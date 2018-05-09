#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int K,C,M;
int ar[250][250];
int Flow[250][250];
int Cap[250][250];
int maxD,end;
bool Visit[250];
int pre[250];
void floyd();
int Binary(int L,int R);
bool canbe(int mid);
int Ford(int s,int t,int Min);
bool Dfs(int k,int t,int Min);
int findFlow(int s,int t);

int main(){
	scanf("%d%d%d",&K,&C,&M);
	maxD=0; end=K+C+1;
	memset(Flow,0,sizeof(Flow));
	memset(Cap,0,sizeof(Cap));
	for(int i=0; i<K+C; i++){
		for(int j=0; j<K+C; j++){
			scanf("%d",&ar[i][j]);
		}
	}
	floyd();
	for(int i=0; i<K+C; i++)
		for(int j=0; j<K+C; j++)
			if(ar[i][j]) Cap[i+1][j+1]=1;
	for(int i=K+1; i<=K+C; i++) Cap[0][i]=1;
	for(int i=1; i<=K; i++) Cap[i][end]=M;
	int ans=Binary(0,maxD);
	printf("%d\n",ans);
	return 0;	
}

void floyd(){
	for(int k=0; k<K+C; k++)
		for(int i=0; i<K+C; i++){
			if(ar[i][k]==0) continue;
			for(int j=0; j<K+C; j++){
				if(ar[k][j]==0) continue;
				if(ar[i][k]+ar[k][j]<ar[i][j]) ar[i][j]=ar[i][k]+ar[k][j];
				maxD=max(ar[i][j],maxD);
			}
		}
}

int Binary(int L,int R){
	int mid;
	while(L<R){
		mid=(L+R)>>1;
		if(canbe(mid)) R=mid;
		else L=mid+1;
	}
//	mid=(L+R)>>1;
	return R;
}

bool canbe(int mid){
	memset(Flow,0,sizeof(Flow));
	int tmp=Ford(0,end,mid);
//	printf("mid:%d Ford:%d\n",mid,tmp);
	if(tmp==C) return true;
	return false;
}

int Ford(int s,int t,int Min){
	int ret=0;
	while(true){
		memset(Visit,false,sizeof(Visit));
		if(!Dfs(s,t,Min)) break;
		ret+=findFlow(s,t);	
	}
	return ret;
}

bool Dfs(int k,int t,int Min){
	Visit[k]=true;
	if(k==t) return true;
	for(int i=1; i<=end; i++){
		if(Visit[i] || (k!=0 && i!=end && ar[k-1][i-1]>Min)) continue;
		if(Cap[k][i]-Flow[k][i]>0 || Flow[i][k]>0){
			pre[i]=k;
			if(Dfs(i,t,Min)) return true;
		}
	}
	return false;
}

int findFlow(int s,int t){
	int f=1e9;
	for(int i=t,Pre; i!=s; i=Pre){
		Pre=pre[i];
		if(Cap[Pre][i]-Flow[Pre][i]>0) f=min(f,Cap[Pre][i]-Flow[Pre][i]);
		else f=min(f,Flow[i][Pre]);
	}
	for(int i=t,Pre; i!=s; i=Pre){
		Pre=pre[i];
		if(Cap[Pre][i]-Flow[Pre][i]>0) Flow[Pre][i]+=f;
		else Flow[i][Pre]-=f;
	}
	return f;
}

