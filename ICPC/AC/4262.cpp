#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool ar[1010][1010];
bool Visit[1010];
bool Visit2[1010];
int Que[1010],qn,N,ans;
void Dfs(int);
void Dfs2(int);

int main(){
	int Case;
	scanf("%d",&Case);
	while(Case--){
		int M;
		memset(ar,false,sizeof(ar));
		memset(Visit,false,sizeof(Visit));
		scanf("%d%d",&N,&M);
		if(N==0){int x; scanf("%d",&x); printf("0\n"); continue;}
		qn=0;
		while(M--){
			int a,b;
			scanf("%d%d",&a,&b);
			ar[a-1][b-1]=true;
		}
		int x; scanf("%d",&x);
		Dfs(0);
		ans=0;
		for(int i=0; i<N; ++i) 
			if(!Visit[i])
				Dfs(i);
		memset(Visit,false,sizeof(Visit));
		for(int i=N-1; i>=0; --i){
			if(!Visit[Que[i]]){
				++ans;
				Dfs2(Que[i]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

void Dfs(int x){
	Visit[x]=true;
	for(int i=0; i<N; ++i)
		if(ar[x][i] && !Visit[i])
			Dfs(i);
	Que[qn++]=x;
}

void Dfs2(int x){
	Visit[x]=true;
	for(int i=0; i<N; ++i)
		if(ar[i][x] && !Visit[i])
			Dfs2(i);
}

