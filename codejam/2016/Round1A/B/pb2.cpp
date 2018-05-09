#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int ar[2510];

int main(){
	int T; scanf("%d",&T); getchar();
	for(int Case=1; Case<=T; ++Case){
		int N; scanf("%d",&N);
		int tmp;
		memset(ar,0,sizeof(ar));
		for(int i=0; i<N*2-1; ++i)
			for(int j=0; j<N; ++j){
				scanf("%d",&tmp);
				++ar[tmp];
			}
		printf("Case #%d:",Case);
		for(int i=0; i<2510; ++i) if(ar[i]%2==1) printf(" %d",i);
		puts("");
	}
	return 0;
}
