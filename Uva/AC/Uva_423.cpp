#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int ar[105][105];
int Dis[105];
bool Visit[105];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0; i<n; i++) ar[i][i]=0;
		for(int i=1; i<n; i++)
			for(int j=0; j<i; j++){
				char s[1000];
				getchar();
				scanf("%s",s);
				if(s[0]=='x') ar[j][i]=ar[i][j]=-1;
				else ar[j][i]=ar[i][j]=atoi(s);
			}
		memset(Visit,false,sizeof(Visit));
		for(int i=1; i<n; i++) Dis[i]=1e9;
		Dis[0]=0;
		queue <int> Q;
		Q.push(0);
		while(!Q.empty()){
			int t=Q.front(); Q.pop();
			Visit[t]=false;
			for(int i=0; i<n; i++){
				if(ar[t][i]!=-1 && Dis[i]>Dis[t]+ar[t][i]){
					Dis[i]=Dis[t]+ar[t][i];
					if(!Visit[i]){
						Visit[i]=true;
						Q.push(i);
					}
				}
			}
		}
		int Ans=0;
		for(int i=1; i<n; i++) Ans=max(Ans,Dis[i]);
		printf("%d\n",Ans);
	}
	return 0;
}
