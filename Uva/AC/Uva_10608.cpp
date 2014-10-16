#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N,M;
int ar[30010],Rank[30010];
int Uni(int x){return ar[x]==x?x:ar[x]=Uni(ar[x]);}
void Find(int a,int b){
	a=Uni(a); b=Uni(b);
	if(a==b) return;
	if(Rank[a]>Rank[b]){
		ar[a]=b;
	}
	else{
		ar[b]=a;
		if(Rank[a]==Rank[b])
			++Rank[b];
	}
}

int main(){
	int K; scanf("%d",&K);
	while(K--){
		scanf("%d%d",&N,&M);
		memset(Rank,0,sizeof(Rank));
		for(int i=1; i<=N; ++i)
			ar[i]=i;
		while(M--){
			int a,b;
			scanf("%d%d",&a,&b);
			Find(a,b);
		}
		int Visit[30010]={0};
		int Count=0;
		for(int i=1; i<=N; ++i){
			ar[i]=Uni(ar[i]);
			++Visit[ar[i]];
		}
		for(int i=1; i<=N; ++i)
			if(Visit[i]>Count)
				Count=Visit[i];
		printf("%d\n",Count);
	}
	return 0;
}
