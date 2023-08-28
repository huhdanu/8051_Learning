#include <REGX52.H>
#include "..\Lib\delay.h"

#define LED_PORT P0


void main()
{
	while(1)
	{
		unsigned int i;
		LED_PORT = 0x01;
		for(i=0;i<8;i++)
		{
			delay_ms(300);
			LED_PORT = LED_PORT<<1;
		}
	}



}