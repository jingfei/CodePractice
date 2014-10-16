#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int A[30010],u[30010];
int M,N;
vector <int> ar;

int main(){
	int K; scanf("%d",&K);
	bool blank=false;
	while(K--){
		ar.clear();
		if(!blank) blank=true;
		else printf("\n");
		scanf("%d%d",&M,&N);
		for(int i=0; i<M; ++i) scanf("%d",&A[i]);
		for(int i=0; i<N; ++i) scanf("%d",&u[i]);
		vector <int>::iterator it;
		int i,j;
		for(i=0,j=0; i<M; ++i){
			it=lower_bound(ar.begin(),ar.end(),A[i]);
			ar.insert(it,A[i]);
			while(i+1==u[j]){
				printf("%d\n",ar[j++]);
				if(j==N) break;
			}
			if(j==N) break;
		}
		while(j<N)
			printf("%d\n",ar[j++]);
	}
	return 0;
}

