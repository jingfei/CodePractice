#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define PI 3.1415926
using namespace std;

struct Dot{
	int x,y;
}D[1010];

struct Dot Ans[1010];
bool Check(struct Dot,struct Dot,struct Dot);

int main(){
	int N,M; int an=2;
	scanf("%d%d",&N,&M);
	for(int i=0; i<N; ++i)
		scanf("%d%d",&D[i].x,&D[i].y);
	Ans[0]=D[0]; Ans[1]=D[1];
	for(int i=2; i<N; ++i){
		struct Dot A=Ans[an-2],B=Ans[an-1],C=D[i];
		if(!Check(A,B,C)) Ans[an-1]=C;
		else Ans[an++]=C;
	}
//	for(int i=0; i<an; ++i) printf("%d %d\n",Ans[i].x,Ans[i].y);
	double ans=0;
	for(int i=1; i<an; ++i){
		int X=Ans[i].x-Ans[i-1].x,Y=Ans[i].y-Ans[i-1].y;
		ans+=sqrt((double)X*X+Y*Y);
	}
	int X=Ans[an-1].x-Ans[0].x,Y=Ans[an-1].y-Ans[0].y;
	ans+=sqrt((double)X*X+Y*Y);
	ans+=PI*2*M;
	printf("%.0f\n",ans);
	return 0;
}

bool Check(struct Dot A,struct Dot B,struct Dot C){
	int x1=B.x-A.x,x2=C.x-A.x,y1=B.y-A.y,y2=C.y-A.y;
//	printf("%d\n",x1*y2-x2*y1);
	if(x1*y2-x2*y1>0) return false;
	return true;
}

