#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char s[1000010];

int main(){
	int T; scanf("%d",&T);
	while(T--){
		getchar(); scanf("%s",s);
		int len=strlen(s);
		bool rev=false;
		for(int i=0; i<len && i>=0;){
			printf("%c",s[i]);
			if(s[i]=='a'){
				if(rev){ 
					strncpy(s,s,i);
					s[i]='\0';
					len=i;
					i=-1;
					rev=false;
				}
				else{
					char *p = s;
					p=p+(i+1)*sizeof(char);
					len=strlen(p);
					strcpy(s,p);
					 rev=true;
					 i=len;
				}
			}
			else if(s[i]=='b'){
				if(rev){
					strncpy(s,s,i);
					s[i]='\0';
					len=i*2;
					strcat(s,s);
					i=len;
				}
				else{
					char *p = s;
					p=p+(i+1)*sizeof(char);
					strcat(p,p);
					i=-1;
					len=strlen(p);
					strcpy(s,p);
				}
			}
			else if(s[i]=='c') rev ? i-=2 : i+=2;
			if(!rev) ++i;
			else --i;
		}
		printf("\n");
	}
	return 0;
}
