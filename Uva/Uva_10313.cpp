#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long int Count[300][300]={0};

void Init(){
	Count[0][0]=1;
	for(int i=1; i<=300; ++i)
		for(int j=i; j<=300; ++j)
			for(int k=1; k<=j; ++k)
				Count[j][k]+=Count[j-i][k-1];
}

int main(){
	Init();
	char s[100];
	while(fgets(s,sizeof(s),stdin)!=0){
		int Len = strlen(s);
		int Limit1=-1,Limit2=-1,Max=-1,tmp=0;
		for(int i=0; i<Len; ++i){
			if(i==Len-1 || s[i]==' '){
				if(tmp==0) continue;
				if(Max==-1) Max=tmp;
				else if(Limit1==-1) Limit1=tmp;
				else Limit2=tmp;
				tmp=0;
			}
			else tmp=tmp*10+s[i]-'0';
		}
		if(Limit1==-1){Limit1=0; Limit2=Max;}
		else if(Limit2==-1) Limit2=Limit1;
		long long int Ans=0;
		for(int i=Limit1; i<=Limit2; ++i) Ans+=Count[Max][i];
		printf("%lld\n",Ans);
	}
	return 0;
}
