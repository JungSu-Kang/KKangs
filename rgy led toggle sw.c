#include <wiringPi.h>				// wiringPi 헤더파일
#include <stdio.h>

int ps[40];		// pin number : 40, pin status : default 0
void Toggle(int pin)
{
	ps[pin] = !ps[pin];			// pin 8 = 0 일 경우 !(not) 반전 시키고 ps[pin]에 댕입 시킨다
	digitalWrite(pin, ps[pin]);	
}

int main()
{
	wiringPiSetup();				// Pin number use case (wPi)
	pinMode(8, OUTPUT);				//	8,9,7 : OUT   2 : IN
	pinMode(9, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(2, INPUT);
	int mode = 0;
	for(i = 0; 1 < 20; i++) //while(1) 		// 무한 루프 설정 == for(;;) or while(1);
	{
		if(mode)
		{
			Toggle(8); delay(200);
			Toggle(9); delay(200);
			Toggle(7); delay(200);
		}
		else
		{
			Toggle(7); delay(200);
			Toggle(9); delay(200);
			Toggle(8); delay(200);
		}
		if(digitalRead(2) == 0) 	// pushed (normal 1)
		{
			mode = !mode;	//++;
		}
				
	}
		
	return 0;
}
