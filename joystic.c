#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main()
{
	int fd = wiringPiI2CSetup(0x48);  //i2cdetect -y 1 에서 찾은 주소이며 '0x48'로 사용한다.
	
	while (1)
	{
	int v1, v2;
	float f1, f2;
	
	wiringPiI2CWrite(fd, 00);	// ch00 (joystic X-axis)
	v1 = wiringPiI2CRead(fd);
	f1 = (float)((v1/255.0)*5.0);	
		// 형변환에서 오류 방지를 위해 형태의 형식 처리 와 괄호처리 반드시 할것
	delay(100);		// 별도의 단위가 없으면 ms단위를 사용한다.
	
	wiringPiI2CWrite(fd, 01);	// ch01 (joystic Y-axis)
	v2 = wiringPiI2CRead(fd);
	f2 = (float)((v2/255.0)*5.0);	
	delay(100);
	
	printf("%d %d (%4.1fV, %4.1fV)\n",v1, v2, f1, f2);
	//printf("%d %d\n",v1, v2);
	
	}
}
