#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int cap[210][210], flow[210][210];
bool visited[210];
int path[210];

bool DFS(int s, int t){
	if(s==t) return true;
	visited[s]=true;
	for(int i=0; i<=N*2+1; ++i){
		if(visited[i]) continue;
		if(cap[s][i]-flow[s][i]>0 || flow[i][s]>0){
			path[i]=s;
			if(DFS(i,t)) return true;
		}
	}
	return false;
}

int findFlow(int s, int t){
	int f=1e9+1;
	for(int i=t, pre; i!=s; i=path[i]){
		pre=path[i];
		if(cap[pre][i]-flow[pre][i]>0)
			f=min(f,cap[pre][i]-flow[pre][i]);
		else
			f=min(f,flow[i][pre]);
	}
	for(int i=t, pre; i!=s; i=path[i]){
		pre=path[i];
		if(cap[pre][i]-flow[pre][i]>0)
			flow[pre][i]+=f;
		else
			flow[i][pre]-=f;
	}
	return f;
}

int maxFlow(int s, int t){
	int ans=0;
	while(1){
		memset(visited,false,sizeof(visited));
		if(!DFS(s,t)) break;
		ans+=findFlow(s,t);
	}
	return ans;
}

int main(){
	while(scanf("%d",&N)!=EOF){
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		for(int i=1; i<=N; ++i) scanf("%d",&cap[i][i+N]);
		int M; scanf("%d",&M);
		while(M--){
			int i,j,C;
			scanf("%d%d%d",&i,&j,&C);
			cap[i+N][j]=C;
		}
		int B, D; scanf("%d%d",&B,&D);
		while(B--){ 
			int n; scanf("%d",&n);
			cap[0][n]=1e9;
		}
		while(D--){
			int n; scanf("%d",&n);
			cap[n+N][N*2+1]=1e9;
		}
		printf("%d\n",maxFlow(0,N*2+1));
	}
	return 0;
}

