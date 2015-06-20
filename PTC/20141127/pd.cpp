#include <iostream>
#include <cstdio>
using namespace std;

int Nf,Np;
int arN[25][25];
double arP[25][25];

int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&Nf,&Np);
		for(int i=0; i<Nf; ++i)
			for(int j=0; j<Np; ++j)
				scanf("%d",&arN[i][j]);
		for(int i=0; i<Nf; ++i)
			for(int j=0; j<Np; ++j)
				scanf("%ld",&arP[i][j]);

	}
	return 0;
}
