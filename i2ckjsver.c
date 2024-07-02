#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main()
{
	int fd = wiringPiI2CSetup(0x48);  //i2cdetect -y 1 에서 찾은 주소이며 '0x48'를 같이 사용한다.
		// = Device 초기화 -> i2c를 사용하기 위해 셋업을 함.
		// fd = device handle이 return 되는 변수 설정
		// 여러곳에 상수를 사용하게되면 프로그램 변경에 어려움이 많다 그래서 변수,상수를 미리 선언해서 사용하고
		// 이후 변경시 선언된 곳에서 바꾸면 전체 사용에도 도움이 된다.

	while (1)
	{
		int slt;
		int i;
		printf("select sensor : lux=0,temp=1,VR=03,exit=5\n");
		scanf("%d", &slt);
		
		if (slt == 5) break;
		else if (slt == 0)
		{
			for (i = 0; i < 15; i++)
			{
			wiringPiI2CWrite(fd, 00);  // ch00 (lux)
			int val = wiringPiI2CRead(fd);	// 값을 읽어서 int 값으로 되돌려 주는 명령어
			float f = (float)((val/255.0)*5.0);	
			printf("lux input level = %d (%4.1fV)\n", val, f);
			delay(500);		// 별도의 단위가 없으면 ms단위를 사용한다.
			}
		}
		else if (slt == 1)
		{
			for (i = 0; i < 15; i++)
			{
			wiringPiI2CWrite(fd, 01);  // ch01 (temp)
			int val = wiringPiI2CRead(fd);
			float f = (float)((val/255.0)*5.0);	
			printf("temp input level = %d (%4.1fV)\n", val, f);
			delay(500);		// 별도의 단위가 없으면 ms단위를 사용한다.
			}
		}
		else if (slt == 3)
		{
			for (i = 0; i < 15; i++)
			{
			wiringPiI2CWrite(fd, 03);  // ch03 (VR)
			int val = wiringPiI2CRead(fd);
			float f = (float)((val/255.0)*5.0);	
			printf("VR input level = %d (%4.1fV)\n", val, f);
			delay(500);		// 별도의 단위가 없으면 ms단위를 사용한다.
			}
		}
		else 
		{
			printf("올바른 선택을 하시오!");
		}
		
	}
/*	wiringPiI2CWrite(fd, 3);  // ch00 (lux), ch01 (temp), ch03 (VR)
	int v1, v2, v3;
	float f1, f2, f3;
	while(1)
	{
		v1 = wiringPiI2CRead(fd, 0);	// ch00(Right) lelect
		f1 = (float)((v1/255.0)*5.0);	
		 // 형변환에서 오류 방지를 위해 형태의 형식 처리 와 괄호처리 반드시 할것
		printf("ADC input level = %d (%4.1fV)\n", val3, f);
		delay(500);		// 별도의 단위가 없으면 ms단위를 사용한다.
	} */
}
