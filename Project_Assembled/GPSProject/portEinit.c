#include "tm4c123gh6pm.h"
#include "head.h"

void PortE_Init(void){ 
  SYSCTL_RCGCGPIO_R |= 0x00000010;     // Port E clock initialized
	while((SYSCTL_PRGPIO_R&0x10) == 0)
		; 
  GPIO_PORTE_CR_R = 0x0F;           // Allow changes to PE4-0       
  GPIO_PORTE_AMSEL_R = 0x00;        // Disable analog function
  GPIO_PORTE_PCTL_R = 0x00000000;   // GPIO clear bit PCTL  
  GPIO_PORTE_DIR_R = 0x0F;          // PE3-PE0 output   
  GPIO_PORTE_PUR_R = 0x00;          // Disable pullup resistors       
  GPIO_PORTE_DEN_R = 0x0F;          // Enable digital pins PE3-PE0
}
