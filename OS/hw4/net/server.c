#include<sys/types.h>  
//data types used in system calls
#include<sys/socket.h> 
//structures needed sockets
#include<netinet/in.h> 
//constants and structures for internet domain addresses
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAXSOCKFD 100
#define PORT 8888

bool Socks[MAXSOCKFD];
char SockName[MAXSOCKFD][256];
void doprocessing(int, char*);

void msgWrite(int sockfd, char *msg){
	char str[256];
	bzero(str,sizeof(str));
	strcat(str, msg);
	int i;
	if(sockfd==-1){ //send all
		for(i=0; i<MAXSOCKFD; ++i)
			if(Socks[i])
				write(i,str,sizeof(str));
	}
	else
		write(sockfd,str,sizeof(str));
}

bool sendMsg(int sockfd, char* ip){
	char buffer[256];
	msgWrite(sockfd, "say it!!");
	int readNum = read(sockfd,buffer,sizeof(buffer));
	printf("%s\n",buffer);
	if(readNum<=0){
		printf("connect closed.\n");
		close(sockfd);
		return false;
	}
	char tmpStr[256];
	strcpy(tmpStr, ip);
	strcat(tmpStr, " said: ");
	strcat(tmpStr, buffer);
	strcat(tmpStr, "\t((press enter))");
	msgWrite(-1, tmpStr);
	return true;
}

void sendFile(int sockfd){
	/* to make sure whether to get a file or not */
	char buffer[256];
	msgWrite(sockfd, "Do you want to get the \"Sample.txt\" file? (yes/no)");
	bzero(buffer, sizeof(buffer));
	int readNum = read(sockfd,buffer,sizeof(buffer));
	if(readNum<=0){
		printf("connect closed.\n");
		close(sockfd);
	}
	printf("%s\n", buffer);
	if(strcmp(buffer, "yes\n")){
		msgWrite(sockfd, "file not send\n");
		return;  //not to send file
	}
	/* send a file!! */
	char tmpStr[256];
	char sdbuf[256];
	char fs_name[256];
	strcpy(fs_name, "Sample.txt");
	FILE *fs = fopen(fs_name, "r");
	if(fs == NULL)
	{
		printf("ERROR: File %s not found.\n", fs_name);
		exit(1);
	}
	/*send file name*/
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
	printf("Ok File %s \"Sample.txt\" was Sent!\n", fs_name);
}

bool fileGet(int sockfd){
	char filename[256], buffer[256];
	msgWrite(sockfd, "file name?");
	bzero(filename, sizeof(filename));
	int readNum = read(sockfd,filename,sizeof(filename));
	printf("%s\n",filename);
	if(readNum<=0){
		printf("connect closed.\n");
		close(sockfd);
		return false;
	}
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
				perror("File write failed on server.\n");
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
		printf("Ok received from client!\n");
		fclose(fr); 
	}
	return true;
}

int main(){
	int sockfd,newsockfd,fd;
	struct sockaddr_in addr;
	memset(Socks,false,sizeof(Socks));
	memset(SockName,0,sizeof(SockName));
	// A sockaddr_in is a structure containing an internet address
	/*
	   struct sockaddr_in
	   {
	   short   sin_family; // must be AF_INET 
	   u_short sin_port;
	   struct  in_addr sin_addr;  
	//contains only one field, a unsigned long called s_addr
	char    sin_zero[8]; // Not used, must be zero 
	};
	 */
	int addr_len = sizeof(struct sockaddr_in);
	fd_set readfds;
	char buffer[256];
	char abc[256];

	/* 建立socket */
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	// int socket(domain, type, protocol)
	if ( sockfd < 0 ){
		perror("socket error");
		exit(1);
	}

	/* 填寫server端的sockaddr_in結構 */
	bzero(&addr,sizeof(addr));  //sets all values in a buffer to zero
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);  
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	// htons(): host to network short
	// htonl(): host to network long
	// ntohs(): network to host short
	// ntohl(): network to host long

	/* 連結socket */
	if(bind(sockfd, (struct sockaddr*)&addr, sizeof(addr))<0){
		perror("binding error");
		exit(1);
	}

	/* 等待連線 */
	if(listen(sockfd,5)<0){
		perror("listen");
		exit(1);
	}

	/*  */
	int Con=0;
	printf("Waiting accepted...\n");
	while(1){
		newsockfd = accept(sockfd, (struct sockaddr*)&addr, &addr_len);
		// causes the process to block until a client connects 
		if(newsockfd<0){
			perror("error on accept");
//			write(sockfd,msg,sizeof(msg));  //error msg
//			close(sockfd);
			exit(1);
		}
		/* Create child process */
		int pid=fork();
		if(pid < 0){
			perror("error on fork");
			exit(1);
		}
		if(pid==0){
			//connect succeed, print ip
			printf("connect from %s\n",inet_ntoa(addr.sin_addr));
			Socks[newsockfd]=true;
//			close(sockfd);
			msgWrite(newsockfd, "What's ur nickname?");
			bzero(SockName[newsockfd], sizeof(SockName[newsockfd]));
			int readNum=read(newsockfd, SockName[newsockfd], sizeof(SockName[newsockfd]));
			if(readNum<=0){
				printf("connect wrong...\n");
				break;	
			}
			printf("nickname: %s\n",SockName[newsockfd]);
			while(Socks[newsockfd]){
				doprocessing(newsockfd, inet_ntoa(addr.sin_addr));
			}
			break;
		}
	}
	return 0;
}

void doprocessing(int sock, char *ip){
	char buffer[256];
	bzero(buffer,sizeof(buffer));  //initialize buffer
	int readNum = read(sock,buffer,sizeof(buffer));
	// block until there is something for it to read in the socket
	bool connected=true;
	if(readNum<=0 || !connected){
		printf("connect from %s closed.\n",ip);
		close(sock);
		Socks[sock]=false;
		return;
	}
	else{
		printf("here\n");
		int Choice=(int)buffer[0]-'0';
		printf("%d\n",Choice);
		switch(Choice){
			case 1:
				connected=sendMsg(sock, ip);
				break;
			case 2:
				connected=fileGet(sock);
				break;
			case 3:
				sendFile(sock);
				break;
			case 4:
				msgWrite(sock, "GoodBye~");
				connected=false;
				break;
			default:
				msgWrite(sock, "choose again...\n\t((press enter))");
		}
	}
}

