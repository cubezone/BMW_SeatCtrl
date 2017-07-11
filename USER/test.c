//#include <stm32f10x_lib.h>
#include <stm32f10x_map.h>
#include <stm32f10x_nvic.h>      

#include "sys.h"
#include "delay.h"	   
#include "pwm.h"

int i;
int m = 0;

int main(void)
{
	
	Stm32_Clock_Init(9);//系统时钟设置
	delay_init(72);		//延时初始化
	
	RCC->APB2ENR |= 0x00000001; //afio
  AFIO->MAPR   = (0x00FFFFFF & AFIO->MAPR)|0x02000000;  //disable JTAG  release PB3,PB4 to GPIO
	RCC->APB2ENR |= 0X0000001c;//IO PORT A,B,C
	
	GPIOB->CRL = 0X33333338;    //输出
	GPIOB->CRH = 0X33333333;    //输出 

	GPIOB->ODR = 1<<0 ;
	
	// led
	for (i = 0 ; i < 3; i ++)
	{
		PBout(8) = 0;delay_ms(200);
		PBout(8) = 1;delay_ms(200);	
	}
	
	// pwm
	{				
		pwm(2,2,100);
		delay_ms(50);
		pwm(2,2,100);
		delay_ms(50);
		pwm(2,2,100);
		delay_ms(50);
		pwm(1,1,200);
		delay_ms(50);		
	}
	while(1)
	infar_test();
	
}

int pwmtest()
{
		
	while(1)
		for( m = 1 ; m < 50; m ++)
			pwm(m,50-m,200);
		
	while(1)
		for( m = 1 ; m < 5; m ++)
			pwm(m,m,200);
		
	while (1)
	{				
		pwm(2,2,100);
		delay_ms(50);
		pwm(2,2,100);
		delay_ms(50);
		pwm(2,2,100);
		delay_ms(50);
		pwm(1,1,200);
		delay_ms(50);		
	}
}	