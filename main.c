#include "config.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>    //for sockaddr_in
#include <arpa/inet.h>	   //for inet_pton and so on

#define MAXLINE 1024

int main(){
	IPAddress conf = getconfig();

	struct sockaddr_in sockaddr;
	memset(&sockaddr,0,sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(conf.port);
	inet_pton(AF_INET,conf.IP,&sockaddr.sin_addr);

	int sock = socket(AF_INET,SOCK_STREAM,0);

	char recvbuf[MAXLINE], sendbuf[MAXLINE];

	if(connect(sock,(struct sockaddr*)&sockaddr,sizeof(sockaddr)) < 0){
		printf("connect error: %s errno: %d\n",strerror(errno),errno);
		exit(0);
	}	


	printf("send opeartion to spvserver\n");
	
	fgets(sendbuf,1024,stdin);

	if(send(sock,sendbuf,strlen(sendbuf),0)<0){
		printf("send message error: %s errno: %d\n",strerror(errno),errno);
		exit(0);
	}
	
	close(sock);
	printf("close");
		
	return 0;
}
