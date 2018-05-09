#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char s[1000010];
void reverse(int l,int r){
	int n=(r-l)>>1;
	for(int i=l,j=r-1; i<l+n; ++i,--j){
		char tmp=s[i]; s[i]=s[j]; s[j]=tmp;
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--){
		getchar(); scanf("%s",s);
		int len=strlen(s);
		for(int i=0; i<len; ++i){
			printf("%c",s[i]);
			if(s[i]=='a'){
				reverse(i+1,len);
			}
			else if(s[i]=='b'){
				for(int j=i+1,k=len; j<len; ++j,++k)
					s[k]=s[j];
				len+=(len-i-1);
				s[len]='\0';
			}
			else if(s[i]=='c') i+=2; 
//			printf("%s\n",s);
		}
		printf("\n");
	}
	return 0;
}
