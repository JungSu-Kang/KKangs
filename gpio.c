#include <wiringPi.h>				// wiringPi 헤더파일
#include <stdio.h>

#define RED   8
#define GREEN 9
#define YELLO 7
#define SW	  2

int mode = 0;
int intv = 0;		// 0 ~ 9
int tim;			// delay time interval(ms)
int ps[40];		    // pin number : 40, pin status : default 0

void Toggle(int pin)
{
	ps[pin] = !ps[pin];			// pin 8 = 0 일 경우 !(not) 반전 시키고 ps[pin]에 댕입 시킨다
	digitalWrite(pin, ps[pin]);	
}

void gpioisr()
{
	if(++intv > 8) intv = 0;
	printf("GPIO interrupt occured...\n");
			
}

int main()
{
	wiringPiSetup();				// Pin number use case (wPi)
	pinMode(RED, OUTPUT);				//	8,9,7 : OUT   2 : IN
	pinMode(GREEN, OUTPUT);
	pinMode(YELLO, OUTPUT);
	pinMode(SW, INPUT);
	wiringPiISR(SW, INT_EDGE_FALLING, gpioisr);		// registration GPIO ISR

	for(;;) //while(1) -> 무한 루프 설정 == for(;;) or while(1);
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
				
	}
		
	return 0;
}
