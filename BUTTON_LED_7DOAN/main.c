#include <regx52.h>
#include "..\Lib\delay.h"
#define	OUT_PORT P0

sbit BTN = P2^0;	//define for BUTTON
sbit LED = P2^1;	//define for LED

unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

//CT thuc thi sau khi nha BUTTON
//void main()
//{
//	BTN = 0;
//	OUT_PORT = Code7Seg[0];		//hien thi trang thai dau la so '0'
//	LED = 0;
//	while(1)
//	{
//		unsigned int dem;
//		if (BTN == 1)
//		{
//			delay_ms(20);
//			if (BTN == 1)
//			{
//				while(BTN) LED = 1;
//				LED = 0;
//				dem++;
//				if(dem == 10) dem = 0;
//				OUT_PORT = Code7Seg[dem];
//			}
//		}
//	}
//}

//CT thuc thi khi nhan BUTTON

void main()
{
	BTN = 0;
	OUT_PORT = Code7Seg[0];		//hien thi trang thai dau la so '0'
	LED = 0;
	while(1)
	{
		unsigned int dem;
		if (BTN == 1)
		{
			delay_ms(20);
			if (BTN == 1)
			{
				LED = 1;
				dem++;
				if(dem == 10) dem = 0;
				OUT_PORT = Code7Seg[dem];
				while (BTN);
			}
		}
		else LED = 0;
	}
}