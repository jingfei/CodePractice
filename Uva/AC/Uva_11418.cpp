#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

string in[26][26];
int n, cap[60][60], flow[60][60], path[60];
bool visited[60];
string A[26];

bool DFS(int s, int t){
	if(s==t) return true;
	visited[s]=true;
	for(int i=0; i<=27+n; ++i){
		if(visited[i]) continue;
		if(cap[s][i]-flow[s][i]>0 || flow[i][s]>0){
			path[i]=s;
			if(DFS(i,t)) return true;
		}
	}
	return false;
}

int findFlow(int s, int t){
	int f=1e9+1;
	for(int i=t, pre; i!=s; i=path[i]){
		pre=path[i];
		if(cap[pre][i]-flow[pre][i]>0)
			f=min(f,cap[pre][i]-flow[pre][i]);
		else
			f=min(f,flow[i][pre]);
	}
	for(int i=t, pre; i!=s; i=path[i]){
		pre=path[i];
		if(cap[pre][i]-flow[pre][i]>0){
			flow[pre][i]+=f;
			if(i<26) A[i]=in[pre-26][i];
		}
		else
			flow[i][pre]-=f;
	}
	return f;
}

void maxFlow(int s, int t){
	while(1){
		memset(visited,false,sizeof(visited));
		if(!DFS(s,t)) break;
		findFlow(s,t);
	}
}

int main(){
	int N; scanf("%d",&N);
	for(int Case=1; Case<=N; ++Case){
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		scanf("%d",&n);
		for(int i=0; i<n; ++i){
			int tmp; scanf("%d",&tmp);
			while(tmp--){
				string s; cin >> s;
				int len=s.length();
				s[0]=toupper(s[0]);
				for(int j=1; j<len; ++j) s[j]=tolower(s[j]);
				in[i][s[0]-'A']=s;
				cap[26+i][s[0]-'A']=1;
			}
		}
		for(int i=0; i<n; ++i){ cap[i][26+n]=1; cap[27+n][26+i]=1; }
		maxFlow(27+n, 26+n);
		printf("Case #%d:\n",Case);
		for(int i=0; i<n; ++i) cout << A[i] << endl;
	}
	return 0;
}

