#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct edge{
	int a,b,w,next;
}e[50010*2];
bool Visit[20010];
int Dis[20010];
int first[20010];

int main(){
	int N;
	scanf("%d",&N);
	for(int Case=1; Case<=N; Case++){
		int n,m,S,T;
		scanf("%d%d%d%d",&n,&m,&S,&T);
		memset(Visit,false,sizeof(Visit));
		memset(first,-1,sizeof(first));
		int en=0;
		while(m--){
			int a,b,w;
			scanf("%d%d%d",&a,&b,&w);
			e[en].a=a; e[en].b=b; e[en].w=w; e[en].next=first[a];
			first[a]=en++;
			e[en].a=b; e[en].b=a; e[en].w=w; e[en].next=first[b];
			first[b]=en++;
		}
		queue <int> Q;
		Q.push(S);
		for(int i=0; i<n; i++) Dis[i]=1e9; 
		Dis[S]=0;
		while(!Q.empty()){
			int a=Q.front(); Q.pop();
			Visit[a]=false;
			for(int i=first[a]; i!=-1; i=e[i].next){
				int b=e[i].b;
				if(Dis[b]>e[i].w+Dis[a]){
					Dis[b]=Dis[a]+e[i].w;
					if(!Visit[b]){
						Visit[b]=true;
						Q.push(b);
					}
				}
			}	
		}
		if(Dis[T]==1e9) printf("Case #%d: unreachable\n",Case);
		else printf("Case #%d: %d\n",Case,Dis[T]);
	}
	return 0;
}
