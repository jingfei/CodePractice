#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n;
int Cap[105][105];
int Flow[105][105];   
int rflow[105];
int pre[105];

int main(){
	int np,nc,m; char c;
	while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF){
		memset(Flow,0,sizeof(Flow));
		memset(Cap,0,sizeof(Cap));
		for(int i=0; i<m; i++){
			int u,v,z; 
			c=getchar(); while(c!='(') c=getchar();
			scanf("%d",&u); getchar();
			scanf("%d",&v); getchar();
			scanf("%d",&z);
			Cap[u+1][v+1]+=z;
		}
		for(int i=0; i<np; i++){
			int u,z;
			c=getchar(); while(c!='(') c=getchar();
			scanf("%d",&u); getchar();
			scanf("%d",&z);
			Cap[0][u+1]+=z;
		}
		for(int i=0; i<nc; i++){
			int u,z;
			c=getchar(); while(c!='(') c=getchar();
			scanf("%d",&u); getchar();
			scanf("%d",&z);
			Cap[u+1][n+1]+=z;
		}
		int Ans=0;
		while(1){  //maximum flow
			queue<int> q;
			memset(rflow,0,sizeof(rflow));  
			rflow[0] = 1e9;  
			q.push(0);  
			while(!q.empty()){  
				int u = q.front();  
				q.pop();
				for(int v = 0; v<n+2; v++){
					if(!rflow[v] && Cap[u][v] > Flow[u][v]){  
						rflow[v] = min(rflow[u],Cap[u][v]-Flow[u][v]);
						pre[v] = u;
						q.push(v);  
					}
				}
			}
			if(rflow[n+1]==0)  break;
			for(int u=n+1; u!=0; u=pre[u]){
				Flow[pre[u]][u]+=rflow[n+1];
				Flow[u][pre[u]]-=rflow[n+1];
			}
			Ans+=rflow[n+1];
		}
		printf("%d\n",Ans);
	}
	return 0;
}

