#include <stdio.h>
#include <wiringPi.h>

#define TRIG 8
#define ECHO 9
#define wPi_PWM1 23

extern double Dist();
extern void calcRange();
extern void playMusic();
extern void Play(double r);

int main(int argc, char **argv)
{
	wiringPiSetup(); 			// Pin numbering method : wPi
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
	pinMode(wPi_PWM1, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);	// Default PWM_MODE_BAL
	calcRange();
	
	for(;;)
	{
		double di = Dist();
		printf("Distance : %.2f(cm) \n", di);
		if (di < 15) playMusic(); //-> 거리가 15이하이면 노래 재생
		// double r = (di > 100) ? 1.0 : (di < 50) ? 2.0 : 1.5;
		// if(d > 100) r = 1.0;
		// else if(d < 50) r = 2.0;
		// else r = 1.5
		// Play(r);
		
		delay(1000);		//기본 delay는 ms 단위 100
	}
	return 0;
}
