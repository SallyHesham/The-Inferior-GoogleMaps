#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "head.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


//GPS Code

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

lat = Lat;
lon = Lon;

//sprintf(longitudeIs,"%f",Lon);


/*printf("lat = %s\n",latitudeIs);
printf("log= %s\n\n\n",longitudeIs);
}
else{

printf("\Error\n");*/
}
}}}}}}}
}

