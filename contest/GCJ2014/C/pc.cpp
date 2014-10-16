#include <iostream>
#include <cstdio>
using namespace std;

char ar[110][110];

void Place(int R,int C,int M,int y,int x){
	if(R<C && M>R*R){
		for(int i=y; i<R+y; ++i)
			for(int j=x; j<R+x; ++j)
				ar[i][j]='*';
		Place(R,C-R,M-R*R,R+y,R+x)
		return;
	}
	if(R>=C && M>C*C){
		for(int i=y; i<C+y; ++i)
			for(int j=x; j<C+x; ++j)
				ar[i][j]='*';
		Place(R-C,C,M-R*R,C+y,C+x)
		return;
	}
	if(R<C){
		Remain=M%R; int ReLine=C-(M/R);
		if(Remain && ReLine>1) Forb=1+R;
		else if(C>1 && ReLine==1) Forb=R-Remain;
		else if(C==1 && ReLine==1) Forb=M?1:0;
		else if(!Remain) Forb=M?R:0;
		if(C*R-M-Forb){
			for(int i=0; i<R; ++i){
				for(int j=0; j<C; ++j){
					if(j<M/R) printf("*");
					else if(j==M/R && i<Remain) printf("*");
					else if(i==R-1 && j==C-1) printf("c");
					else printf(".");
				}
				printf("\n");
			}
		}
		else printf("Impossible\n");
	}
	else{
		Remain=M%C; int ReLine=R-(M/C);
		if(Remain && ReLine>1) Forb=1+C;
		else if(R>1 && ReLine==1) Forb=C-Remain;
		else if(R==1 && ReLine==1) Forb=M?1:0;
		else if(!Remain) Forb=M?C:0;
		if(C*R-M-Forb){
			for(int i=0; i<R; ++i){
				for(int j=0; j<C; ++j){
					if(i<M/C) printf("*");
					else if(i==M/C && j<Remain) printf("*");
					else if(i==R-1 && j==C-1) printf("c");
					else printf(".");
				}
				printf("\n");
			}
		}
		else printf("Impossible\n");
	}
}

int main(){
	int T; scanf("%d",&T);
	for(int Case=1; Case<=T; ++Case){
		int R,C,M;
		scanf("%d%d%d",&R,&C,&M);
		int Remain,Forb=0;
		printf("Case #%d:\n",Case);
		Place(R,C,M,0,0);
	}
	return 0;
}

