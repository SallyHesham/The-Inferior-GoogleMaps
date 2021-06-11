#include "tm4c123gh6pm.h"
#include "head.h"

int chars [10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char digit1, digit2, digit3;

void NumSplit(int calculated){
int hundreds = calculated/100;
int tens = (calculated%100)*10;
int units = calculated - (hundreds*100) - (tens*10);
	digit1 = chars[hundreds];
	digit2 = chars[tens];
	digit3 = chars[units];
}
