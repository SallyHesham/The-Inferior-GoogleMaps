#include "stdint.h"
#include "math.h"
#include "tm4c123gh6pm.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int first_point = 0;
double total_distance = 0;
double dist[2][2];
double latglo = 0;
double longlo = 0;

void SystemInit(){}
	
	
	// Mili seconds delay function 
void delay_ms(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3180;j++)
 {}
}

  // Micro seconds delay function
void delay_us(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3;j++)
 {}
 }
	

void LCD_command(unsigned char command)
{
	
	GPIO_PORTA_DATA_R=0;        
	delay_ms(1);
	GPIO_PORTA_DATA_R |=0x40;   
  delay_ms(1);	
	GPIO_PORTB_DATA_R=command;      
	delay_us(1);
	GPIO_PORTA_DATA_R=0;        
  delay_us(1);
	
}	
	
void LCD_DATA(unsigned char data)
{ 	
  GPIO_PORTA_DATA_R=0x80;         
	delay_ms(1);
	GPIO_PORTA_DATA_R |=0x40;      
	delay_ms(1);
	GPIO_PORTB_DATA_R=data;        
	delay_us(1);
	GPIO_PORTA_DATA_R=0;           
  delay_us(50);
}
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
void initPortAB() {
  SYSCTL_RCGCGPIO_R |= 0x02;
  while((SYSCTL_PRGPIO_R&0x02) == 0);
	GPIO_PORTB_LOCK_R = 0x4C4F434B;
	GPIO_PORTB_CR_R = 0xFF;
	GPIO_PORTB_AMSEL_R = 0x00;
  GPIO_PORTB_PCTL_R = 0x00000000;
	GPIO_PORTB_DIR_R = 0xFF;
	GPIO_PORTB_AFSEL_R = 0x00;
	GPIO_PORTB_DEN_R = 0xFF;
	GPIO_PORTB_PUR_R = 0x00;

	SYSCTL_RCGCGPIO_R |= 0x01;
  while((SYSCTL_PRGPIO_R&0x01) == 0);
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	GPIO_PORTA_CR_R |= 0xE0;
	GPIO_PORTA_AMSEL_R = 0x00;
  GPIO_PORTA_PCTL_R = 0x00000000;
	GPIO_PORTA_DIR_R |= 0xE0;
	GPIO_PORTA_AFSEL_R = 0x00;
	GPIO_PORTA_DEN_R |= 0xE0;
	GPIO_PORTA_PUR_R = 0x00;
}
void ledRed(){
	GPIO_PORTF_DATA_R &= 0xF3; 
	GPIO_PORTF_DATA_R |= 0x02; 
}

void ledBlue(){
	GPIO_PORTF_DATA_R &= 0xF1; 
	GPIO_PORTF_DATA_R |= 0x04; 
}

void ledGreen(){
	GPIO_PORTF_DATA_R &= 0xF1; 
	GPIO_PORTF_DATA_R |= 0x08; 
}
int R = 6371 * 1000; //Radius of Earth in meter
double PI = 3.141592653589793;

