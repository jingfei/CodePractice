#include <iostream>
#include <cstdio>
using namespace std;

int n; double ans;

struct Loc{
	int x,y;
}L[350],Ans[4];

double Area(struct Loc a,struct Loc b,struct Loc c,struct Loc d){
//	printf("%d %d\n%d %d\n%d %d\n%d %d\n",a.x,a.y,b.x,b.y,c.x,c.y,d.x,d.y);
	int tmp1=(a.x*b.y+b.x*c.y+c.x*a.y)-(a.y*b.x+b.y*c.x+c.y*a.x);
	int tmp2=(a.x*b.y+b.x*d.y+d.x*a.y)-(a.y*b.x+b.y*d.x+d.y*a.x);
	if(tmp1<0) tmp1*=(-1);
	if(tmp2<0) tmp2*=(-1);
	return (double)(tmp1+tmp2)/2.0;
}

void Dfs(int dep,int index);

int main(){
	ans=0.0;
	scanf("%d",&n);
	for(int i=0; i<n; ++i)
		scanf("%d%d",&L[i].x,&L[i].y);
	Dfs(0,0); 
	printf("%lf\n",ans); 
	return 0;
}

bool Check(struct Loc a,struct Loc b,struct Loc c,struct Loc d){
	int xAB=b.x-a.x, yAB=b.y-a.y, xAC=c.x-a.x, yAC=c.y-a.y, xAD=d.x-a.x, yAD=d.y-a.y;
	if((xAB*yAC-xAC*yAB)*(xAB*yAD-xAD*yAB)>=0)
		return true; //ab, cd 不相交
	else return false;
}

void Dfs(int dep,int index){
	if(dep==4){
		double tmp;
		if(Check(Ans[0],Ans[1],Ans[2],Ans[3])){
//			printf("True\n");
			tmp=Area(Ans[0],Ans[2],Ans[1],Ans[3]);
		}
		else{
//			printf("False\n");
			tmp=Area(Ans[0],Ans[1],Ans[2],Ans[3]);
		}
		if(tmp>ans) ans=tmp;
		return;
	}
	for(int i=index; i<n; ++i){
		Ans[dep]=L[i];
		Dfs(dep+1,i+1);
	}
}

