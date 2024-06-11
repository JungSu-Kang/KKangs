#include <wiringPi.h>				// wiringPi 헤더파일
#include <stdio.h>

#define RED   8
#define GREEN 9
#define YELLO 7
#define SW	  2

int ps[40];		// pin number : 40, pin status : default 0
void Toggle(int pin)
{
	ps[pin] = !ps[pin];			// pin 8 = 0 일 경우 !(not) 반전 시키고 ps[pin]에 댕입 시킨다
	digitalWrite(pin, ps[pin]);	
}

int main()
{
	wiringPiSetup();				// Pin number use case (wPi)
	pinMode(RED, OUTPUT);				//	8,9,7 : OUT   2 : IN
	pinMode(GREEN, OUTPUT);
	pinMode(YELLO, OUTPUT);
	pinMode(SW, INPUT);
	int mode = 0;
	int intv = 2;		// 2 ~9
	int tim;			// delay time interval(ms)
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
		if(digitalRead(2) == 0) 	// pushed (normal 1)
		{
			//mode = !mode;	//++;
			intv++;
			if(intv > 8) intv = 1;
		}
				
	}
		
	return 0;
}
