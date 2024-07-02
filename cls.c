#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main()
{
	printf("\033[2J");		// [2J = Clear Screen 
	//printf("\033[12;40H");	// [1;1H = x;yH = 커서 화면 위치 초기화
	
	int fd = wiringPiI2CSetup(0x48);  //i2cdetect -y 1 에서 찾은 주소이며 '0x48'로 사용한다.
	
	/* while (1)
	{
		int v1, v2;
		int x = 12, y = 40;
		// float f1, f2;
	
		wiringPiI2CWrite(fd, 00);	// ch00 (joystic X-axis)
		// v1 = wiringPiI2CRead(fd);
		// f1 = (float)((v1/255.0)*80.0);
		int f1 = (wiringPiI2CRead(fd * 80)/255;	
			// 형변환에서 오류 방지를 위해 형태의 형식 처리 와 괄호처리 반드시 할것
		delay(100);		// 별도의 단위가 없으면 ms단위를 사용한다.
	
		wiringPiI2CWrite(fd, 01);	// ch01 (joystic Y-axis)
		// v2 = wiringPiI2CRead(fd);
		// f2 = (float)((v2/255.0)*24.0);	
		int f2 = wiringPiI2CRead(fd*24) / 255;
		delay(100);
	
		//printf("%d %d (%4.1fV, %4.1fV)\n",v1, v2, f1, f2);
		//printf("%4.1f, %4.1f", f2, f1);
		printf("\033[%d;%dH ",(int)f2,(int)f1);
		//delay(100);		
		//printf("\033[2J");
	} */ // 내가 짠 코드 
	while (1)
	{
		wiringPiI2CWrite(fd, 00); 
		wiringPiI2CRead(fd);
		int x = (wiringPiI2CRead(fd) * 80) / 255; //0~255
		delay(100);
		
		wiringPiI2CWrite(fd, 01);
		wiringPiI2CRead(fd);
		int y = (wiringPiI2CRead(fd) * 24) / 255;
		delay(100);
				
		printf("%d %d\n", y, x);
		printf("\033[%d;%dH", y, x);
		delay(200);
		  // 교수님 코드
	}
	
	return 0;
}
