#include <REGX52.H>

sbit LED_PIN = P0^0;

void delay_ms(unsigned char t)	//delay voi thoi gian t
{
	unsigned int i,j;
	for(i=0;i<t;i++)
	{	
			for(j=0;j<120;j++);
	}
}

void main()
{
	//LED_PIN = 0;
	while(1)
	{
		LED_PIN = !LED_PIN;
		delay_ms(500);
	}

}