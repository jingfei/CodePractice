#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct L{
	double y,x;
}ar[110];
int an;

double Dis(struct L a, struct L b){
	double X=a.x-b.x,Y=a.y-b.y;
	return X*X+Y*Y;
}

int main(){
	int n; an=1;
	double Path=0.0;
	struct L tmp;
	scanf("%d",&n);
	scanf("%lf%lf",&ar[0].y,&ar[0].x);
	while(scanf("%lf%lf",&tmp.y,&tmp.x)!=EOF){
		double Min=1e9;
		for(int i=0; i<an; ++i)
			Min=min(Min,Dis(tmp,ar[i]));
		Path+=sqrt(Min);
		ar[an++]=tmp;
	}
	printf("%.2lf\n",Path);
	return 0;
}

