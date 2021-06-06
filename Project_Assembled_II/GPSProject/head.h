#define FUNC_HEAD
double distance(float x, float y);
void led (int Dis);
void initPortF(void);
void initPortAB(void);
void PortE_Init(void);
void Delay2(void);
void Display(int digit, int number);
void NumSplit(int calculated);
void ledRed(void);
void ledBlue(void);
void ledGreen(void);
float distanceMarkII(float x, float y);
extern int digit1, digit2, digit3;
extern float PX;
extern float PY;
extern int firstPoint;
extern float totalDist;
extern float dist;
int distanceMarkIII(int x, int y);
double distanceNew(double lat,double lon);
void delay_ms(int n);
void delay_us(int n);
void LCD_command(unsigned char com);
void LCD_DATA(unsigned char data);

#define CPACR     (*((volatile unsigned long *)0xE000ED88))
