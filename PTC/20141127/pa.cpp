#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N;
char arr[10][10];
int ch[100],chn;
int This[256];
int Start[100],End[100],sn,en;
int flow[100][100], cap[100][100], path[100];
bool visited[100];
int FordFulkerson(int s, int t);
int findFlow(int s, int t);
bool DFS(int k, int t);

int main(){
	int T; scanf("%d",&T);
	while(T--){
		chn=sn=en=0;
		memset(This,-1,sizeof(This));
		memset(flow,0,sizeof(flow));
		memset(cap,0,sizeof(cap));
		memset(visited,false,sizeof(visited));
		scanf("%d",&N); getchar();
		for(int i=0; i<N; ++i){
			for(int j=0; j<N; ++j){
				char tmp;
				tmp=getchar();
				if(!This[tmp]){
					This[tmp]=chn;
					ch[chn++]=tmp;
					Start[sn++]=i*N+j;
				}
				else
					End[en++]=i*N+j;

				if((j+1)%N!=0) cap[i*N+j][i*N+j+1]=cap[i*N+j+1][i*N+j]=1;
				if(j%N!=0) cap[i*N+j][i*N+j-1]=cap[i*N+j-1][i*N+j]=1;
				if((i+1)%N!=0) cap[i*N+j][(i+1)*N+j]=cap[(i+1)*N+j][i*N+j]=1;
				if(i%N!=0) cap[i*N+j][(i-1)*N+j]=cap[(i-1)*N+j][i*N+j]=1;
			}
			getchar();
		}
		printf("haha\n");
		for(int i=0; i<sn; ++i) cap[N*N][Start[i]]=100;
		for(int i=0; i<en; ++i) cap[End[i]][N*N+1]=100;
		int ans=FordFulkerson(N*N,N*N+1);
		printf("%d\n",ans);
	}
	return 0;
}

int FordFulkerson(int s, int t) {
	int ret = 0;
	while (1) {
		memset(visited, 0, sizeof(visited));
		if (!DFS(s, t))
			break;
			printf("%d %d %d\n",ret,s,t);
			ret += findFlow(s, t);
	}
	return ret;
}

bool DFS(int k, int t) {
	visited[k] = 1;
	if (k == t)
		return 1;
	int tmp[4],tn=0;
	int i=k/N, j=k%N;
	if((j+1)%N!=0) tmp[tn++]=i*N+j+1;
	if(j%N!=0) tmp[tn++]=i*N+j-1;
	if((i+1)%N!=0) tmp[tn++]=(i+1)*N+j;
	if(i%N!=0) tmp[tn++]=(i-1)*N+j;
	if(k==N*N) tn=sn;

		for (int l = 0; l < tn; ++l ) {
			int i=tmp[l];
			if(k==N*N) i=Start[l];
			if (visited[i])
				continue;
				if (cap[k][i] - flow[k][i] > 0 || flow[i][k] > 0) {
					path[i] = k;
					if (DFS(i, t))
						return 1;
				}
		}
		return 0;
}

int findFlow(int s, int t) {
	int f = 1e9;
	for (int i = t, pre; i != s; i = pre) {
		pre = path[i];
		if (cap[pre][i] - flow[pre][i] > 0)
			f = min(f, cap[pre][i] - flow[pre][i]);
			else
				f = min(f, flow[i][pre]);
	}
	for (int i = t, pre; i != s; i = pre) {
		pre = path[i];
		if (cap[pre][i] - flow[pre][i] > 0)
			flow[pre][i] += f;
			else
				flow[i][pre] -= f;
	}
	return f;
}

