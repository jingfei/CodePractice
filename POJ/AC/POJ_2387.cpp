#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int ar[1010];
struct Edge{
	int a,b,w;
}e[4010];

int main(){
	int T,N;
	scanf("%d%d",&T,&N);
	memset(ar,-1,sizeof(ar));
	int en=0;
	while(T--){
		int a,b,w; scanf("%d%d%d",&a,&b,&w);
		e[en].a=a; e[en].b=b; e[en++].w=w;
		e[en].b=a; e[en].a=b; e[en++].w=w;
	}
	ar[1]=0;
	for(int k=1; k<N; ++k)
	for(int i=0; i<en; ++i){
		int A=e[i].a, B=e[i].b, W=e[i].w;
		if(ar[A]==-1) continue;
		if(ar[B]==-1 || ar[B]>ar[A]+W)	
			ar[B]=ar[A]+W;
	}
	printf("%d\n",ar[N]);
	return 0;
}

