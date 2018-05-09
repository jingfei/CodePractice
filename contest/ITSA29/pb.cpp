#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Tmp{
	int Kind;
	double w,p,R,e;
	bool operator<(const struct Tmp &t)const{
		return R>t.R;
	}
}ar[3];

bool cmp(const struct Tmp &a, const struct Tmp &b){
	return a.Kind<b.Kind;
}

int main(){
	double W,left,energy;
	while(scanf("%lf",&W)!=EOF){
		left = W;
		energy = 0;
		for(int i=0; i<3; ++i) scanf("%lf",&ar[i].w);
		for(int i=0; i<3; ++i){
			scanf("%lf",&ar[i].p);
			ar[i].Kind=i;
			ar[i].e=0;
			if(ar[i].w==0) ar[i].R=0;
			else ar[i].R=ar[i].p/ar[i].w;
		}
		sort(ar,ar+3);
		for(int i=0;i<3;++i){
			if(left>=ar[i].w){
				ar[i].e = ar[i].w;
				left -= ar[i].e;
				energy += (ar[i].e/ar[i].w)*ar[i].p;
			}
			else{
				ar[i].e = left;
				left -= ar[i].e;
				energy += (ar[i].e/ar[i].w)*ar[i].p;
				break;
			}
		}
		sort(ar,ar+3,cmp);  //sort by Kind
		printf("%.3f %.3f %.3f %.3f\n", ar[0].e, ar[1].e, ar[2].e, energy);
		
	}
	return 0;
}

