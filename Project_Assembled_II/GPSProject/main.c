#include "tm4c123gh6pm.h"
#include "head.h"
#include "stdlib.h"


float PX = 0;
float PY = 0;
int firstPoint = 0;
float totalDist = 0;
float dist = 0;

void Delayyy(void){
	unsigned long volatile time;
	time = (727240*200/91000)*100;  // 0.1 ms
  while(time){
			time--;
  } 
}

int main(){
	//CPACR = CPACR | (0xF << 20);
	initPortF();
	initPortAB();
	PortE_Init();
	
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
	
	
	//float x = 0;
	//float y = 0;
	//srand(1);
	for(int i=0;i<100;i++){
		//x += rand()/(RAND_MAX);
		//y += rand()/(RAND_MAX);
		Delayyy();
		int distloc = (int)(distanceMarkII((float)(0.5+i),(float)(0.4+i))+ (float)0.5);
			//float x = i/10+0.1;
			//float y = i/10+0.2;
			//totDist += (int)(distance(x,y)+0.5);
			//GPIO_PORTB_DATA_R = totDist;

		//int distloc =0;
		ledBlue();
		
		LCD_command(0x01);          //clear the screen 
		LCD_command(0x80);          //force cursor to beginning of 1st line
		delay_ms(500);
		LCD_DATA('A');
		delay_us(1);
		LCD_DATA('B');
	  delay_ms(500);
		
		/*NumSplit(distloc);		 	// Split value in counter into 4 numbers
		Display(1,digit1);								// Display number for lowest digit
	  Display(2,digit2);			
	  Display(4,digit3);*/
		if (distloc > 100){ledGreen();}	
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
