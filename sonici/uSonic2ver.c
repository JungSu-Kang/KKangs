#include <stdio.h>
#include <wiringPi.h>
#include <softTone.h>
#include <softPwm.h>

#define TRIG 8
#define ECHO 9
#define SUND 7

double Dist()
{
	// Trigger signal
		digitalWrite(TRIG, 1);
		delayMicroseconds(10);		// raspberry Pi에서는 us 단위를 제공함으로 사용 가능함
		digitalWrite(TRIG, 0);
		delayMicroseconds(200);		// 200 x 0.34mm = 68mm는 무시 한다는 의미
		
		//while(digitalRead(ECHO) != 0);		// Wait for burst Start
		// Wait for Echo signal //전원 인가 후 최초에만 유효한 명령어(없어도 되는 명령어)
		
		while(digitalRead(ECHO) != 1);		// Wait for Echo High
		// burst 신호 이후 rising edge 될때까지 (t1 time count start)
		int t1 = micros();					// Get start time(in micros-second)
		while(digitalRead(ECHO) != 0);		// Wait for Echo Low
		// high 신호 이후 falling edge 될때까 (t2 time count)
		int t2 = micros();					// Get end time
		//double dist = (t2 - t1) * (340 / 1000000 / 2 * 100);
		// 340m/s(음속) / 1000000s(us로 변환) / 2(왕복이므로 거리는 절반) * 100(cm로 변환)
		// double dist = (t2 - t1) * 0.017; 	// 거리 계산 간소화 식 by cm
		return (t2 - t1) * 0.017;
}
int main(int argc, char **argv)
{
	wiringPiSetup(); 			// Pin numbering method : wPi
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
	pinMode(SUND, OUTPUT);
	softToneCreate(SUND);
	
	for(;;)
	{
		printf("Distance : %f(cm) \n", Dist());
		delay(500);		//기본 delay는 ms 단위 1000
		
		/* if (Dist() <= 50)
		{
			softToneWrite(SUND, 1047);
			delay(100);
		}
		else if (Dist() >= 50 && Dist() <= 100)
		{
			softToneWrite(SUND, 523);
			delay(100);
		}
		else if (Dist() >= 100)
		{
			softToneWrite(SUND, 262);
			delay(100);
		}
		else 
		{
			softToneStop(SUND);
		} */
	}
	
	return 0;
}
