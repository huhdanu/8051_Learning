#include "main.h"

void main()
{
	T2CON = 0x00;
	T2MOD = 0x02;
	
	//F_out=FREQ_OSC/(4*(65536-RCAP))
	//tao xung f_out = 5kHz -> RCAP = 64983 (0xFDD7) 
	// hoac co the tao xung voi chu ky 1/f roi ~previous_state nhu PWM
	RCAP2H = 0xFD;	
	RCAP2L = 0xD7;
	
	TR2 = 1;
	
	while(1)
	{
				
	}
}