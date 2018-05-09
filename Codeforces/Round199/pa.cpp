#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int ar[100000];
int ans[100000];
bool visit[100000],Find;
void Dfs(int ,int );

int main(){
	scanf("%d",&n);
	memset(visit,false,sizeof(visit));
	for(int i=0; i<n; ++i) scanf("%d",&ar[i]);
	sort(ar,ar+n);
	ans[0]=ar[n-1];
	visit[n-1]=true;
	Dfs(1,n-1);
	if(!Find) printf("-1\n");
	else{
		for(int i=n-1; i>=0; i-=3)
			printf("%d %d %d\n",ans[i],ans[i-1],ans[i-2]);
	}
	return 0;
}

void Dfs(int dep,int index){
	if(Find) return;
	if(dep%3==0){
		if(dep<n){
			for(int i=n-2; i>=0; --i)
				if(!visit[i]){
					visit[i]=true;
					ans[dep]=ar[i];
					Dfs(dep+1,i);
					if(Find)return;
					visit[i]=false;
					return;
				}
		}
		else Find=true;
		return;
	}
	for(int i=index-1; i>=0; --i){
		if(!visit[i] && ar[index]!=ar[i] && ar[index]%ar[i]==0){
			visit[i]=true;
			ans[dep]=ar[i];
			Dfs(dep+1,i);
			if(Find) return;
			visit[i]=false;
		}
	}
}

