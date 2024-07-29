#include <stdio.h>
#include <wiringPi.h>

#define TRIG 8
#define ECHO 9
extern void Trigger()

int t1;	// ISR에서 사용할 전역 변수
double dist; 
void usISR()  // ISR : no arg no return
{
	int tt = micros();
	int sg = digitalRead(ECHO);	// read current Pin status
	if(sg == 1) t1 = tt;		// Rising Edge(만약 현재 상태가 1이면) : Start counter
	else   						// Falling Edge(그렇지 않으면 (0이면)) : Calc distance (거리 계산 )
	{
		dist = (tt - t1) * 0.017; // (340 / 1000000 / 2 * 100); -> cm
	}
}

double Dist()
{
	wiringPiSetup();
	// Trigger signal
    Trigger();
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
	dist = (t2 - t1) * 0.017; //(340 / 1000000 / 2 * 100); 	// 거리 계산 간소화 식 by cm
	return dist; //(t2 - t1) * 0.017;
}
