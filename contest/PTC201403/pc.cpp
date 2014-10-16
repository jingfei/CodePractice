#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int ar[50][50];
bool Visit[50];
int Dis[50],n;
bool Find;
void Dfs(int);

int main(){
	while(scanf("%d",&n)!=EOF && n!=0){
		memset(Visit,false,sizeof(Visit));
		Find=false;
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				scanf("%d",&ar[i][j]);
		for(int i=0; i<n; ++i){
			if(!Visit[i]){
				memset(Dis,0,sizeof(Dis));
				Dis[i]=1;
				Dfs(i);
			}
			if(Find) break;
		}
		if(Find) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}

void Dfs(int x){
	if(Find) return;
//	Visit[x]=true;
	for(int i=0; i<n; ++i){
		if(ar[x][i] && Dis[i] && Dis[i]-Dis[x]==3){
//			printf("%d -> %d\n",i,x);
			Find=true;
			break;
		}
		else if(!Dis[i] && ar[x][i]){
			Dis[i]=Dis[x]+1;
			Dfs(i);
		}
	}
}


