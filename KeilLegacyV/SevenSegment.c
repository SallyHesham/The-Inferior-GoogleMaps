#include "tm4c123gh6pm.h"
#include "head.h"


//Create definitions for Port B registers
#define GPIO_PORTB_DATA_R       (*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTB_DIR_R        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_PUR_R        (*((volatile unsigned long *)0x40005510))
#define GPIO_PORTB_DEN_R        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_CR_R         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_R      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_R       (*((volatile unsigned long *)0x4000552C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

//Create definitions for Port E registers
#define GPIO_PORTE_DATA_R       (*((volatile unsigned long *)0x400243FC))
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_PUR_R        (*((volatile unsigned long *)0x40024510))
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_CR_R         (*((volatile unsigned long *)0x40024524))
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))

//Create definitions for Port F registers
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))

//Global variables
int numbers[10] = {0x00,0x02,0x10,0x12,0x19,   // Each value turns on bits needed
0x24,0x30,0x40,0x078,0x79};  // to show numbers in display

int chars [10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

char digit1, digit2, digit3;                 // Number to be displayed in each digit

unsigned long calc=0;          // Calculated value initialization


// Creates 0.1ms delay
void Delay2(void){
unsigned long volatile time;
time = 727240*200/91000;  // 0.1 ms
  while(time){
time--;
  } 
}


// Splits number in function into 3 separate numbers for each digit
void NumSplit(int calculated){
//int calculated = 345;
int hundreds = calculated/100; //3
int tens = (calculated%100)*10; //4
int units = calculated - (hundreds*100) - (tens*10); //5
	digit1 = chars[hundreds];
	digit2 = chars[tens];
	digit3 = chars[units];

}
