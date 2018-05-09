#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

long long int ans[101];

int main(){
	int T; scanf("%d",&T);
	for(int Case=1; Case<=T; ++Case){
		int K,C,S; scanf("%d%d%d",&K,&C,&S);
		int possible = K-C+1 <=0 ? 1 : K-C+1;
		printf("Case #%d:",Case);
		if(S<possible)
			puts(" IMPOSSIBLE");
		else {
			for(int i=1; i<=possible; ++i) ans[i]=i;
			for(long long int i=K-1,sub=0; i>=possible; --i,sub=sub*K+1){
				for(int j=1; j<=possible; ++j)
					ans[j]=(ans[j]-sub)*K;
			}
			for(int i=1; i<=possible; ++i) printf(" %lld",ans[i]);
			puts("");
		}
	}
	return 0;
}
