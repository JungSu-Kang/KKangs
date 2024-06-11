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
	int cnt = 0;
	for(;;) //while(1) 		// 무한 루프 설정 == for(;;) or while(1);
	{
		switch(cnt)
		{
			case 0:
			Toggle(8); delay(1000);
			Toggle(9); delay(1000);
			Toggle(7); delay(1000);
			break;
			
			case 1:
			Toggle(8); delay(200);
			Toggle(9); delay(200);
			Toggle(7); delay(200);
			break;
			
			case 2:
			Toggle(8); delay(800);
			Toggle(9); delay(800);
			Toggle(7); delay(800);
			break;
			
			case 3:
			Toggle(8); delay(200);
			Toggle(9); delay(200);
			Toggle(7); delay(200);
			break;
			
			case 4:
			Toggle(8); delay(600);
			Toggle(9); delay(600);
			Toggle(7); delay(600);
			break;
			
			case 5:
			Toggle(8); delay(200);
			Toggle(9); delay(200);
			Toggle(7); delay(200);
			break;
			
			case 6:
			Toggle(8); delay(400);
			Toggle(9); delay(400);
			Toggle(7); delay(400);
			break;
			
			case 7:
			Toggle(8); delay(200);
			Toggle(9); delay(200);
			Toggle(7); delay(200);
			break;
			
			case 8:
			digitalWrite(8, 1); delay(1000);
			digitalWrite(9, 1); delay(1000);
			digitalWrite(7, 1); delay(1000);
			break;
		}
		if(digitalRead(2) == 0)
		{
			cnt += 1;
		}
		if (cnt == 10)
		{
			digitalWrite(8, 0);
			digitalWrite(9, 0);
			digitalWrite(7, 0);
			break;
		}
	}
	return 0;
}
