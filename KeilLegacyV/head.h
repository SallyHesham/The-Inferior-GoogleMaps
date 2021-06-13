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
extern int first_point;
extern double total_distance;
extern double dist[2][2];
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
//void gpsSetup(void);
extern double latglo;
extern double longlo;
double atof (const char*);

#define CPACR     (*((volatile unsigned long *)0xE000ED88))
