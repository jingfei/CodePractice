#include <iostream>
#include <cstdio>
using namespace std;

struct Loc{
	int y,x;
};

int main(){
	int N;
	scanf("%d",&N);
	int r1,r2,m;
	struct Loc R1[101],R2[101],In[13][25];
	while(N--){
		scanf("%d%d%d",&r1,&r2,&m);
		for(int i=0; i<r1; ++i) scanf("%d%d",&R1[i].x,&R1[i].y);
		for(int i=0; i<r2; ++i) scanf("%d%d",&R2[i].x,&R2[i].y);
		for(int i=0; i<m; ++i){
			int n; scanf("%d",&n);
			for(int j=0; j<n; ++j) scanf("%d%d",&In[i][j].x,&In[i][j].y);
		}
	}
	return 0;
}
