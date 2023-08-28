#include "main.h"
#include "display_on_7segment.h"
#include "..\Lib\delay.h"

unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};


void Display_7segment(unsigned int b)
{
	unsigned tr_ng,ch_ng,tr,ch,dvi;
	tr_ng = b/10000;
	ch_ng = b/1000%10;
	tr = b/100%10;
	ch = b%100/10;
	dvi = b%10;
	
	//use PORT0 to display on 7segment and use PORT3 to control on_off 7segment
	P0 = Code7Seg[dvi];
	P2_0 = 1;
	delay_ms(1);
	P2_0 = 0;
	
	P0 = Code7Seg[ch];
	P2_1 = 1;
	delay_ms(1);
	P2_1 = 0;
	
	P0 = Code7Seg[tr];
	P2_2 = 1;
	delay_ms(1);
	P2_2 = 0;
	
	P0 = Code7Seg[ch_ng];
	P2_3 = 1;
	delay_ms(1);
	P2_3 = 0;
	
	P0 = Code7Seg[tr_ng];
	P2_4 = 1;
	delay_ms(1);
	P2_4 = 0;

}

void main()
{
	unsigned char low, high;
	unsigned int number;
	
	TMOD = (TMOD&0xF0)|0x05;			//xxxx 0101 su dung Counter va dinh thoi Timer0
	TR0 = 1; 											//Timer0 bat dau dem
	while(1)
	{
			do{
				high = TH0;
				low = TL0;
			}while(high != TH0);
			
			number = (high<<8)|low;
			Display_7segment(number);
	}
}