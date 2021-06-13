#include "stdint.h"
#include "math.h"
#include "tm4c123gh6pm.h"


void SystemInit(){}
	
	
	// Mili seconds delay function 
void delay_ms(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3180;j++)
 {}
}

  // Micro seconds delay function
void delay_us(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3;j++)
 {}
 }
	

void LCD_command(unsigned char command)
{
	
	GPIO_PORTA_DATA_R=0;        
	delay_ms(1);
	GPIO_PORTA_DATA_R |=0x40;   
  delay_ms(1);	
	GPIO_PORTB_DATA_R=command;      
	delay_us(1);
	GPIO_PORTA_DATA_R=0;        
  delay_us(1);
	
}	
	
void LCD_DATA(unsigned char data)
{ 	
  GPIO_PORTA_DATA_R=0x80;         
	delay_ms(1);
	GPIO_PORTA_DATA_R |=0x40;      
	delay_ms(1);
	GPIO_PORTB_DATA_R=data;        
	delay_us(1);
	GPIO_PORTA_DATA_R=0;           
  delay_us(50);
}
