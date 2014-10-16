#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool ar[1005][1005];
int N;
int Check(int);
bool Check2(int,int,int);

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		getchar();
		char tmp;
		for(int i=0; i<N; ++i){
			for(int j=0; j<N; ++j){
				scanf("%c",&tmp);
				ar[i][j]=(tmp=='o'?true:false);
			}
			getchar();
		}
		int ans=0;
		for(int i=N/3; i>=1; i--){
			ans=Check(i);
			if(ans){
				printf("%d %d\n",i,ans);
				break;
			}
		}
		if(!ans) printf("0 0\n");
	}
	return 0;
}

int Check(int n){
	int ans=0;
	for(int i=0; i<=N-3*n; ++i){
		if(i>N) break;
		for(int j=n; j<=N-2*n; ++j){
			if(j>N) break;
			bool Find=true;
			for(int k=j; k<j+n; k++)
				if(!ar[i][k] || k>N){ Find=false; break; }
			if(Find){
				if(Check2(i,j,n)) ans++;
			}
		}
	}
	return ans;
}

bool Check2(int y,int x,int n){
	for(int i=y; i<y+n; i++)
		for(int j=x; j<x+n; j++)
			if(!ar[i][j])return false;
	for(int i=y+n; i<y+2*n; i++)
		for(int j=x-n; j<x+2*n; j++)
			if(!ar[i][j]) return false;
	for(int i=y+2*n; i<y+3*n; i++)
		for(int j=x; j<x+n; j++)
			if(!ar[i][j]) return false;
	return true;
}

