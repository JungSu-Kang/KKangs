#include <stdio.h>
#include <wiringPi.h>

#define TRIG 8
#define ECHO 9

#define CLK 	19200000
#define PSC 	19
#define RANGE 	66666	// for 15Hz
#define VAL		10

void TriggerEx()
{
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(PSC*2);	// divisor (PSC)클럭 주파수의 유효자리 수정도
	pwmSetRange(RANGE/2); // 15Hz
	pwmWrite(TRIG, VAL/2);
}

void Trigger()
{
	digitalWrite(TRIG, 1);
	delayMicroseconds(10);
	digitalWrite(TRIG, 0);
	delayMicroseconds(200); // delay for burst	
}
