#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int nk[30];
int peo[1010];
int Y,X;
bool ar[1010][1010];
bool vx[1010];
int Mx[1010][1010],Ans[1010][1010];

bool Augument(int y){
	for(int i=0; i<X; ++i){
		if(!ar[y][i]) continue;
//		printf("%d %d ",y,i);
//		ar[y][i]?printf("true\n"):printf("false\n");
		if(!vx[i]){
			vx[i]=true;
			if(peo[i]<nk[i]){
				Mx[i][peo[i]++]=y;
				return true;
			}
			for(int k=0; k<peo[i]; ++k)
				if(Augument(Mx[i][k])){
					Mx[i][k]=y;
					return true;
				}
		}
	}
	return false;
}

bool Matching(){
	for(int i=0; i<Y; ++i){
		memset(vx,false,sizeof(vx));
		Augument(i);
//		if(!Augument(i)){
//			return false;
//		}
	}
	return true;
}

int main(){
	while(scanf("%d%d",&X,&Y)!=EOF && !(Y==0 && X==0)){
		memset(ar,false,sizeof(ar));
		memset(peo,0,sizeof(peo));
		memset(Mx,0,sizeof(Mx));
		memset(Ans,0,sizeof(Ans));
		for(int i=0; i<X; ++i) scanf("%d",&nk[i]);
		for(int i=0; i<Y; ++i){
			int Num;
			scanf("%d",&Num);
			for(int j=0; j<Num; ++j){
				int tmp; scanf("%d",&tmp);
				ar[i][tmp-1]=true;
			}
		}
		Matching();
		int Match=true;
		for(int i=0; i<X; ++i) if(peo[i]!=nk[i]){Match=false;break;}
		if(!Match) printf("0\n");
		else{
			printf("1\n");
			for(int i=0; i<X; ++i){
				for(int j=0; j<peo[i]-1; ++j){
					printf("%d ",Mx[i][j]+1);
				}
				printf("%d\n",Mx[i][peo[i]-1]+1);
			}
//			printf("\n");
//			for(int i=0; i<Y; ++i){
//				for(int j=1; j<Ans[i][0]; ++j)
//					printf("%d ",Ans[i][j]);
//				printf("%d\n",Ans[i][Ans[i][0]]);
//			}
		}
	}
	return 0;
}

