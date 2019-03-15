#include "config.h"


IPAddress getconfig(){
	FILE *pFile;
	char *pbuf;
	int fileLight;
	IPAddress tmp={"0",0};

	pFile = fopen("config.xml","r");
	if(pFile == NULL){
		fprintf(stderr,"Open file config.xml failed\n");
		return tmp;
	}
	
	fseek(pFile,0,SEEK_END);
	fileLight = ftell(pFile);
	pbuf = (char *)malloc(fileLight);

	rewind(pFile);

	fread(pbuf,1,fileLight,pFile);
	pbuf[fileLight] = 0;
	fclose(pFile);
	fprintf(stdout,"pbuf:%s",pbuf);

	int iplen = 0;
	char *portstr = pbuf;
	int i = 0;
	while(*portstr != '\n'){
		portstr += 1;
		iplen++;
	}
	printf("iplen:%d\n",iplen);
	tmp.IP = (char *)malloc(iplen);
	for(i=0;i<iplen;i++){
		tmp.IP[i] = pbuf[i];
	}
	tmp.IP[iplen] ='\0';
	portstr += 1;
	tmp.port = atoi(portstr);

	printf("%s,%d\n",tmp.IP,tmp.port);
	
	return tmp;
}

/*
int main(){
	getconfig();
	return 0;	



}
*/
