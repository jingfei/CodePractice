#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector <int> V[100010];
int N;
int dfn[100010], low[100010], answer[100010]; 
int deapth, ansc, Vnum, Enum; 
void Dfnlow(int u, int v){ 
	/*‐‐u is the visiting point, v is the u's parent and w is u's child.‐‐*/
	int w; 
	bool yes=0; 
	int child=0; 
	dfn[u]=low[u]=deapth++; 
	int Size=V[u].size();
	for(w=0;w<Size;w++){ 
			if(dfn[V[u][w]]<0) {    //w isn't visited. 
				Dfnlow(V[u][w],u); 
				child++; 
				if(dfn[u]<=low[V[u][w]])yes=1; 
				low[u]=(low[u]<low[V[u][w]])?low[u]:low[V[u][w]]; 
			} 
			else if(V[u][w]!=v) //Back edge 
				low[u]=(low[u]<dfn[V[u][w]])?low[u]:dfn[V[u][w]]; 
	}
	if((child>1||v>=0)&&yes)answer[ansc++]=u; 
} 
void initialization(){ 
	ansc = deapth = 0; 
	memset(dfn,-1,sizeof(dfn));
	memset(low,-1,sizeof(low));
} 
void FindCutVertex(){ 
	for(int i=0;i<=N;i++) 
		if(dfn[i]==-1)
			Dfnlow(i,-1); 
} 

int main(){
	int n; scanf("%d",&n);
	while(n--){
		int M,K; scanf("%d%d%d",&N,&M,&K);
		for(int i=0; i<=M; ++i) V[M].clear();
		initialization();
		for(int i=0; i<M; ++i){
			int a,b;
			scanf("%d%d",&a,&b);
			V[a].push_back(b);
			V[b].push_back(a);
		}
		FindCutVertex();
		int ans=0;
		for(int i=0; i<=N; ++i) printf("%d %d %d\n",dfn[i],low[i],answer[i]); printf("\n");
		for(int i=1; i<=N; ++i) if(dfn[i]>=K) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}
