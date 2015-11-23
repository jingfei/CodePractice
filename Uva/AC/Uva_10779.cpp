#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m;
int cap[40][40], flow[40][40];
int path[40];
bool visited[40];

bool DFS(int s, int t){
	if(s==t) return true;
	visited[s]=true;
	for(int i=0; i<=n+m+1; ++i){
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
	int T; scanf("%d",&T);
	for(int Case=1; Case<=T; ++Case){
		scanf("%d%d",&n,&m);
		memset(flow,0,sizeof(flow));
		memset(cap,0,sizeof(cap));
		for(int i=0; i<n; ++i){
			int tmp; scanf("%d",&tmp);
			while(tmp--){
				int tmp2; scanf("%d",&tmp2);
				++cap[i+m+1][tmp2];
			}
		}
		for(int i=m+1; i<m+n+1; ++i){
			for(int j=1; j<=m; ++j)
				if(cap[i][j]==0) cap[j][i]=1;
				else if(i!=m+1) --cap[i][j];
		}
		for(int i=1; i<=m; ++i) cap[i][m+n+1]=1;
		printf("Case #%d: %d\n",Case,maxFlow(m+1,m+n+1));
	}
	return 0;
}
