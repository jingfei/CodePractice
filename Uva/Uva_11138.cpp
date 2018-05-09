#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

struct ar{
	int x,y;
}ar[510];

queue <struct ar> que;
int nuts,bolts;
int fits[505][505];
int Judge[505][505];

void read_input_data(void){
	int n,b;
	scanf("%d%d",&bolts,&nuts);
	for(b=0;b<bolts;b++)
		for(n=0;n<nuts;n++)
			scanf("%d",&fits[b][n]);
}

bool Check(int y, int x){
	if(y>=bolts || x>=nuts)return false;
	return true;
}

int match_bolt(int Y,int X){
	int Max=1;
	memset(Judge,0,sizeof(Judge));
	while(!que.empty())que.pop();
	struct ar tmp;
	tmp.x=X; tmp.y=Y;
	que.push(tmp);
	Judge[Y][X]=1;
	while(!que.empty()){
		struct ar F=que.front();
		int y=F.y, x=F.x;
		que.pop();
		if(Check(y+1,x) && fits[y+1][x]==1 && Judge[y][x]>=Judge[y+1][x]){
			Judge[y+1][x]=Judge[y][x]+1;
			Max=max(Max,Judge[y+1][x]);
			tmp.x=x; tmp.y=y+1;
			que.push(tmp);
		}
		if(Check(y+1,x+1) && fits[y+1][x+1]==1 && Judge[y][x]>=Judge[y+1][x+1]){
			Judge[y+1][x+1]=Judge[y][x]+1;
			Max=max(Max,Judge[y+1][x+1]);
			tmp.x=x+1; tmp.y=y+1;
			que.push(tmp);
		}
		if(Check(y,x+1) && fits[y][x+1]==1 && Judge[y][x]>=Judge[y][x+1]){
			Judge[y][x+1]=Judge[y][x]+1;
			Max=max(Max,Judge[y][x+1]);
			tmp.x=x+1; tmp.y=y;
			que.push(tmp);
		}
	}
	return Max;
}

int main(){
	int cases,caseno;
    scanf("%d",&cases);
    for(caseno=1;caseno<=cases;caseno++){
	    int Max=0;
		read_input_data();
		for(int i=0; i<nuts; i++)
  	  		if(fits[0][i])
				Max=max(match_bolt(0,i),Max);
    	printf("Case %d: ",caseno);
	    printf("a maximum of %d nuts and bolts ",Max);
	    printf("can be fitted together\n");
	}
	return 0;
}
