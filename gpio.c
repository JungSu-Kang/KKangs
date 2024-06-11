#include <wiringPi.h>	// wiringPi 헤더파일
#include <stdio.h>

#define RED		8
#define GREEN	9
#define YELLO	7
#define SW		2
#define ITRT	3

int ps[40];				// pin number : 40, pin status : default 0
int mode = 0;
int intv = 0;			// 0 ~ 9
int tim;				// delay time interval(ms)
int flag = 1;			// stop interrupt 변수 선언 및 초기

void Toggle(int pin)
{
	ps[pin] = !ps[pin];	// pin 8 = 0 일 경우 !(not) 반전 시키고 ps[pin]에 대입 시킨다
	digitalWrite(pin, ps[pin]);	
}

void gpioisr()
{
	if(++intv > 8) intv = 0;
	printf("GPIO interrupt occured...\n");
}
void gpiostop()
{
	flag = 0;
	printf("GPIO interrupt stop occured...\n");	
}

int main()
{
	wiringPiSetup();								// Pin number use case (wPi)
	pinMode(RED, OUTPUT);							//	8,9,7 : OUT   2 : IN
	pinMode(GREEN, OUTPUT);
	pinMode(YELLO, OUTPUT);
	pinMode(SW, INPUT);
	pinMode(ITRT, INPUT);							// add new switch
	wiringPiISR(SW, INT_EDGE_FALLING, gpioisr);		// registration GPIO ISR
	wiringPiISR(ITRT, INT_EDGE_FALLING, gpiostop);	// interrupt stop

	for(;;) 			//무한 루프 설정 == for(;;) or while(1);
	{
		tim = (9-intv) *100;
		if(mode)
		{
			Toggle(RED); delay(tim);
			Toggle(GREEN); delay(tim);
			Toggle(YELLO); delay(tim);
		}
		else
		{
			Toggle(RED); delay(tim);
			Toggle(GREEN); delay(tim);
			Toggle(YELLO); delay(tim);
		}
		if(flag == 0) 
		{
			digitalWrite(RED, 0);
			digitalWrite(GREEN, 0);
			digitalWrite(YELLO, 0);
			break;			
		}
	}
	return 0;
}
