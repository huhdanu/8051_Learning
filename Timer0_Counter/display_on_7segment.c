#include "main.h"
#include "display_on_7segment.h"
#include "..\Lib\delay.h"



void Display_7segment(unsigned int b)
{
	unsigned tr_ng,ch_ng,tr,ch,dvi;
	tr_ng = b/10000;
	ch_ng = b/1000%10;
	tr = b/100%10;
	ch = b%100/10;
	dvi = b%10;
	
	//use PORT0 to display on 7segment and use PORT3 to control on_off 7segment
	P0_0 = Code7Seg[dvi];
	P3_0 = 1;
	delay_ms(1);
	P3_0 = 0;
	
	P0_1 = Code7Seg[ch];
	P3_1 = 1;
	delay_ms(1);
	P3_1 = 0;
	
	P0_2 = Code7Seg[tr];
	P3_2 = 1;
	delay_ms(1);
	P3_2 = 0;
	
	P0_3 = Code7Seg[ch_ng];
	P3_3 = 1;
	delay_ms(1);
	P3_3 = 0;
	
	P0_4 = Code7Seg[tr_ng];
	P3_4 = 1;
	delay_ms(1);
	P3_4 = 0;

}