#include <iostream>
#include <cstdio>
using namespace std;

int ans;
void dfs(int n, int t){
	if(n==0){
		++ans; return;
	}
	else if(n<0) return;
	if(t==1) dfs(n,2);
	dfs(n-t,1);
}

int main(){
	int T; scanf("%d",&T);
	while(T--){
		int a; scanf("%d",&a);
		ans=0;
		dfs(a,1);
		printf("%d\n",ans);
	}
	return 0;
}
