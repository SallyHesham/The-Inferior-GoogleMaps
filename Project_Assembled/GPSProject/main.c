#include "tm4c123gh6pm.h"
#include "head.h"
#include "stdlib.h"

int main(){
	initPortF();
	initPortAB();
//portE needed for 7seg here
	ledRed();
	
	int totDist = 0;
	for(int i=0;i<10;i++){
			//srand(1);
			//float x = rand()/(RAND_MAX)+1;
			//float y = rand()/(RAND_MAX)+1;
			float x = i/10+0.1;
			float y = i/10+0.2;
			//totDist += (int)(distance(x,y)+0.5);
			//GPIO_PORTB_DATA_R = totDist;
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
