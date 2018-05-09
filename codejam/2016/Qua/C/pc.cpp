#include <iostream>
#include <cstdio>
using namespace std;

int N,J,n,ans;
bool s[100];

void dfs(int dep){
	if(ans>=J) return;
	if(dep==n){
		string tmp="11";
		for(int i=0; i<n; ++i){
			if(s[i]) tmp="11"+tmp;
			else tmp="00"+tmp;
		}
		tmp="11"+tmp;
		cout << tmp;
		for(int i=2; i<=10; ++i) printf(" %d",i+1);
		puts("");
		++ans;
		return; 
	}
	s[dep] = 1;
	dfs(dep+1);
	s[dep] = 0;
	dfs(dep+1);
}

int main(){
	/* input */
	int T; scanf("%d",&T);
	scanf("%d%d",&N,&J);
	/* init */
	memset(s,false,sizeof(s));
	n=(N-4)>>1;
	ans=0;
	/* output */
	puts("Case #1:");
	dfs(0);
	return 0;
}

