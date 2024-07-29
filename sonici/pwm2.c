#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define wPi_Pin 7		// 변수화 or 정의(define) 해 놓으면 변경 상황 발생시 관리가 용이함.
int main(int n, char * s[])
{
	if(n<2)
	{
		printf("usage : pwm2 [duty_rate(%%)] [[period]]\n\n");
		printf("default value : period = 10 ms, DR = 50%%\n\n");
		// return 1;
	}
	int dr = 50, drh, period = 10;
	if (n>1) sscanf(s[1], "%d", &dr);	// scanf -> 콘솔함수
		// sscanf -> scanf의 파생 함수로 string scanf의 뜻으로 문자열에서 입력 받음.
		// agument가 추가 됨"s[1]"에서 "%d" 값을 &dr에 넣어라
	if(n > 2) sscanf(s[2], "%d", &period);
	drh = (dr * period) / 100;	// Mark time : 7
	// drl = (period - drh);		// Space time : 3
	
	wiringPiSetup();	// wPi Pin numbering
	pinMode(wPi_Pin, OUTPUT);
	
	pwmSetMode(PWM_MODE_MS);	// MODE_MS == Mark & Space Mode (일반적인 Puls 방식)
								// MODE_BAL == Balance Mode (설정방법이 다소 복잡함)
	softPwmCreate(wPi_Pin, drh, period);	// argument 3ea pin value range
	//softPwmWrite(wPi_Pin, 70);
	
	delay(5000);
	softPwmStop(wPi_Pin);
	
	return 0;
}
// software pwm mode control
