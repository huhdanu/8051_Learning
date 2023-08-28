#include <regx52.h>
#include "..\Lib\delay.h"

#define LED_PORT P0
sbit LED_7Seg_1 = P2^1;
sbit LED_7Seg_2 = P2^0;

unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void main()
{
//	P2 = 0x00;
	while(1)
	{
		unsigned char chuc, dvi,dem;
		unsigned int i;
		
		for(dem=0;dem<100;dem++)
		{
			dvi = dem%10;
			chuc = dem/10;
			// xoa so '0' hang chuc vo nghia
			if(chuc == 0) chuc = 0xff;		
			for(i=0;i<50;i++)		//lap lai doan CT delay 2ms de duoc 1s
			{
				//hien thi LED 7Seg hang don vi
				LED_PORT = Code7Seg[dvi];
				LED_7Seg_1 = 1;
				delay_ms(1);
				LED_7Seg_1 = 0;
				
				//hien thi LED 7Seg hang chuc
				LED_PORT = Code7Seg[chuc];
				LED_7Seg_2 = 1;
				delay_ms(1);
				LED_7Seg_2 = 0;
			}
		}
	}
}
	