#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n,m;
int ans[110],an;
bool visit[110];
vector <int> ar[110];
void Dfs(int);

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && n+m){
		memset(visit,false,sizeof(visit));
		for(int i=1; i<=n; ++i) ar[i].clear();
		an=0;
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			ar[a].push_back(b);
		}
		for(int i=1; i<=n; ++i)
			if(!visit[i])
				Dfs(i);
		for(int i=an-1; i; --i)
			printf("%d ",ans[i]);
		printf("%d\n",ans[0]);
	}
	return 0;
}

void Dfs(int x){
	visit[x]=true;
	if(!ar[x].empty())
		for(vector <int>::iterator it=ar[x].begin(); it!=ar[x].end(); ++it)
			if(!visit[*it])
				Dfs(*it);
	ans[an++]=x;
}

