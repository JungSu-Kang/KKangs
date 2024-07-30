#include <stdio.h>
#include <wiringPi.h>
#include <pthread.h>

#define TRIG 8
#define ECHO 9

extern void Trigger();
extern void usISR();
extern double Dist();
extern double dist;

void *usThread(void *a)  // thread는 메인이 실행 중 계속 실행 되고 있어야 함.
{
	while(1)
	{
		Dist(); delay(70);
	}
}

int main()
{
	pthread_t th;
	wiringPiSetup();
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);


	// printf("initial Distance : %.2f		\r",dist);
	// TriggerEx();
	pthread_create(&th, NULL, usThread, NULL);
	//wiringPiISR(ECHO, INT_EDGE_BOTH, usISR);	// Regist ISR (ISR등록)
	//Trigger();
	
	while(1)
	{
		printf("Distance : %.2f		\r", dist); // \r 은 같은줄에 앞자리로 가는것
	}
	
}


