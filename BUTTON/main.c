#include <regx52.h>

sbit LED = P2^1;
sbit BTN = P2^0;

void main()
{
	LED = 0;	//tat LED
	BTN = 0;	// su dung nut nhan muc cao
	while(1)
	{
		if (BTN == 1)
		{
			LED = 1;
		}
		else LED = 0; 
	}
}