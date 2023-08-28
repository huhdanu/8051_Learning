#include <regx52.h>
#include "..\Lib\delay.h"

#define LED_COL P2
#define LED_ROW P0

unsigned char code count0_9[] = {0xFF,0xff,0x00,0x7E,0x7E,0x00,0xff,0xFF};

void main()
{
	unsigned char a,i,j,dich;
	
	while(1)
	{
		for(a=0;a<8;a++)				// dich led
		{
			dich = 0x80>>a;	
			for(i=0;i<20;i++)		// su dung de delay 200ms
			{
				for(j=0;j<8;j++)		//	quet cot led matrix
				{
					LED_COL = count0_9[7-j];
					LED_ROW = dich;
					delay_ms(1);
					dich = dich >> 1;
					LED_ROW = 0x00;
				}
			}
		}
		
//		for(a=0;a<15;a++)				// dich led
//		{
//			if(a<8)
//			{
//				dich = 0x80>>a;	
//				for(i=0;i<20;i++)		// su dung de delay 200ms
//				{
//					for(j=0;j<8;j++)		//	quet cot led matrix
//					{
//						LED_COL = count0_9[7-j];
//						LED_ROW = dich;
//						delay_ms(1);
//						dich = dich >> 1;
//						LED_ROW = 0x00;
//					}
//				}
//			}
//			else 
//			{
//				dich = 0x80>>(a-7);	
//				for(i=0;i<20;i++)		// su dung de delay 200ms
//				{
//					for(j=0;j<8;j++)		//	quet cot led matrix
//					{
//						LED_COL = count0_9[j];
//						LED_ROW = dich;
//						delay_ms(1);
//						dich = dich >> 1;
//						LED_ROW = 0x00;
//					}
//				}	
//			}
//		}
	}
}