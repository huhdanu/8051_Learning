#include <regx52.h>
#include "..\Lib\delay.h"

#define OUT_PORT P0

//ma 7 doan
unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};


void main()
{
	while(1)
	{
		unsigned char i;
		for(i=0;i<10;i++)
		{
			OUT_PORT = Code7Seg[i];
			delay_ms(1000);
		}
	}
}