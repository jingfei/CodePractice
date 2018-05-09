#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[100100];
int pi[100100];

int main(){
	while(scanf("%s",s)!=EOF){
		int Len=strlen(s); pi[Len-1]=Len;
		for(int i=0,k=Len; i<Len; ++i){
			if(k<Len && s[i]!=s[k-1]) k=Len;
			if(s[i]==s[k-1]) --k;
			pi[i]=k;
		}
		for(int i=0; i<Len; ++i) printf("%c",s[i]);
//		printf("%s",s);
		for(int i=pi[Len-1]-1; i>=0; --i) printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}

