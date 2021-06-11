#include "tm4c123gh6pm.h"
#include "head.h"
#include "stdlib.h"

int first_point = 0;
double total_distance = 0;
double dist[2][2];
double lat = 0;
double lon = 0;

void Delayyy(void){
	unsigned long volatile time;
	time = (727240*200/91000)*100;  // 0.1 ms *100
  while(time){
			time--;
  } 
}

int main(){
	//CPACR = CPACR | (0xF << 20);
	initPortF();
	initPortAB();
	UART2Init();
	//gpsSetup();
	//PortE_Init();
	
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
	
	ledRed();
	
	
	while(1){

		//readGPSModule();
		
		int distloc = (int)(distanceNew(lat,lon)+(double)0.5);

		ledBlue();
		
		NumSplit(distloc);		 	// Split value in counter into 4 numbers
		LCD_command(0x01);          //clear the screen 
		LCD_command(0x80);          //force cursor to beginning of 1st line
		delay_ms(500);
		LCD_DATA(digit1);
		delay_us(1);
		LCD_DATA(digit2);
		delay_us(1);
		LCD_DATA(digit3);
		delay_ms(500);
		
		if (distloc > 100){ledGreen();}	
		
		if((UART2_FR_R & 0x40) != 0) {ledRed(); while(1);}
	}
	
	/*
	while(1){
		int data = GPIO_PORTF_DATA_R & 0x11;
		switch (data){
			case (0x11) :GPIO_PORTF_DATA_R &= 0xF1; break;
			case (0x01) :GPIO_PORTF_DATA_R &= 0xF5; GPIO_PORTF_DATA_R |= 0x04; break;
			case (0x10) :GPIO_PORTF_DATA_R &= 0xF9; GPIO_PORTF_DATA_R |= 0x08; break;
			case (0x00) :GPIO_PORTF_DATA_R &= 0xF3; GPIO_PORTF_DATA_R |= 0x02; break;
			}
		}
	*/
}
