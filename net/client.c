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
#define PORT 1234
#define SERVER_IP "127.0.0.1"

main()
{
    int s;
    struct sockaddr_in addr;
    char buffer[256];
	char abc[256];

    /* 建立socket */
    if((s = socket(AF_INET,SOCK_STREAM,0))<0){ 
      perror("socket");
      exit(1);
    }

    /* 填寫server端的sockaddr_in結構 */
    bzero(&addr,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port=htons(PORT);
    addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    
    /* 建立連線*/
    if(connect(s,(struct sockaddr*)&addr,sizeof(addr))<0){
      perror("connect");
      exit(1);
    }

    /* 接收由server端傳來的信息*/
    recv(s,buffer,sizeof(buffer),0);
    printf("%s\n",buffer);
    
    
    /* 將標準輸入的資料傳到server端 */
    while(1){
      bzero(buffer,sizeof(buffer));

      /* 從標準輸入設備取得字符串*/
      read(STDIN_FILENO,buffer,sizeof(buffer));
    
	  /* 將字符串傳給server端*/
      if(send(s,buffer,sizeof(buffer),0)<0){
        perror("send");
        exit(1);
      }

      /* 接收由server端傳來的信息*/
      recv(s,abc,sizeof(abc),0);
      printf("%s\n",abc);
    }
}
