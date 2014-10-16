#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int Y,X,dis,match;
int mx[105],my[105];
bool vx[105];
bool ar[105][105];
double tmp[105][2];

bool Aug(int y){
	for(int j=0; j<X; ++j)
		if(ar[y][j] && !vx[j]){
			vx[j]=true;
			if(mx[j]==-1 || Aug(mx[j])){
				mx[j]=y;
				my[y]=j;
				return true;
			}
		}
	return false;
}

int Matching(){
	for(int i=0; i<Y; ++i)
		if(my[i]==-1){
			memset(vx,false,sizeof(vx));
			if(Aug(i)) ++match;
		}
	return match;
}

int main(){
	int v,s;
	while(scanf("%d%d%d%d",&Y,&X,&s,&v)!=EOF){
		memset(mx,-1,sizeof(mx));
		memset(my,-1,sizeof(my));
		memset(ar,false,sizeof(ar));
		dis=s*v;
		for(int i=0; i<Y; ++i) scanf("%lf%lf",&tmp[i][0],&tmp[i][1]);
		for(int i=0; i<X; ++i){
			double a,b; scanf("%lf%lf",&a,&b);
			for(int j=0; j<Y; ++j){
				double tmpA=tmp[j][0]-a, tmpB=tmp[j][1]-b;
				if(tmpA*tmpA+tmpB*tmpB<=(double)dis*dis) ar[j][i]=true;
			}
		}
		match=0;
		Matching();
		printf("%d\n",Y-match);
	}
	return 0;
}
