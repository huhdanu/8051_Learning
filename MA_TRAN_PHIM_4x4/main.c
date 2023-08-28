#include <regx52.h>
#include "..\Lib\delay.h"

#define LED_COT P2
#define LED_ROW P0

//khai bao ket noi ma tran phim use P1
sbit COL_1 = P1^0;
sbit COL_2 = P1^1;
sbit COL_3 = P1^2;
sbit COL_4 = P1^3;

sbit ROW_1 = P1^4;
sbit ROW_2 = P1^5;
sbit ROW_3 = P1^6;
sbit ROW_4 = P1^7;

// ma hex cho LED ma tran
unsigned char code Code_matrix[10][8] = {{0xFF,0xff,0x00,0x7E,0x7E,0x00,0xff,0xFF},
																				 {0xFF,0xFF,0xDE,0xBE,0x00,0xFE,0xFE,0xFF},   
																				 {0xFF,0xB1,0x76,0x76,0x76,0x8E,0xFF,0xFF},
																			   {0xFF,0xFF,0x6E,0x6E,0x6E,0x6E,0x81,0xFF},  
																			   {0xFF,0xF3,0xEB,0xDB,0xBB,0x00,0xFB,0xFF},
																				 {0xFF,0xFF,0x0E,0x6E,0x6E,0x71,0xFF,0xFF},
																				 {0xFF,0xFF,0x00,0x6E,0x6E,0x60,0xFF,0xFF},  
																				 {0xFF,0xFF,0x1F,0x7F,0x7F,0x00,0xFF,0xFF},
																				 {0xFF,0xFF,0x00,0x66,0x66,0x00,0xFF,0xFF},
																				 {0xFF,0xFF,0x0E,0x6E,0x6E,0x00,0xFF,0xFF}};
																				 
unsigned char code Code_matrix_AD[6][8] = {{0xFF,0xC0,0xB7,0x77,0x77,0xB7,0xC0,0xFF},
																				 {0xFF,0x00,0x66,0x66,0x66,0x99,0xFF,0xFF},
																				 {0xFF,0xC3,0xBD,0x7E,0x7E,0x7E,0xBD,0xFF},
																				 {0xFF,0x00,0x7E,0x7E,0x7E,0xBD,0xC3,0xFF},
																				 {0xFF,0x7D,0xBB,0xC7,0x01,0xC7,0xBB,0x7D},
																				 {0xEB,0xEB,0x80,0xEB,0x80,0xEB,0xEB,0xFF}};
																				 
unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
//-----------------------------------------------------------------------------------------																			
//CT con cho phim nhan
unsigned char press_key()
{
	unsigned char key = 0xff;	
	//cho Cot 1 = 0;
	COL_1 = 0;
	//Kiem tra cac hang lan luot
	if(ROW_1 == 0) key = 13;
	if(ROW_2 == 0) key = 12;
	if(ROW_3 == 0) key = 11;
	if(ROW_4 == 0) key = 10;
	COL_1 = 1;
	
	//cho Cot 2 = 0
	COL_2 = 0;
	//Kiem tra cac hang lan luot
	if(ROW_1 == 0) key = 15;
	if(ROW_2 == 0) key = 9;
	if(ROW_3 == 0) key = 6;
	if(ROW_4 == 0) key = 3;
	COL_2 = 1;
	
	//cho cot 3 = 0
	COL_3 = 0;
	//Kiem tra cac hang lan luot
	if(ROW_1 == 0) key = 0;
	if(ROW_2 == 0) key = 8;
	if(ROW_3 == 0) key = 5;
	if(ROW_4 == 0) key = 2;
	COL_3 = 1;
	
	COL_4 = 0;
	//Kiem tra cac hang lan luot
	if(ROW_1 == 0) key = 14;
	if(ROW_2 == 0) key = 7;
	if(ROW_3 == 0) key = 4;
	if(ROW_4 == 0) key = 1;
	COL_4 = 1;
	
	return key;
}
//-------------------------------------------------------------------------------------

void main()
{
	unsigned char key,tmp,j,i;
	tmp = 0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++);
		LED_COT = 0x01<<i;
		LED_ROW = 0x80>>j;
		delay_ms(200);
		LED_ROW = 0;
	}
	
	while(1)
	{
		key = press_key();
		if(key!=0xff)		//neu co nhan
		{
				tmp = key;
		}
		//P0 = Code7Seg[tmp];
		if(tmp >= 10 )
		{
			for(j=0;j<8;j++)
			{
				LED_COT = Code_matrix_AD[tmp-10][j];
				LED_ROW = 0x80>>j;
				delay_ms(1);
				LED_ROW = 0;
			}
		}
		else 
		{
			for(j=0;j<8;j++)
			{
				LED_COT = Code_matrix[tmp][j];
				LED_ROW = 0x80>>j;
				delay_ms(1);
				LED_ROW = 0;
			}
		}
	}
}