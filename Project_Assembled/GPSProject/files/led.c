#include "stdint.h"
#include "tm4c123gh6pm.h"
//function which red led turn on when the distance exceed 100  	 
void led (int Dis)
 {
	 while (1){
    if (Dis >100 ){
		GPIO_PORTF_DATA_R |= 0x02; 
		}	
		else {
		GPIO_PORTF_DATA_R  =0;
		}
	}
}	 
