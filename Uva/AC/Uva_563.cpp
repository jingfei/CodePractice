#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int X,Y,total;
int cap[6000][6000], flow[6000][6000], path[6000];
bool visited[6000];
vector <int> S,T;

void updateFlow(int s, int t) { 
	for (int i = t, pre; i != s; i = pre) {
		pre = path[i];
		if(cap[pre][i]-flow[pre][i]>0) ++flow[pre][i];
		else --flow[i][pre];
	}
}

bool DFS(int k, int t) {
	visited[k] = 1;
	if (k == t) return 1;
	vector <int> V;
	if(k==0) V=S;
	else if(k<total){
		V.push_back(k+total);
		int x=k%(X+2), y=k/(X+2);
		if(x<=X) V.push_back(k+1+total);
		if(x) V.push_back(k-1+total);
		if(y) V.push_back(k-X-2+total);
		if(y<=Y) V.push_back(k+X+2+total);
	}
	else{
		k-=total;
		V.push_back(k);
		V.push_back(total);
		int x=k%(X+2), y=k/(X+2);
		if(x<=X) V.push_back(k+1);
		if(x) V.push_back(k-1);
		if(y) V.push_back(k-X-2);
		if(y<=Y) V.push_back(k+X+2);
		k+=total;
	}
	for (int i : V) {
		if (visited[i]) continue;
		if (cap[k][i]-flow[k][i]>0 || flow[i][k]>0) {
			path[i] = k;
			if (DFS(i, t)) return 1;
		}
	}
	return 0;
}

int maxFlow(int s, int t){
	int ret = 0;
	while (1) {
		memset(visited, 0, sizeof(visited));
		if (!DFS(s, t)) break;
		updateFlow(s,t);
		++ret;
	}
	return ret;
}

int main(){
	int p; scanf("%d",&p);
	while(p--){
		int b; scanf("%d%d%d",&X,&Y,&b);
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		S.clear();
		total=(X+2)*(Y+2);
		for(int i=1; i<total; ++i){ 
			int x=i%(X+2), y=i/(X+2);
			if(x<=X) cap[i+total][i+1]=1;
			if(x) cap[i+total][i-1]=1;
			if(y) cap[i+total][i-X-2]=1;
			if(y<=Y) cap[i+total][i+X+2]=1;
			cap[i][i+total]=1;
		}
		for(int i=0; i<b; ++i){
			int x,y; scanf("%d%d",&x,&y);
			cap[0][y*(X+2)+x]=1;
			S.push_back(y*(X+2)+x);
		}
		for(int i=1,tmp=(Y+1)*(X+2)+1; i<=X; ++i,++tmp) 
			cap[i+total][total]=cap[tmp+total][total]=1;
		for(int i=X+2,tmp=i+X+1; tmp<total-1; i+=(X+2),tmp+=(X+2))
			cap[i+total][total]=cap[tmp+total][total]=1;
		if(b==maxFlow(0,total)) puts("possible");
		else puts("not possible");
	}
	return 0;
}
