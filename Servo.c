#include <stdio.h>
#include <wiringPi.h>

#define SERVO_PIN 1		// wPi Number (Physical Pin Number 12)
int main(int argc, char **argv)
{
	wiringPiSetup();				// wiringPi 사용 설정
	pinMode(SERVO_PIN, OUTPUT);		// pinMode 출력 설정
	
	for(int j=0;j<5;j++)
	{
		for(int i=0;i<50;i++)
		{
			digitalWrite(SERVO_PIN, 1);		// Pin High 
			delayMicroseconds(500);			// cw 90degree
			digitalWrite(SERVO_PIN, 0);		// Pin Low 
			delayMicroseconds(19500);
		}
		/*for(int i=0;i<50;i++)
		{
			digitalWrite(SERVO_PIN, 1);		// Pin High 
			delayMicroseconds(1000);		// cw 45degree
			digitalWrite(SERVO_PIN, 0);		// Pin Low 
			delayMicroseconds(19000);
		}
		for(int i=0;i<50;i++)
		{
			digitalWrite(SERVO_PIN, 1);		// Pin High 
			delayMicroseconds(1500);		// cw 0degree (12o'clock)
			digitalWrite(SERVO_PIN, 0);		// Pin Low 
			delayMicroseconds(18500);
		}
		for(int i=0;i<50;i++)
		{
			digitalWrite(SERVO_PIN, 1);		// Pin High 
			delayMicroseconds(2000);		// ccw 45degree
			digitalWrite(SERVO_PIN, 0);		// Pin Low 
			delayMicroseconds(18000);
		} */
		for(int i=0;i<50;i++)
		{
			digitalWrite(SERVO_PIN, 1);		// Pin High 
			delayMicroseconds(2450);		// ccw 90degree
			digitalWrite(SERVO_PIN, 0);		// Pin Low 
			delayMicroseconds(17550);
		}		
		/* for(int i=0;i<50;i++)
		{
			digitalWrite(SERVO_PIN, 1);		// Pin High 
			delayMicroseconds(1500);		// cw 0degree (12o'clock)
			digitalWrite(SERVO_PIN, 0);		// Pin Low 
			delayMicroseconds(18500);
		} */
	}
	for(int i=0;i<50;i++)
		{
			digitalWrite(SERVO_PIN, 1);		// Pin High 
			delayMicroseconds(1400);		// cw 0degree (12o'clock)
			digitalWrite(SERVO_PIN, 0);		// Pin Low 
			delayMicroseconds(18600);
		}
	return 0;
}

