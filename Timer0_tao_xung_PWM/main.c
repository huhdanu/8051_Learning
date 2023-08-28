#include "main.h"
#include "..\Lib\delay.h"

// khai bao PIN
#define PWM_PIN P1_0
//hoac la sbit PWM_PIN = P2^0;

unsigned int T, Ton, Toff;
unsigned char Ton_hr, Ton_lr, Toff_hr, Toff_lr;

void PWM_Init(unsigned int ck)	// ck (us)
{
	PWM_PIN = 1;
	
	TMOD = (TMOD&0xF0)|0x01;		//xoa cac bit cua timer0 va cho timer0 hoat dong mode 1
	
	ET0 = 1;										// use interrupt
	EA = 1;											// cho phep ngat toan cuc
	
	T = ck/1.085069;
	Ton = T/2;									//Duty cycle = 50%
	Toff = T - Ton;
	
	Ton_hr = (65536-Ton)>>8;
	Ton_lr = (65536-Ton)&0x00FF;
	
	Toff_hr = (65536-Toff)>>8;
	Toff_lr = (65536-Toff)&0x00FF;
	
	TH0 = Ton_hr;
	TL0 = Ton_lr;
}


void PWM_Start()
{
	TR0 = 1; 										//Timer0 bat dau hoat dong
	ET0 = 1;
}

void PWM_Stop()
{
	TR0 = 0;										//Timer0 ngung dem
}

//setup duty cycle 0 - 100;
void PWM_Set_Duty(unsigned char duty)
{
	if(!duty)
	{
		PWM_PIN = 0;
		ET0 = 0 ;									//Khong cho phep ngat hoat dong
	}
	else if(duty == 100)
	{
		PWM_PIN = 1;
		ET0 = 0;									//Khong cho phep ngat hoat dong
	}
	Ton = ((unsigned long)T)*duty/100;
	Toff = T - Ton;
	
	Ton_hr = (65536-Ton)>>8;
	Ton_lr = (65536-Ton)&0x00FF;
	
	Toff_hr = (65536-Toff)>>8;
	Toff_lr = (65536-Toff)&0x00FF;
}

void main()
{
	unsigned char dir = 0, duty = 0;
	P0 = 0 ;
	
	PWM_Init(1000);							//T = 1000us = 1ms
	PWM_Set_Duty(0);
	PWM_Start();
	
	while(1)
	{
		delay_ms(50);
		PWM_Start();
		
		if(dir == 0)							//setup sang dan
		{
			duty += 5;
			if(duty == 100) 
			{	
				dir = 1;
			}				
		}
		else              				//setup tat dan
		{
			duty -= 5;
			if(duty == 0) 
			{
				dir = 0;
			}
		}
		PWM_Set_Duty(duty);
	}
}

void Timer0_Overflow(void) interrupt 1
{
	PWM_PIN = !PWM_PIN;
	if(PWM_PIN==0)
	{
		TR0 = 0;									//Timer0 ngung hoat dong
		//nap lai gia tri khoi tao
		TH0 = Toff_hr;						
		TL0 = Toff_lr;
		TR0 = 1;									//Timer0 cho phep hoat dong
	}
	else
	{
		TR0 = 0;									//Timer0 ngung hoat dong
		//nap lai gia tri khoi tao
		TH0 = Ton_hr;
		TL0 = Ton_lr;
		TR0 = 1;									//Timer0 cho phep hoat dong
	}
}