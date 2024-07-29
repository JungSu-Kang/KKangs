#include <stdio.h>
#include <wiringPi.h>

#define wPi_Pin 22		// 변수화 or 정의(define) 해 놓으면 변경 상황 발생시 관리가 용이함.
int main(int n, char * s[])
{
	if(n<2)
	{
		printf("usage : pwm1 [duty_rate(%%)] [[period]]\n\n");
		printf("        period = 10 ms if empty\n\n");
		return 1;
	}
	int i, dr, drh, drl, period = 10;
	sscanf(s[1], "%d", &dr);	// scanf -> 콘솔함수
		// sscanf -> scanf의 파생 함수로 string scanf의 뜻으로 문자열에서 입력 받음.
		// agument가 추가 됨"s[1]"에서 "%d" 값을 &dr에 넣어라
	if(n > 2) sscanf(s[2], "%d", &period);
	drh = (dr * period) / 100;	// s[1] 이 80이면 (80*10) / 100 == 8
	drl = (period - drh);       // 10 - 8 = 2
	
	wiringPiSetup();	// wPi Pin numbering
	
	pinMode(wPi_Pin, OUTPUT);
	for (i = 0; i < 500; i++)
	{
		digitalWrite(wPi_Pin, 1);
		delay(drh);			// 입력 받은 duty 만큼 on
		digitalWrite(wPi_Pin, 0);
		delay(drl);			// period - drh
	}
	
	return 0;
}


