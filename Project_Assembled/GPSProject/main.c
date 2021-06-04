#include "tm4c123gh6pm.h"
#include "head.h"
#include "stdlib.h"

int main(){
	initPortF();
	initPortAB();
	PortE_Init();
	ledRed();
	
	float x = 0;
	float y = 0;
	//srand(1);
	for(int i=0;i<10;i++){
		x += rand()/(RAND_MAX);
		y += rand()/(RAND_MAX);
		//int dist = (int)(distanceMarkII(x,y)+0.5);
			//float x = i/10+0.1;
			//float y = i/10+0.2;
			//totDist += (int)(distance(x,y)+0.5);
			//GPIO_PORTB_DATA_R = totDist;

		int dist =0;
		NumSplit(dist);		 	// Split value in counter into 4 numbers
		Display(1,digit1);								// Display number for lowest digit
	  Display(2,digit2);			
	  Display(4,digit3);
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
