#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int N, M, D, K, remain;
long long int cap[110][110], flow[110][110], path[110], ar[110][110], dis[110];
bool visited[110];
vector <int> edge[110];

bool SPFA(int s, int t){
	for(int i=1; i<=N; ++i) dis[i]=1e9;
	dis[s]=0;
	memset(visited,false,sizeof(visited));
	queue <int> Que;
	Que.push(s); visited[s]=true;
	while(!Que.empty()){
		int top=Que.front();
		Que.pop();
		visited[top]=false;
		for(int i : edge[top]){
			if(flow[i][top]>0 && dis[i]>dis[top]-ar[i][top]){
				dis[i]=dis[top]-ar[i][top];
				path[i]=top;
				if(!visited[i]){ Que.push(i); visited[i]=true; }
			}
			else if(cap[top][i]-flow[top][i]>0 && dis[i]>dis[top]+ar[top][i]){
				dis[i]=dis[top]+ar[top][i];
				path[i]=top;
				if(!visited[i]){ Que.push(i); visited[i]=true; }
			}
		}
	}
	return dis[t]!=1e9;
}

long long int MCMF(int s, int t){
	long long int MaxFlow=0, MinCost=0;
	if(D==0){
		if(!remain) return 0;
		else{D=1; K=remain; remain=0;}
	}
	while(SPFA(s,t)){
		++MaxFlow;
		MinCost+=dis[t]*K;
		for(int i=t,pre; i!=s; i=pre){
			pre=path[i];
			++flow[pre][i];
			--flow[i][pre];
		}
		if(D==MaxFlow){
			if(!remain) return MinCost;
			else{++D; K=remain; remain=0;}
		}
	}
	return -1;
}

int main(){
	while(scanf("%d%d",&N,&M)!=EOF){
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(ar,0,sizeof(ar));
		for(int i=1; i<=N; ++i) edge[i].clear();
		for(int i=0; i<M; ++i){
			long long int a, b, c;  scanf("%lld%lld%lld",&a,&b,&c);
			edge[a].push_back(b);
			edge[b].push_back(a);
			cap[a][b]=cap[b][a]=1;
			ar[a][b]=ar[b][a]=c;
		}
		scanf("%d%d",&D,&K); 
		remain=D%K;
		D/=K;
		long long int ans=MCMF(1,N);
		if(ans==-1) printf("Impossible.\n");
		else printf("%lld\n",ans);
	}
	return 0;
}

