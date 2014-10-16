#include <iostream>
#include <cstdio>
using namespace std;

int R,C,M;
void Print(int K){
	if(K==1)
		for(int i=0; i<R; ++i){
			for(int j=0; j<C; ++j){
				if(M && (i<R-2 || j<C-2) ){ printf("*"); --M; }
				else if(i==R-1 && j==C-1) printf("c");
				else printf(".");
			}
			printf("\n");
		}
	else
		for(int i=0; i<R; ++i){
			for(int j=0; j<C; ++j){
				if(i==R-1 && j==C-1) printf("c");
				else if(M){printf("*"); --M;}
				else printf(".");
			}
			printf("\n");
		}
}

int main(){
	int T; scanf("%d",&T);
	for(int Case=1; Case<=T; ++Case){
		scanf("%d%d%d",&R,&C,&M);
		printf("Case #%d:\n",Case);
		if(R!=1 && C!=1 && R*C-M>=4 && R*C-M!=5) Print(1);
		else if(R!=1 && C!=1 && R*C-M==1 ) Print(2);
		else if(R==1 && R*C-M>=1) Print(2);
		else if(C==1 && R*C-M>=1) Print(2);
		else printf("Impossible\n");
	}
	return 0;
}
