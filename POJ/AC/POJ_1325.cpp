#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int Y,X,k;
int mx[110],my[110];
bool vx[110];
bool ar[110][110];
int Aug(int y){
	for(int j=0; j<X; ++j){
		if(ar[y][j] && !vx[j]){
			vx[j]=true;
			if(mx[j]==-1 || Aug(mx[j])){
				mx[j]=y;
				my[y]=j;
				return true;
			}
		}
	}
	return false;
}

int Aug2(int x){
	for(int j=0; j<Y; ++j){
		if(ar[j][x] && !vx[j]){
			vx[j]=true;
			if(mx[j]==-1 || Aug2(mx[j])){
				mx[j]=x;
				my[x]=j;
				return true;
			}
		}
	}
	return false;
}

int Matching(){
	int match=0;
	for(int i=0; i<Y; ++i)
		if(my[i]==-1){
			memset(vx,false,sizeof(vx));
			if(Aug(i)) ++match;
		}
	return match;
//	memset(my,-1,sizeof(my));
//	memset(mx,-1,sizeof(mx));
//	int match2=0;
//	for(int i=0; i<X; ++i)
//		if(my[i]==-1){
//			memset(vx,false,sizeof(vx));
//			if(Aug2(i)) ++match2;
//		}
//	printf("%d %d\n",match,match2);
//	return match>match2?match:match2;
}

int main(){
	while(scanf("%d",&Y)!=EOF && Y){
		scanf("%d%d",&X,&k);
		memset(ar,false,sizeof(ar));
		for(int i=0; i<k; ++i){
			int a,b,c; scanf("%d%d%d",&a,&b,&c);
			if(!b || !c) continue;
			ar[b][c]=true;
		}
		memset(mx,-1,sizeof(mx));
		memset(my,-1,sizeof(my));
		printf("%d\n",Matching());
	}
	return 0;
}
