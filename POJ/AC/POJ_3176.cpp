#include <iostream>
#include <cstdio>
using namespace std;

long long int ar[500][500];

int main(){
	int N; scanf("%d",&N);
	scanf("%lld",&ar[0][0]);
	for(int i=1; i<N; ++i){
		scanf("%lld",&ar[i][0]);
		ar[i][0]+=ar[i-1][0];
		for(int j=1; j<i; ++j){
			scanf("%lld",&ar[i][j]);
			ar[i][j] += (ar[i-1][j-1]>ar[i-1][j]?ar[i-1][j-1]:ar[i-1][j]);
		}
		scanf("%lld",&ar[i][i]);
		ar[i][i]+=ar[i-1][i-1];
	}
	long long int Max=0;
	for(int i=0; i<N; ++i)
		if(ar[N-1][i]>Max) Max=ar[N-1][i];
	printf("%lld\n",Max);
	return 0;
}
