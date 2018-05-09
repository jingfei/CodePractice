#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int s, Min;
struct Ar{
	int time;
	int g, gtime;
}ar[1010][1010];
int N[1010];

void Dfs(int na,int nb,int nc,int nd){
	if(nd==nb && nc>=na){
		Min=min(na-5, Min);
		return;
	}
	for(int i=1; i<=s; ++i){
		if(ar[nb][i].time<na) continue;
		Dfs(ar[nb][i].gtime+5, ar[nb][i].g, nc, nd);
	}
}

int Change(int b, int a){
	int bb=b%100, aa=a%100;
	int bbb=b/100, aaa=a/100;
	int ans=0;
	if(bb-aa<0){ ans=bb+60-aa; --bbb; }
	else ans=bb-aa;
	ans+=(bbb-aaa)*60;
	return ans;
}

int main(){
	int t; scanf("%d",&t);
	for(int Case=1; Case<=t; ++Case){
		scanf("%d",&s);
		Min=1e9;
		memset(N,0,sizeof(N));
		memset(ar,0,sizeof(ar));
		int train; scanf("%d",&train);
		for(int i=0; i<train; ++i){
			int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
			if(ar[b][d].g!=d || ar[b][d].gtime>c){
				ar[b][d].time=a;
				ar[b][d].g=d;
				ar[b][d].gtime=c;
			}
		}
		int na,nb,nc,nd; scanf("%d%d%d%d",&na,&nb,&nc,&nd);
		Dfs(na,nb,nc,nd);
		printf("%d\n",Case);
		if(Min==1e9)
			printf("no connection\n");
		else
			printf("%.4d %d\n",Min,Change(Min,na));
	}
	return 0;
}
