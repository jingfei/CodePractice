#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int ar[10010],tmp[10010],LIS[10010],LDS[10010];
void Lis(int,int*);

int main(){
	int n,ans;
	while(scanf("%d",&n)!=EOF){
		ans=0;
		for(int i=0; i<n; ++i) scanf("%d",&ar[i]);
		Lis(n,LIS);
		reverse(ar,ar+n);
		Lis(n,LDS);
		reverse(LDS,LDS+n);
		for(int i=0; i<n; ++i){
			int Min=LIS[i]<LDS[i]?LIS[i]:LDS[i];
			Min=Min*2-1;
			if(Min>ans) ans=Min;
		}
		printf("%d\n",ans);
	}
	return 0;
}

void Lis(int x,int *L){
	int n=0;
	for(int i=0; i<x; ++i){
		if(!n) tmp[n++]=ar[i];
		else if(ar[i]>tmp[n-1]) tmp[n++]=ar[i];
		else *lower_bound(tmp,tmp+n,ar[i])=ar[i];
		L[i]=n;
	}
}

