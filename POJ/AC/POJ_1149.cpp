#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int Pigs[1010];
int VisitP[1010];
int Flow[1010][1010];
int Cap[1010][1010];
int pre[1010];
bool Visit[1010];
int Ford(int s,int t);
bool Dfs(int k,int t);
int findFlow(int s,int t);
int p;

int main(){
	int M,N;
	memset(VisitP,-1,sizeof(VisitP));
	memset(Flow,0,sizeof(Flow));
	memset(Cap,0,sizeof(Cap));
	scanf("%d%d",&M,&N);
	p=N+1;
	for(int i=0; i<M; i++) scanf("%d",&Pigs[i]);
	for(int i=1; i<=N; i++){
		int n,t=0;
		scanf("%d",&n);
		while(n--){
			int key;
			scanf("%d",&key);
			if(VisitP[key-1]==-1){
				VisitP[key-1]=i;
				t+=Pigs[key-1];
			}
			else{
				Cap[VisitP[key-1]][i]=1e9;
				VisitP[key-1]=i;
			}
		}
		Cap[0][i]=t;
		scanf("%d",&t);
		Cap[i][p]=t;
	}
	int ans=Ford(0,p);
	printf("%d\n",ans);
	return 0;
}

int Ford(int s,int t){
	int ret=0;
	while(1){
		memset(Visit,false,sizeof(Visit));
		if(!Dfs(s,t)) break;
		ret+=findFlow(s,t);
	}
	return ret;
}

bool Dfs(int k,int t){
	Visit[k]=true;
	if(k==t) return true;
	for(int i=1; i<=p; i++){
		if(Visit[i]) continue;
		if(Cap[k][i]-Flow[k][i]>0 || Flow[i][k]>0){
			pre[i]=k;
			if(Dfs(i,t)) return true;
		}
	}
	return false;
}

int findFlow(int s,int t){
	int f=1e9;
	for(int i=t,Pre; i!=s; i=Pre){
		Pre=pre[i];
		if(Cap[Pre][i]-Flow[Pre][i]>0) f=min(f,Cap[Pre][i]-Flow[Pre][i]);
		else f=min(f,Flow[i][Pre]);
	}
	for(int i=t,Pre; i!=s; i=Pre){
		Pre=pre[i];
		if(Cap[Pre][i]-Flow[Pre][i]>0) Flow[Pre][i]+=f;
		else Flow[i][Pre]-=f;
	}
	return f;
}

