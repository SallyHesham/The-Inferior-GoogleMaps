/*#include "stdint.h"
#include "math.h"
#include "tm4c123gh6pm.h"
#include "head.h"
	
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
	

void LCD_command(unsigned char com)
{
	
	GPIO_PORTA_DATA_R=0;        //Rs=0 send command, Rw=0 write, E=0 initially enable=0 
	delay_ms(1);
	GPIO_PORTA_DATA_R |=0x20;   // E=1 (low to high) without affecting other pins
  delay_ms(1);	
	GPIO_PORTB_DATA_R=com;      // send command to the screen
	delay_us(1);
	GPIO_PORTA_DATA_R=0;        // E=0 agian
  delay_us(1);
	
}	
	
void LCD_DATA(unsigned char data)
{ 	
  GPIO_PORTA_DATA_R=0x40;        //Rs=1 send data, Rw=0 write,E=0 initially enable=0  
	delay_ms(1);
	GPIO_PORTA_DATA_R |=0x20;      // E=1 (low to high) without affecting other pins 
	delay_ms(1);
	GPIO_PORTB_DATA_R=data;        // send data to the screen
	delay_us(1);
	GPIO_PORTA_DATA_R=0;           //Rs=0 Rw=0 E=0(back to the beginning)
  delay_us(50);
}
	


-
void initA()
{
	uint32_t delay;
	
		SYSCTL_RCGCGPIO_R |=0x03;    //clock register for ports A B
	  delay=1;
	
	GPIO_PORTA_LOCK_R=0x4C4F434B;   //lock for ports A B 
	GPIO_PORTA_CR_R=0xE0;
	//GPIO_PORTB_LOCK_R=0x4C4F434B;
	GPIO_PORTB_CR_R=0xFF;
	

	GPIO_PORTA_AFSEL_R=0;       //initializing portA  5 6 7
	GPIO_PORTA_PCTL_R=0;
	GPIO_PORTA_AMSEL_R=0;
	GPIO_PORTA_DIR_R|=0xE0;
	GPIO_PORTA_DEN_R|=0xE0;
	GPIO_PORTA_PUR_R=0;
	GPIO_PORTB_AFSEL_R=0;       //initializing portB pins 0-8 for LCD
	GPIO_PORTB_PCTL_R=0;
	GPIO_PORTB_AMSEL_R=0;
	GPIO_PORTB_DIR_R=0xFF;
	GPIO_PORTB_DEN_R=0xFF;
	GPIO_PORTB_PUR_R=0;	
	
	
	
	
	
	
  delay_ms(20);
	LCD_command(0x38);          
	delay_us(50);
	LCD_command(0x0F); 
  delay_ms(50);	
	LCD_command(0x06); 
	delay_ms(50);
  LCD_command(0x01);  
  delay_ms(5);
  delay_ms(20);	

}	

*/
