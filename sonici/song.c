#include <stdio.h>
#include <wiringPi.h>


#define wPi_PWM1 23
int PSC = 19;
int RANGE = 100;
//int DUTY = RANGE / 2;

enum { DO=0, Do, RE, Re, MI, FA, Fa, SL, Sl, LA, La, CI };
// enum은 define문과 다르게 순서대로 값을 저장 할수 있다
int pitch[] = { 262,277,294,311,330,349,370,392,415,440,466,494 };
int range[12];
int song[] = { SL, SL, LA, LA, SL, SL, MI, SL,SL,MI,MI,RE,
			   SL, SL, LA, LA, SL, SL, MI, SL, MI, RE, MI, DO, -1 }; //-1은 종료를 확인하기 위한 숫자
int rythm[] = { 4,4,4,4,4,4,2,-1,4,4,4,4,1,
				 4,4,4,4,4,4,2,4,4,4,4,1 };
	
void calcRange()	// Calc Range values using Pitch data (Pitch data == 주파수)
{
	for (int i=0;i<12;i++)
	{	
		range[i] = 19200000 / (PSC * pitch[i]);
	}
}
double rate = 1;	
void playSound(int um, int len)		// um : pitch, len : rhythm
{
	pwmSetClock(PSC);	// Prescaler 1MHz 까지 Control 가능
	pwmSetRange(range[um]);	 
	pwmWrite(wPi_PWM1, (range[um]/2));	// Duty 50%
	delay(len * 100);
	pwmWrite(wPi_PWM1, 0);
	delay(500); //(rythm * rate)); //1을 기준(2000)으로 설정 후 rhythm으로 나눔

}
int iFlag = 0;
void initSound()
{
	wiringPiSetup();
	pinMode(wPi_PWM1, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);	// Default PWM_MODE_BAL
	calcRange();
	iFlag = 1;
}

void Play(double r)
{
	if(!iFlag) initSound();
	rate = r;
	double d1 = rate;
	if(n>1)
	{ 
		sscanf(v[1], "%lf",&d1); 
	}
	rate = d1;
	
	wiringPiSetup();
	pinMode(wPi_PWM1, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);	// Default PWM_MODE_BAL
	calcRange();
	for(int i=0;song[i] !=-1;i++)
	{
		playSound(song[i], rythm[i]);
		delay(500/rythm[i]);
	}
	pwmWrite(wPi_PWM1, 0);
	//pinMode(wPi_PWM1, PWM_OUTPUT);
	
	return 0;
}

/* int main(int n, char *v[])
{
	double d1 = rate;
	if(n>1)
	{ 
		sscanf(v[1], "%lf",&d1); 
	}
	rate = d1;
	
	wiringPiSetup();
	pinMode(wPi_PWM1, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);	// Default PWM_MODE_BAL
	calcRange();
	for(int i=0;song[i] !=-1;i++)
	{
		playSound(song[i], rythm[i]);
		delay(500/rythm[i]);
	}
	pwmWrite(wPi_PWM1, 0);
	//pinMode(wPi_PWM1, PWM_OUTPUT);
	
	return 0;
} */
