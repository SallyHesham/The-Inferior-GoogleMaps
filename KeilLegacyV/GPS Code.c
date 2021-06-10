/*
 *GPS Code
 */
#include "tm4c123gh6pm.h"
#include "head.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "hw_ints.h"
#include "hw_types.h"
#include "hw_memmap.h"

#include "sysctl.h"
#include "gpio.h"
#include "pin_map.h"
#include "uart.h"

/* tiva pins:
 *TX-->PD6
 * RX-->PD7
 * Vcc--> 3.3V
 */

char* settime(char str[]);
void readGPSModule();



void read(void)
{

	
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

    //GPS Pins
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    //GPIOPinConfigure(GPIO_PD6_U2RX);
    //GPIOPinConfigure(GPIO_PD7_U2TX);
    GPIOPinTypeUART(GPIO_PORTD_BASE,GPIO_PIN_6|GPIO_PIN_7);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2);
    UARTConfigSetExpClk(UART2_BASE,SysCtlClockGet(),9600,(UART_CONFIG_WLEN_8 | UART_CONFIG_PAR_NONE | UART_CONFIG_STOP_ONE));
    UARTEnable(UART2_BASE);



	//$GPRMC,200751.00,A,4047.32510,N,02929.63031,E,9.879,105.80,301117,,,A*6C
	/* before A--Clock
	before N(North)--Latitude
	befofe E--Longitude 
	*/
    while(1){
        readGPSModule();
    }
    //UARTDisable(UART1_BASE);

}

// When there is transmition, the location will be taken. And SMS will be sent.

//Sample:
//$GPRMC,200751.00,A,4047.32510,N,02929.63031,E,9.879,105.80,301117,,,A*6C
void readGPSModule(void){
    char c0,GPSValues[100],latitudeResult[10],longitudeResult[10],parseValue[12][20],*token,date[9],*time,CurrentTime[9];
    double latitude=0.0,longitude=0.0,seconds=0.0,result=0.0,minutes=0.0;
    const char comma[2] = ",";
    int index=0,degrees,i=0,j=0;


    while(!UARTCharsAvail(UART2_BASE));
    c0=UARTCharGetNonBlocking(UART2_BASE);

    //is the incoming data $GPRMC ?
    if(c0=='$'){
        while(!UARTCharsAvail(UART2_BASE));
        char c1=UARTCharGetNonBlocking(UART2_BASE);
        if(c1=='G'){
            while(!UARTCharsAvail(UART2_BASE));
            char c2=UARTCharGetNonBlocking(UART2_BASE);
            if(c2=='P'){
                while(!UARTCharsAvail(UART2_BASE));
                char c3=UARTCharGetNonBlocking(UART2_BASE);
                if(c3=='R'){
                    while(!UARTCharsAvail(UART2_BASE));
                    char c4=UARTCharGetNonBlocking(UART2_BASE);
                    if(c4=='M'){
                        while(!UARTCharsAvail(UART2_BASE));
                        char c5=UARTCharGetNonBlocking(UART2_BASE);
                        if(c5=='C'){
                            while(!UARTCharsAvail(UART2_BASE));
                            char c6=UARTCharGetNonBlocking(UART2_BASE);
                            if(c6==','){
                                while(!UARTCharsAvail(UART2_BASE));
                                char c7=UARTCharGetNonBlocking(UART2_BASE);

                                //assign the data to the GPSValues array. read up to the last data checksum (like checksum: A*60)
                                while(c7!='*'){
                                    GPSValues[index]=c7;
                                    while(!UARTCharsAvail(UART2_BASE));
                                    c7=UARTCharGetNonBlocking(UART2_BASE);
                                    index++;}


                                //Separating the data in the GPSValues ??array by comma
                                index=0;
                                token = strtok(GPSValues, comma);
                                while( token != NULL ) {
                                    strcpy(parseValue[index], token);
                                    token = strtok(NULL, comma);
                                    index++;}


                                //Data valid if parseValue[1] = A - not valid if =V
                                if(strcmp(parseValue[1],"A")==0){
                                    latitude=atof(parseValue[2]);
                                    longitude=atof(parseValue[4]);


                                    //latitude calculation
                                    degrees=latitude/100;
                                    minutes=latitude-(double)(degrees*100);
                                    seconds=minutes/60.00;
                                    result=degrees+seconds;
                                    sprintf(latitudeResult,"%f", result);


                                    //longitude calculation
                                    degrees=longitude/100;
                                    minutes=longitude-(double)(degrees*100);
                                    seconds=minutes/60.00;
                                    result=degrees+seconds;
                                    sprintf(longitudeResult, "%f", result);


                                    //printf("https://www.google.com/maps/place/%s+%s \n",latitudeResult,longitudeResult);
                                    //date correction
                                    for(i=0;i<6;i++){
                                        date[j]=parseValue[index-2][i];
                                        if(i==1 || i==3){
                                            j++;
                                            date[j]='/';}
                                        j++;}
                                    date[8]='\0';


                                    //time correction +3 UTC adjustment
                                    time=settime(parseValue[0]);
                                    j=0;
                                    for(i=0;i<6;i++){
                                        CurrentTime[j]=time[i];
                                        if(i==1 || i==3){
                                            j++;
                                            CurrentTime[j]=':';}
                                        j++;}
                                    CurrentTime[8]='\0';




                                    printf("time  = %s\n",CurrentTime);
                                    printf("date = %s\n",date);
                                    printf("latitude = %s\n",latitudeResult);
                                    printf("longitude= %s\n\n\n",longitudeResult);
                                    SysCtlDelay(SysCtlClockGet()/6);}
                                else{
                                    printf("Reading GPS Data\n\n\n");}

                                printf("");
                        }}}}}}}
}


char* settime(char str[]){
    int num10 = str[0]-'0';
    int num1 = str[1]-'0';
    int timeData=num10*10+num1;

    timeData=timeData+3;
    if(timeData>24){
        timeData=timeData%24;
        if(timeData<10){
            str[0]='0';
            str[1]=timeData+'0';}
        else{
            str[0]=(timeData/10)+'0';
            str[1]=(timeData%10)+'0';}}
    else{
        str[0]=(timeData/10)+'0';
        str[1]=(timeData%10)+'0';}
    return str;
}
