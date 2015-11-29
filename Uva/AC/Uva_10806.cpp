#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, cap[110][110], flow[110][110], path[110], cost[110][110], dis[110];
bool inQueue[110];
vector <int> Edge[110];

int maxFlow, minCost;

bool SPFA(int s,int t){
	memset(inQueue,false,sizeof(false));
	for(int i=0; i<=n; ++i) dis[i]=1e9; dis[s]=0;
	queue <int> Q;
	Q.push(s); inQueue[s]=true;
	while(!Q.empty()){
		int F=Q.front();
		Q.pop(); inQueue[F]=false;
		for(int i : Edge[F]){
			if(flow[i][F]>0 && dis[i]>dis[F]-cost[F][i]){
				dis[i]=dis[F]-cost[F][i];
				path[i]=F;
				if(!inQueue[i]){ inQueue[i]=true; Q.push(i); }
			}
			else if(cap[F][i]-flow[F][i]>0 && dis[i]>dis[F]+cost[F][i]){
				dis[i]=dis[F]+cost[F][i];
				path[i]=F;
				if(!inQueue[i]){ inQueue[i]=true; Q.push(i); }
			}
		}
	}
	return dis[t]!=1e9;
}

void updateFlow(int s,int t){
	for(int i=t,pre; i!=s; i=pre){
		pre=path[i];
		++flow[pre][i];
		--flow[i][pre];
	}
}

void MCMF(int s,int t){
	while(SPFA(s,t)){
		updateFlow(s,t);
		++maxFlow;
		minCost+=dis[t];
	}
}

int main(){
	while(scanf("%d",&n)!=EOF && n){
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		maxFlow=minCost=0;
		for(int i=0; i<=n; ++i) Edge[i].clear();
		int m; scanf("%d",&m);
		cap[0][1]=2;
		Edge[0].push_back(1);
		while(m--){
			int a,b,s; scanf("%d%d%d",&a,&b,&s);
			cap[a][b]=cap[b][a]=1;
			Edge[a].push_back(b);
			Edge[b].push_back(a);
			cost[a][b]=cost[b][a]=s;
		}
		MCMF(0,n);
		if(maxFlow==2) printf("%d\n",minCost);
		else printf("Back to jail\n");
	}
	return 0;
}
