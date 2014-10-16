#include <iostream>
#include <cstdio>
using namespace std;

int Ans[8000]={0};
int Count[8000]={0};
int Coin[5]={1,5,10,25,50};
void Init(){
	Count[0]=1;
	for(int j=0; j<5; ++j)
		for(int i=Coin[j]; i<7490; ++i)
			Count[i]+=Count[i-Coin[j]];
}

int main(){
	Init();
	int n;
	while(scanf("%d",&n)!=EOF) printf("%d\n",Count[n]);
	return 0;
}
