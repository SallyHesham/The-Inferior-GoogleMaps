#include "tm4c123gh6pm.h"
#include "head.h"

void ledRed(){
	GPIO_PORTF_DATA_R &= 0xF3; 
	GPIO_PORTF_DATA_R |= 0x02; 
}

void ledBlue(){
	GPIO_PORTF_DATA_R &= ~0x0E; 
	GPIO_PORTF_DATA_R |= 0x04; 
}

void ledGreen(){
	GPIO_PORTF_DATA_R &= ~0x0E; 
	GPIO_PORTF_DATA_R |= 0x08; 
}
