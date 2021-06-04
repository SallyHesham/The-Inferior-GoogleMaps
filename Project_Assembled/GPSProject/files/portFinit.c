#include "tm4c123gh6pm.h"
#include "C:\Users\sally\OneDrive\Desktop\Coding\GitHub\The-Inferior-GoogleMaps\Project_Assembled\GPSProject\head.h"

void initPortF() {   
	SYSCTL_RCGCGPIO_R |= 0x20;   
	while((SYSCTL_PRGPIO_R&0x20) == 0);   
	GPIO_PORTF_LOCK_R = 0x4C4F434B;   
	GPIO_PORTF_CR_R = 0x1F;   
	GPIO_PORTF_AMSEL_R = 0x00;   
	GPIO_PORTF_PCTL_R = 0x00000000;   
	GPIO_PORTF_DIR_R = 0x0E;   
	GPIO_PORTF_AFSEL_R = 0x00;   
	GPIO_PORTF_DEN_R = 0x1F;   
	GPIO_PORTF_PUR_R = 0x11; 
}
