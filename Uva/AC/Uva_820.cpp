#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
int ar[110][110];
bool visited[110];
int flow[110][110];
int path[110];

bool DFS(int s, int t){
	if(s==t) return true;
	visited[s]=true;
	for(int i=1; i<=n; ++i){
		if(visited[i]) continue;
		if(ar[s][i]-flow[s][i]>0 || flow[i][s]>0){
			path[i]=s;
			if(DFS(i,t)) return true;
		}
	}
	return false;
}

int findFlow(int s, int t){
	int f=1e9;
	for(int i=t,pre; i!=s; i=path[i]){
		if(ar[path[i]][i]-flow[path[i]][i]>0)
			f=min(f,ar[path[i]][i]-flow[path[i]][i]);
		else
			f=min(f,flow[i][path[i]]);
	}
	for(int i=t; i!=s; i=path[i]){
		if(ar[path[i]][i]-flow[path[i]][i]>0)
			flow[path[i]][i]+=f;
		else
			flow[i][path[i]]-=f;
	}
	return f;
}

int MaxFlow(int s, int t){
	int ans=0;
	while(1){
		memset(visited,false,sizeof(visited));
		if(!DFS(s,t)) break;
		ans += findFlow(s,t);
	}
	return ans;
}

int main(){
	int Case=0;
	scanf("%d",&n);
	do{
		int s,t,c;
		memset(flow,0,sizeof(flow));
		memset(ar,0,sizeof(ar));
		scanf("%d%d%d",&s,&t,&c);
		while(c--){
			int a,b,dis;
			scanf("%d%d%d",&a,&b,&dis);
			ar[a][b]=ar[b][a]=dis+ar[a][b];
		}
		printf("Network %d\n",++Case);
		printf("The bandwidth is %d.\n\n",MaxFlow(s,t));
		scanf("%d",&n);
	}while(n);
	return 0;
}
