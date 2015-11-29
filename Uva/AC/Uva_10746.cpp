#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n,m,total;

int cap[70][70], flow[70][70], path[70];
double cost[70][70], dis[70];
bool inQue[70];

bool SPFA(int s,int t){
	queue <int> Q;
	memset(inQue,false,sizeof(inQue));
	for(int i=1; i<=total; ++i) dis[i]=1e9; dis[0]=0;
	Q.push(s);
	inQue[s]=true;
	while(!Q.empty()){
		int F=Q.front();
		Q.pop(); inQue[F]=false;
		for(int i=1; i<=total; ++i){
			if(flow[i][F]>0 && dis[i]>dis[F]-cost[i][F]){
				dis[i]=dis[F]-cost[i][F];
				path[i]=F;
				if(!inQue[i]){ inQue[i]=true; Q.push(i); }
			}
			else if(cap[F][i]-flow[F][i]>0 && dis[i]>dis[F]+cost[F][i]){
				dis[i]=dis[F]+cost[F][i];
				path[i]=F;
				if(!inQue[i]){ inQue[i]=true; Q.push(i); }
			}
		}
	}
	return dis[total]!=1e9;
}

void updateFlow(int s,int t){
	for(int i=t,pre; i!=s; i=pre){
		pre=path[i];
		--flow[i][pre];
		++flow[pre][i];
	}
}

double MCMF(int s,int t){
	double minCost=0;
	while(SPFA(s,t)){
		updateFlow(s,t);
		minCost+=dis[total];
	}
	return minCost;
}

int main(){
	while(scanf("%d%d",&n,&m) && n && m){
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(cost,0,sizeof(cost));
		total=m*2+n+1;
		for(int i=1; i<=m; ++i){
			cap[0][i]=cap[i][i+m]=1;
			for(int j=m*2+1,k=0; k<n; ++j,++k)
				cap[i+m][j]=1;
		}
		for(int j=m*2+1,k=0; k<n; ++j, ++k) cap[j][total]=1;
		for(int j=m*2+1,k=0; k<n; ++j, ++k)
			for(int i=1; i<=m; ++i)
				scanf("%lf",&cost[i+m][j]);
		printf("%.2f\n",MCMF(0,total)/n+0.000001);
	}
	return 0;
}

