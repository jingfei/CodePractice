#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge{
	int a,b;
}E[1000010];
int en;
int Set[1000010];
int Rank[1000010];
int Find(int x){return x==Set[x]?x:Set[x]=Find(Set[x]);}

void Union(int a,int b){
	if(Rank[a]>Rank[b])
		Set[b]=a;
	else{
		Set[a]=b;
		if(Rank[a]==Rank[b])
			++Rank[b];
	}
}

int main(){
	int n; scanf("%d",&n);
	while(n--){
		int N,M,K; en=0;
		scanf("%d%d%d",&N,&M,&K);
		for(int i=0; i<M; ++i){
			int a,b;
			scanf("%d%d",&a,&b);
			E[en].a=a; E[en].b=b; ++en;
		}
		int Ans=0;
		for(int j=1; j<=N; ++j){
			for(int k=0; k<=N; ++k) Set[k]=k;
			memset(Rank,0,sizeof(Rank));
			for(int i=0; i<en; ++i){
				if(E[i].a==j || E[i].b==j) continue;
				Union(Find(E[i].a),Find(E[i].b));
			}
			int tmp=0;
			for(int i=1; i<=N; ++i)
				if(i==j || Set[i]!=Set[0]) ++tmp;
			if(tmp>=K) ++Ans;
		}
		printf("%d\n",Ans);
	}
	return 0;
}
/*
#define MAX_VERTEX 110 
bool graph[MAX_VERTEX][MAX_VERTEX]; 
int dfn[MAX_VERTEX], low[MAX_VERTEX], answer[MAX_VERTEX]; 
int deapth, ansc, Vnum, Enum; 
void dfnlow(int u, int v){ 
	‐‐u is the visiting point, v is the u's parent and w 
	  is u's child.‐‐
	int w; 
	bool yes=0; 
	int child=0; 
	dfn[u]=low[u]=deapth++; 
	for(w=0;w<MAX_VERTEX;w++) 
		if(graph[u][w]){ 
			if(dfn[w]<0) {    //w isn't visited. 
				dfnlow(w,u); 
				child++; 
				if(dfn[u]<=low[w])yes=1; 
				low[u]=(low[u]<low[w])?low[u]:low[w]; 
			} 
			else if(w!=v) //Back edge 
				low[u]=(low[u]<dfn[w])?low[u]:dfn[w]; 
		} 
	if((child>1||v>=0)&&yes)answer[ansc++]=u; 
} 
void initialization(){ 
	int i; 
	memset(graph,0,MAX_VERTEX*MAX_VERTEX*sizeof(bool)); 
	ansc = deapth = 0; 
	for(i=0;i<MAX_VERTEX;i++) dfn[i]=low[i]=‐1; 
} 
void FindCutVertex(){ 
	for(int i=0;i<MAX_VERTEX;i++) 
		if(dfn[i]==‐1) dfnlow(i,‐1); 
}*/ 