double distanceNew(double lat, double lon)
{

	double lat_rad = lat * PI / 180;
	double lon_rad = lon * PI / 180;
	dist[1][0] = lat_rad;
	dist[1][1] = lon_rad;

	if (first_point == 0)
	{
		first_point = 1;
		dist[0][0] = dist[1][0];
		dist[0][1] = dist[1][1];

	}
	else
	{
		double difference_lat = (dist[1][0] - dist[0][0]);
		double difference_lon = (dist[1][1] - dist[0][1]);
		double lat1 = dist[0][0];
		//double lon1 = dist[0][1];
		double lat2 = dist[1][0];
		//double lon2 = dist[1][1];
		double a = sin(difference_lat / 2) * sin(difference_lat / 2) + cos(lat1) * cos(lat2) *
			sin(difference_lon / 2) * sin(difference_lon / 2);
		double c = 2 * asin(sqrt(a));
		double the_distance = R * c;

		total_distance += the_distance;
		dist[0][0] = dist[1][0];
		dist[0][1] = dist[1][1];
	}



	return total_distance;

}
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
int chars [10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char digit1, digit2, digit3;

void NumSplit(int calculated){
int hundreds = calculated/100;
int tens = (calculated%100)/10;
int units = calculated - (hundreds*100) - (tens*10);
	digit1 = chars[hundreds];
	digit2 = chars[tens];
	digit3 = chars[units];
}
void readGPSModule(){
char GPS_values[100],*token,parseValue[12][20];
double latitude=0.0,longitude=0.0,seconds=0.0,minutes=0.0,Lat=0.0,Lon=0.0;
char m0,m1,m2,m3,m4,m5,m6,m7;
const char comma[2] = ",";

int index=0,degrees;
	//is the incoming data is $GPRMC?
while((UART2_FR_R&0x0010) !=0);
m0 = UART2_DR_R&0xFF;
if(m0 =='$'){
while((UART2_FR_R&0x0010) !=0);
m1 = UART2_DR_R &0xFF;
if(m1 == 'G'){
while((UART2_FR_R&0x0010) !=0);
m2 = UART2_DR_R&0xFF;
if(m2 == 'P'){
while((UART2_FR_R&0x0010) !=0);
m3 = UART2_DR_R&0xFF;
if(m3 == 'R'){
while((UART2_FR_R&0x0010) !=0);
m4 = UART2_DR_R&0xFF;
if(m4 == 'M'){
while((UART2_FR_R&0x0010) !=0);
m5 = UART2_DR_R&0xFF;
if(m5 == 'C'){
while((UART2_FR_R&0x0010) !=0);
m6 = UART2_DR_R&0xFF;
if(m6 == ','){
while((UART2_FR_R&0x0010) !=0);
m7 = UART2_DR_R&0xFF;

//assign the data to the GPSValues array. read up to the last data checksum (like checksum: A*60)
while(m7 !='*'){
GPS_values[index] = m7; //20
while((UART2_FR_R&0x0010) !=0);
m7 = UART2_DR_R&0xFF;
index++;
}
 //Separating the data in the GPSValues array by comma
index = 0;
token = strtok(GPS_values,comma);
while( token != NULL ) {
 strcpy(parseValue[index], token);
token = strtok(NULL,comma);
index++;}

//Data valid if parseValue[1] = A - not valid if =V
if(strcmp(parseValue[1],"A")==0){
latitude=atof(parseValue[2]);
longitude=atof(parseValue[4]);
	
//latitude calculation
degrees=latitude/100;
minutes=latitude-(double)(degrees*100);
seconds=minutes/60.00;
Lat=degrees+seconds;
	
//sprintf(latitudeIs,"%f", Lat);
	
//longitude calculation
degrees=longitude/100;
minutes=longitude-(double)(degrees*100);
seconds=minutes/60.00;
Lon=degrees+seconds;

latglo = Lat;
longlo = Lon;

//sprintf(longitudeIs,"%f",Lon);


/*printf("lat = %s\n",latitudeIs);
printf("log= %s\n\n\n",longitudeIs);
}
else{

printf("\Error\n");*/
}
}}}}}}}
}

void Delayyy(void){
	unsigned long volatile time;
	time = (727240*200/91000)*100;  // 0.1 ms *100
  while(time){
			time--;
  } 
}

int main(){
	initPortF();
	initPortAB();
	UART2Init();
	
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

		readGPSModule();
		
		int distloc = (int)(distanceNew(latglo,longlo)+(double)0.5);

		if(distloc<100){ledBlue();}
		
		NumSplit(123);		 	// Split value in counter into 3 numbers
		LCD_command(0x01);          
		LCD_command(0x80);          
		delay_ms(500);
		LCD_DATA(digit1);
		delay_us(1);
		LCD_DATA(digit2);
		delay_us(1);
		LCD_DATA(digit3);
		delay_ms(500);
		
		if (distloc >= 100){ledGreen();}	
		
		
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
