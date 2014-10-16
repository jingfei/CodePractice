#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int H[50010];
int FindMax(int,int);
int FindMin(int,int);

int main(){
	int N,Q;
	scanf("%d%d",&N,&Q);
	for(int i=0; i<N; ++i) scanf("%d",&H[i]);
	while(Q--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",FindMax(a-1,b-1)-FindMin(a-1,b-1));
	}
	return 0;
}

int FindMax(int a,int b){
	if(a==b) return H[a];
	if(a+1==b) return max(H[a],H[b]);
	int mid=(a+b)>>1;
	return max(FindMax(a,mid),FindMax(mid+1,b));
}

int FindMin(int a,int b){
	if(a==b) return H[a];
	if(a+1==b) return min(H[a],H[b]);
	int mid=(a+b)>>1;
	return min(FindMin(a,mid),FindMin(mid+1,b));
}

