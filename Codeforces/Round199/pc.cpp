#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int r,h,remain,ans;
	scanf("%d%d",&r,&h);
	ans=(h/r)*2;
	remain=h%r;
	double tmp=(double)remain+1.73205*(double)r/2.0;
	if(tmp>=(double)r) ans+=2;
	else if(tmp>=(double)r/2.0) ++ans;
	printf("%d\n",ans);
	return 0;
}

