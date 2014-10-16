#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int Now[110][110];
int Flow[110][110];
int Cap[110];
int Pre[110];
bool Visit[110];
bool Dfs(int,int);
int findFlow(int,int);

int main(){
	int M,B,D;
	while(scanf("%d",&N)!=EOF){
		memset(Flow,0,sizeof(Flow));
		memset(Now,0,sizeof(Now));
		Cap[0]=1e9; Cap[N+1]=1e9;
		for(int i=1; i<=N; ++i) scanf("%d",&Cap[i]);
		scanf("%d",&M);
		while(M--){
			int a,b,n; scanf("%d%d%d",&a,&b,&n);
			Flow[a][b]=n;
		}
		scanf("%d%d",&B,&D);
		while(B--){int b; scanf("%d",&b); Flow[0][b]=1e9;}
		while(D--){int d; scanf("%d",&d); Flow[d][N+1]=1e9;}
		int ans=0;
		while(true){
			memset(Visit,false,sizeof(Visit));
			if(!Dfs(0,N+1)) break;
			ans+=findFlow(0,N+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}

bool Dfs(int s,int t){
	Visit[s]=true;
	if(s==t) return true;
	for(int i=1; i<=N+1; ++i){
		if(Visit[i]) continue;
		if(Flow[s][i]-Now[s][i]>0 && Cap[i]-Now[s][i]>0 || Flow[s][i]-Now[i][s]>0 && Now[i][s]){
			Pre[i]=s; 
			if(Dfs(i,t)) return true;
		}
	}
	return false;
}

int findFlow(int s,int t){
	int f=1e9;
	for(int i=t; i!=s; i=Pre[i]){
		if(Cap[i]-Now[Pre[i]][i]>0)
			f=min(Flow[Pre[i]][i],min(f,Cap[i]-Now[Pre[i]][i]));
		else
			f=min(Flow[i][Pre[i]],min(f,Now[i][Pre[i]]));
	}
	for(int i=t; i!=s; i=Pre[i]){
		if(Cap[i]-Now[Pre[i]][i]>0) Now[Pre[i]][i]+=f;
		else Now[i][Pre[i]]-=f;
//		printf("%d %d\n",i,Pre[i],Now[i][Pre[i]]);
	}
	return f;
}

