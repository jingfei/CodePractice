#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ar[110];

int main(){
	char s[110];
	while(fgets(s,110,stdin)!=0){
		int Len=strlen(s),tmp=0,an=0;
		for(int i=0; i<Len; ++i){
			if(s[i]>='0' && s[i]<='9') tmp=tmp*10+s[i]-'0';
			else if(s[i]=='+'){ar[an++]=tmp; tmp=0;}
		}
		ar[an++]=tmp;
		sort(ar,ar+an);
		printf("%d",ar[0]);
		for(int i=1; i<an; ++i) printf("+%d",ar[i]);
		printf("\n");
	}
	return 0;
}
