/* 利用socket的TCP client
   此程序會連線TCP server，並將鍵盤輸入的字符串傳送給server。
 */

#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#define PORT 8888
#define SERVER_IP "140.116.252.147"

void menu(){
	char str[256];
	bzero(str,sizeof(str));
	strcat(str,"\nchoose what to do next:\n");
	strcat(str,"\t1) send message\n");
	strcat(str,"\t2) send file\n");
	strcat(str,"\t3) get file\n");
	strcat(str,"\t4) exit\n");
//	write(sockfd,str,sizeof(str));
	printf("%s",str);
}

void sendStr(int sockfd, char *str){
	if(send(sockfd,str,sizeof(str),0)<0){
		perror("send error");
		exit(1);
	}
}

void fileGet(int sockfd){
	char filename[256], buffer[256];
	strcpy(filename, "getSample.txt");
	/* create file */
	FILE *fr = fopen(filename,"w");
	if(fr==NULL)
		printf("file wrong");
	else{
		bzero(buffer, sizeof(buffer)); 
		int fr_block_sz = 0;
		while((fr_block_sz = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) 
		{
			int write_sz = fwrite(buffer, sizeof(char), fr_block_sz, fr);
			if(write_sz < fr_block_sz)
			{
				perror("File write failed on client.\n");
			}
			bzero(buffer, sizeof(buffer)); 
			if (fr_block_sz == 0 || fr_block_sz != 512) 
			{
				break;
			}
		}
		if(fr_block_sz < 0)
		{
			fprintf(stderr, "recv() failed");
			exit(1);
		}
		printf("Ok received from server!\n");
		fclose(fr); 
	}
}

void sendFile(int sockfd){
	char sdbuf[256];
	char fs_name[256];
	scanf("%s",fs_name);
	FILE *fs = fopen(fs_name, "r");
	if(fs == NULL)
	{
		printf("ERROR: File %s not found.\n", fs_name);
		exit(1);
	}
	/*send file name*/
	sendStr(sockfd, fs_name);
	
	bzero(sdbuf, sizeof(sdbuf)); 
	int fs_block_sz; 
	while((fs_block_sz = fread(sdbuf, sizeof(char), sizeof(sdbuf), fs)) > 0)
	{
		if(send(sockfd, sdbuf, fs_block_sz, 0) < 0)
		{
			fprintf(stderr, "ERROR: Failed to send file %s.\n", fs_name);
			break;
		}
		bzero(sdbuf, sizeof(sdbuf));
	}
	printf("Ok File %s from Client was Sent!\n", fs_name);
}

int main(){
	int s;
	struct sockaddr_in addr;
	char buffer[256];
	char abc[256];

	/* 建立socket */
	if((s = socket(AF_INET,SOCK_STREAM,0))<0){ 
		perror("socket error");
		exit(1);
	}

	/* 填寫server端的sockaddr_in結構 */
	bzero(&addr,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port=htons(PORT);
	addr.sin_addr.s_addr = inet_addr(SERVER_IP);

	/* 建立連線*/
	if(connect(s,(struct sockaddr*)&addr,sizeof(addr))<0){
		perror("connect error");
		exit(1);
	}

	/* 接收由server端傳來的信息*/
	recv(s,buffer,sizeof(buffer),0);
	printf("%s\n",buffer);

	/* nickname */
	bzero(buffer,sizeof(buffer));
	read(STDIN_FILENO,buffer,sizeof(buffer));
	sendStr(s,buffer);
	
	int pid=fork();
	while(1){
		if(pid<0){
			perror("error on fork");
			exit(1);
		}
		else if(pid==0){
			sleep(1);
			menu();
			/* get choice */
			bzero(buffer,sizeof(buffer));
			read(STDIN_FILENO,buffer,sizeof(buffer));
			sendStr(s,buffer);
			int Choice=atoi(buffer);
			bool Exit=false;
			switch(Choice){
				case 1:
					bzero(buffer,sizeof(buffer));
					read(STDIN_FILENO,buffer,sizeof(buffer));
					sendStr(s,buffer);
					break;
				case 2:
					sendFile(s);
					break;
				case 3:
					bzero(buffer,sizeof(buffer));
					read(STDIN_FILENO,buffer,sizeof(buffer));
					sendStr(s,buffer);
					if(!strcmp(buffer, "yes\n"))
						fileGet(s);
					else{
						recv(s, abc, sizeof(abc), 0);
						printf("%s\n",abc);
					}
					break;
				case 4:
					Exit=true;
					break;
			}
			if(Exit) break;
		}
		else{
			recv(s, abc,sizeof(abc),0);
			printf("%s\n",abc);
		}
	}
	return 0;
}
