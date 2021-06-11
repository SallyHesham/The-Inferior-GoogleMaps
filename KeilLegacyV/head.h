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
extern char digit1, digit2, digit3;
extern double PX;
extern double PY;
extern double CX;
extern double CY;
extern int first_point;
extern double total_distance;
extern double dist[2][2];
//extern double distance;
//int distanceMarkIII(int x, int y);
double distanceNew(double lat,double lon);
void delay_ms(int n);
void delay_us(int n);
void LCD_command(unsigned char com);
void LCD_DATA(unsigned char data);
void Delayyy(void);
extern int R;
extern double PI;
void UART2Init(void);
void readGPSModule(void);
void gpsSetup(void);
extern double lat;
extern double lon;

#define CPACR     (*((volatile unsigned long *)0xE000ED88))
