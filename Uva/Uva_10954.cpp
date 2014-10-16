#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int ar[5010];
bool cmp(int a,int b){
	if(a>b) return 1;
	else return 0;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF && n!=0){
		long long int total=0;
		for(int i=0; i<n; ++i) scanf("%d",&ar[i]);
		sort(ar,ar+n,cmp);
		while(n>1){
			ar[n-2]+=ar[n-1];
			total+=ar[n-2];
			--n;
			sort(ar,ar+n,cmp);
//			for(int i=0; i<n; ++i) printf("%d ",ar[i]); printf("\n");
		}
		printf("%lld\n",total);
	}
	return 0;
}

