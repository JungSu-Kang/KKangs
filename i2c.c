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

	int v1, v2, v3;
	float f1, f2, f3;
	while(1)
	{
		wiringPiI2CWrite(fd, 00);	// ch00 (Light) select
		v1 = wiringPiI2CRead(fd);
		f1 = (float)((v1/255.0)*5.0);	
		// 형변환에서 오류 방지를 위해 형태의 형식 처리 와 괄호처리 반드시 할것
		delay(100);		// 별도의 단위가 없으면 ms단위를 사용한다.
		
		wiringPiI2CWrite(fd, 01);	// ch01 (temp) select
		v2 = wiringPiI2CRead(fd);
		f2 = (float)((v2/255.0)*5.0);	
		delay(100);
			
		wiringPiI2CWrite(fd, 03);	// ch03 (VR) select
		v3 = wiringPiI2CRead(fd);
		f3 = (float)((v3/255.0)*5.0);	
		delay(100); 
		printf("ADC input level = %d %d %d(%4.1fV, %4.1fV %4.1fV)\n", v1, v2, v3, f1, f2, f3);
		printf("ADC value : %d(%4.1fV)\n",v1, f1);
		delay(100);
		}		
}
