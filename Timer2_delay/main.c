#include "main.h"

void Delay_1s()
{
	unsigned char i;
	TR2 = 1;						//Timer2 bat dau hoat dong
	for (i=0;i<20;i++)	//dem den 50ms thi tran nen dem 20 vong de duoc 1s
	{
		while(!TF2);			//cho set len 1 khi Overflow
		TF2 = 0;
	}
	TR2 = 0;
}
void main()
{
	//set up timer 2 tu dong nap lai, 16 bit
	T2CON = 0x00;
	T2MOD = 0x00;
	
	//dem 1 lan 50ms nen can dem 46080 xung, gia tri khoi tao la 19456 -> 0x4C00
	TH2 = 0x4C;
	TL2 = 0x00;
	
	//ghi gia tri thanh ghi tu dong nap lai khi Overflow
	RCAP2H = 0x4C;
	RCAP2L = 0x00;
	
	while(1)
	{
		P2 = ~P2;
		Delay_1s();
	}
}	