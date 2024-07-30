#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <asm-generic/socket.h>
#include <asm-generic/types.h>
#include <unistd.h>
#include <netinet/in.h>


#define PORT	1004

int main()
{
	struct sockaddr_in sad,cad;  //sad=socket address, cad=client address
	memset(&sad, 0, sizeof(sad));
	memset(&cad, 0, sizeof(cad));
	
	sad.sin_family = AF_INET;
	sad.sin_port = htons(PORT); //htons(host to network short) short = 2byte
	sad.sin_addr.s_addr =htonl(INADDR_ANY); //htonl(host to network long) long = 4byte
	//printf("LE: %d    BE: %d\r\n", PORT, sad.sin_port);
	// PORT 1000의 LE방식은 16진수 '3E8' 값 출력되고, BE방식은 '59395' 값 출력
	// BE방식 은 LE값 03E8을 'E803' 으로 변경한것이고 이값의 10진수는 59395가 됨
	unsigned int fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	printf("socket open result : %d....\r\n", fd);
	
	int optvalue = 1;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &optvalue, sizeof(optvalue));
	
	unsigned int saddrLen = sizeof(sad);
	int bnd = bind(fd, (struct sockaddr*)&sad, saddrLen);
	printf("binding result : %d....\r\n", bnd);
		
	listen(fd, 2);  // waiting until requeset... (클라이언트로부터 요청이 올때까지 대기)
	int addrLen = sizeof(cad);
	int client = accept(fd, (struct sockaddr*)&cad, &addrLen);
	printf("Accept client result : %d....\r\n", client);
	
	char buf[100];
	while(1)
	{
		int r = read(client, buf, 20);
		if (r == -1) break;
		write(client, "OK\r\n",4);
		printf("Input message > %s\r\n", buf);
		if(strcmp(buf, "exit") == 0) break;
	}
	close(client);
}
