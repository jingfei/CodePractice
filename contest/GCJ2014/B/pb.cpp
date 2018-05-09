#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int T; scanf("%d",&T);
	for(int Case=1; Case<=T; ++Case){
		double C,F,X;
		scanf("%lf%lf%lf",&C,&F,&X);
		double Ans=0.0,Now=2.0;
		double Cookie=C/Now;
		while(Cookie+X/(F+Now)<X/Now){
			Ans+=Cookie;
			Now+=F;
			Cookie=C/Now;
		}
		printf("Case #%d: %.7lf\n",Case,Ans+X/Now);
	}
	return 0;
}
