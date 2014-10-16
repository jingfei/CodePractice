
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define PORT 1234
#define MAXSOCKFD 10

main()
{
    int sockfd,is_connected,fd;
    struct sockaddr_in addr;
    int addr_len = sizeof(struct sockaddr_in);
    fd_set readfds;
    char buffer[256];
	char abc[256];
    char msg[ ] = "Welcome to server!";

    /* 建立socket */
    if ((sockfd = socket(AF_INET,SOCK_STREAM,0))<0){
      perror("socket");
      exit(1);
    }

    /* 填寫server端的sockaddr_in結構 */
    bzero(&addr,sizeof(addr));
    addr.sin_family =AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    /* 連結socket */
    if(bind(sockfd,(struct sockaddr*)&addr,sizeof(addr))<0){
      perror("connect");
      exit(1);
    }

    /* 等待連線 */
    if(listen(sockfd,3)<0){
      perror("listen");
    exit(1);
    }

    /*  */
    is_connected=0;
    
    /*  */
    while(1){
		if(!is_connected){
          if((sockfd = accept (sockfd,(struct sockaddr*)&addr,&addr_len))<0)
            perror("accept");
          write(sockfd,msg,sizeof(msg));
          is_connected = 1;
          printf("connect from %s\n",inet_ntoa(addr.sin_addr));
       	}
	   	else{
          bzero(buffer,sizeof(buffer));
          if(read(sockfd,buffer,sizeof(buffer))<=0){
            printf("connect closed.\n");
            is_connected=0;
            close(sockfd);
          }
		  else
            printf("%s",buffer);
		  printf("new str:\n");
		  bzero(abc,sizeof(abc));
		  read(STDIN_FILENO,abc,sizeof(abc));
		  write(sockfd,abc,sizeof(abc));
       	}
    }
}
