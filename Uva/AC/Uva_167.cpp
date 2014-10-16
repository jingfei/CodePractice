#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ar[8][8];
bool my[8],mx[8],ma[15],mb[15];
int Max;
void Back(int,int);

int main(){
	int k;
	scanf("%d",&k);
	while(k--){
		Max=0;
		memset(my,false,sizeof(my));
		memset(mb,false,sizeof(ma));
		memset(ma,false,sizeof(ma));
		memset(mx,false,sizeof(my));
		for(int i=0; i<8; ++i)
			for(int j=0; j<8; ++j)
				scanf("%d",&ar[i][j]);
		for(int i=0; i<8; ++i){
			my[0]=true; mx[i]=true; ma[0+i]=true; mb[7-0+i]=true;
			Back(1,ar[0][i]);
			my[0]=false; mx[i]=false; ma[0+i]=false; mb[7-0+i]=false;
		}
		printf("%5d\n",Max);
	}
	return 0;
}

void Back(int y,int Now){
	if(y==8){
		Max=max(Max,Now);
		return ;
	}
	for(int i=0; i<8; ++i){
		if(mx[i] || ma[y+i] || mb[7-y+i]) continue;
		my[y]=true; mx[i]=true; ma[y+i]=true; mb[7-y+i]=true;
		Back(y+1,Now+ar[y][i]);
		my[y]=false; mx[i]=false; ma[y+i]=false; mb[7-y+i]=false;
	}
}

