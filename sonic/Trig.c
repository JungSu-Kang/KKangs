#include <stdio.h>
#include <wiringPi.h>

#define TRIG 8
#define ECHO 9

void Trigger()
{
	// Trigger signal
	digitalWrite(TRIG, 1);
	delayMicroseconds(10);		// raspberry Pi에서는 us 단위를 제공함으로 사용 가능함
	digitalWrite(TRIG, 0);
	delayMicroseconds(200);		// 200 x 0.34mm = 68mm는 무시 한다는 의미 //wait
}

