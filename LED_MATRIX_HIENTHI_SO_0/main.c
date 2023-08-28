#include <regx52.h>
#include "..\Lib\delay.h"

// matrix so '0'
unsigned char code matrix_0[] ={0xFF,0x81,0x7E,0x7E,0x7E,0x7E,0x81,0xFF};	

void main()
{
	unsigned char i;
	while(1)
	{		
		for(i=0;i<8;i++)
		{
			P2 = matrix_0[i];
			P0 = 0x80>>i;
			delay_ms(1);
			P0 = 0x00;
		}
	}
}