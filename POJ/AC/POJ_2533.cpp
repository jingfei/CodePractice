#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int tmp[1010];

int main(){
	int N,n=0,a;
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&a);
		if(!n) tmp[n++]=a;
		else if(a>tmp[n-1]) tmp[n++]=a;
		else *lower_bound(tmp,tmp+n,a)=a;
	}
	printf("%d\n",n);
	return 0;
}
