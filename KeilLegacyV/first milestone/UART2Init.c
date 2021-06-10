#include "tm4c123gh6pm.h"
#include "head.h"

void UART2Init(){
  SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R2;
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;

  UART2_CTL_R &= ~UART_CTL_UARTEN;
  //SET BRD
  //BR = 9600 bits/s
  //16*10^6/(16*9600) = 104.16667
  UART2_IBRD_R = 104;
  UART2_FBRD_R = 11;
  //UART2_CC_R = UART_CC_CS_SYSCLK;
  UART2_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
  UART2_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE);

  GPIO_PORTD_AFSEL_R |= 0xC0;
  GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & ~0xFF) | (GPIO_PCTL_PD6_U2RX | GPIO_PCTL_PD7_U2TX);
  GPIO_PORTD_DEN_R |= 0xC0;
}
