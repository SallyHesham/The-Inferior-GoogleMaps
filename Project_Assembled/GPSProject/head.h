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
double distanceMarkII(double x, double y);
extern int digit1, digit2, digit3;
extern double PX;
extern double PY;
extern int firstPoint;
extern double totalDist;
extern double dist;
int distanceMarkIII(int x, int y);
#define CPACR     (*((volatile unsigned long *)0xE000ED88))
