#include "stdint.h"
#include "math.h"
#include "tm4c123gh6pm.h"
#include "head.h"

#define PI 3.14159265
#define R 6371000

	
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
	GPIO_PORTA_DATA_R |=0x40;   // E=1 (low to high) without affecting other pins
  delay_ms(1);	
	GPIO_PORTB_DATA_R=com;      // send command to the screen
	delay_us(1);
	GPIO_PORTA_DATA_R=0;        // E=0 agian
  delay_us(1);
	
}	
	
void LCD_DATA(unsigned char data)
{ 	
  GPIO_PORTA_DATA_R=0x80;        //Rs=1 send data, Rw=0 write,E=0 initially enable=0  
	delay_ms(1);
	GPIO_PORTA_DATA_R |=0x40;      // E=1 (low to high) without affecting other pins 
	delay_ms(1);
	GPIO_PORTB_DATA_R=data;        // send data to the screen
	delay_us(1);
	GPIO_PORTA_DATA_R=0;           //Rs=0 Rw=0 E=0(back to the beginning)
  delay_us(50);
}
	

/*
// To convert from degrees to radian
 double deg_to_rad(double deg){
    return (deg * PI / 180); 
}

// Measuring the distance by longitude and latitude
 double Total_Distance(double long1, double long2, double lat1, double lat2)
 {
    double dlong = deg_to_rad(long2 - long1);
    double dlat  = deg_to_rad(lat2 - lat1);
    double phi1 = deg_to_rad(lat1);
    double phi2 = deg_to_rad(lat2);
// Haversine formula
    double a = pow(sin((0.5 * dlat)), 2) + cos(phi1) * cos(phi2) * pow(sin((0.5 * dlong)), 2);
    double d = 2 * R * asin(sqrt(a));
    Dis = Dis + d;
		return Dis;
		}
		
void init()
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
	
	
	
	
	SYSCTL_RCGCUART_R |=0x0008;    // ACTIVATE UART3
	SYSCTL_RCGCGPIO_R |=0x0004;    // enable the clock of port C6,7
	UART3_CTL_R =0;
	UART3_IBRD_R =104;
	UART3_FBRD_R =11;
	UART3_LCRH_R =0x0070;
	UART3_CTL_R =0X0301;

	GPIO_PORTC_DEN_R |=0x00C0;      // D	C6,7
	GPIO_PORTC_AMSEL_R &=~0x00C0;	    //  D
	GPIO_PORTC_AFSEL_R |=0x00C0;
  GPIO_PORTC_PCTL_R =(GPIO_PORTC_PCTL_R&0x00FFFFFF)+0x11000000;       // working I/O ports OR UART
	
	
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


	SYSCTL_RCGCGPIO_R |=0x20;    // enable the clock of port
	delay=1;
	GPIO_PORTF_LOCK_R=0x4C4F434B;
	GPIO_PORTF_CR_R=0x1F;        // enable pins 
  GPIO_PORTF_DIR_R=0x0E;      // pin I/O  0/1
	GPIO_PORTF_DEN_R=0x1F;      // D	
	GPIO_PORTF_AMSEL_R =0;	    // A
	GPIO_PORTF_AFSEL_R =0;
  GPIO_PORTF_PCTL_R =0;       // working I/O ports OR UART
	GPIO_PORTF_PUR_R=0x11;      // for switches
}	

int main()
{
	
	init();
	
	
  Distance = Total_Distance(30.075622, 30.066031 ,31.361465, 31.262106);  // more than 100 led on

	
	//LED
	if (Distance>=100)
				{
					GPIO_PORTF_DATA_R=0x02;
				}
				else
				{
					GPIO_PORTF_DATA_R=0;
				}
				
	
	//LCD

	  LCD_command(0x01);          //clear the screen 
		LCD_command(0x80);          //force cursor to beginning of 1st line
		delay_ms(500);
		LCD_DATA('A');
		delay_us(1);
		LCD_DATA('B');
	  delay_ms(500);

	
	//UART		
//	 char x;
//	 while(1)
//	 {
//		while((UART3_FR_R&0x10) !=0){} 
//		x=UART3_DR_R ;	
//	 }	
			 
		while(1)
	  {}
		
	}
	
	*/
	
