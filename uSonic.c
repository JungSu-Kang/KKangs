#include <stdio.h>
#include <wiringPi.h>

#define TRIG 8
#define ECHO 9

extern Dist();
int main(int argc, char **argv)
{
	wiringPiSetup(); 			// Pin numbering method : wPi
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
	
	for(;;)
	{
		printf("Distance : %f(cm) \n", Dist());
		delay(1000);		//기본 delay는 ms 단위 1000
	}
	return 0;
}
