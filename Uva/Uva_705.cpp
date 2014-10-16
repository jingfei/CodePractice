#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#define Max 80
using namespace std;

struct Loc{
	int y,x;
};

queue <struct Loc> Q;
int w,h;
bool Maze[Max*3][Max*3];
void Trans(int,int,char);
void Fill(int,int);
void Print();
int Count(int,int);
bool Check(int,int);

int main(){
	int Case=0;
	while(scanf("%d%d",&w,&h)!=EOF && !(w==0 && h==0)){
		memset(Maze,0,sizeof(Maze));
		char c;
		getchar();
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				scanf("%c",&c);
				Trans(i,j,c);
			}
			getchar();
		}
		for(int i=0; i<w*3; i++){
			if(!Maze[0][i]) Fill(0,i);
			if(!Maze[h*3-1][i]) Fill(h*3-1,i);
		}
		for(int i=0; i<h*3; i++){
			if(!Maze[i][0]) Fill(i,0);
			if(!Maze[i][w*3-1]) Fill(i,w*3-1);
		}
		int Cycle=0, Longest=0;
		for(int i=1; i<h*3-1; i++)
			for(int j=1; j<w*3-1; j++)
				if(!Maze[i][j]){
					int tmp=Count(i,j)/3;
					Longest=max(Longest,tmp);
					Cycle++;
				}
		printf("Maze #%d:\n",++Case);
		if(!Cycle)printf("There are no cycles.\n\n");
		else printf("%d Cycles; the longest has length %d.\n\n",Cycle,Longest);
	}
	return 0;
}

void Trans(int y,int x,char c){
	if(c=='/')
		Maze[y*3][x*3+2]=Maze[y*3+1][x*3+1]=Maze[y*3+2][x*3]=1;
	else if(c=='\\')
		Maze[y*3][x*3]=Maze[y*3+1][x*3+1]=Maze[y*3+2][x*3+2]=1;
}

void Fill(int y,int x){
	struct Loc F,tmp;
	tmp.y=y; tmp.x=x;
	if(!Q.empty())Q.pop();
	Q.push(tmp);
	while(!Q.empty()){
		F=Q.front();
		int Y=F.y, X=F.x;
		Maze[Y][X]=1;
		Q.pop();
		if(Check(Y+1,X) && !Maze[Y+1][X]){tmp.y=Y+1; tmp.x=X; Q.push(tmp);}
		if(Check(Y,X+1) && !Maze[Y][X+1]){tmp.y=Y; tmp.x=X+1; Q.push(tmp);}
		if(Check(Y-1,X) && !Maze[Y-1][X]){tmp.y=Y-1; tmp.x=X; Q.push(tmp);}
		if(Check(Y,X-1) && !Maze[Y][X-1]){tmp.y=Y; tmp.x=X-1; Q.push(tmp);}
	}
}

int Count(int y,int x){
	int ans=0;
	struct Loc F,tmp;
	tmp.y=y; tmp.x=x;
	if(!Q.empty())Q.pop();
	Q.push(tmp);
	while(!Q.empty()){
		F=Q.front();
		int Y=F.y, X=F.x; 
		if(Maze[Y][X]){Q.pop();  continue;}
		Maze[Y][X]=1; ans++;
		Q.pop();
		if(Check(Y+1,X) && !Maze[Y+1][X]){tmp.y=Y+1; tmp.x=X; Q.push(tmp);}
		if(Check(Y,X+1) && !Maze[Y][X+1]){tmp.y=Y; tmp.x=X+1; Q.push(tmp);}
		if(Check(Y-1,X) && !Maze[Y-1][X]){tmp.y=Y-1; tmp.x=X; Q.push(tmp);}
		if(Check(Y,X-1) && !Maze[Y][X-1]){tmp.y=Y; tmp.x=X-1; Q.push(tmp);}
	}
	return ans;
}

bool Check(int y,int x){
	if(y<0 || x<0 || y>=h*3 || x>=w*3) return false;
	return true;
}

void Print(){
	for(int i=0; i<h*3; i++){
		for(int j=0; j<w*3; j++)
			printf("%d",Maze[i][j]?1:0);
		printf("\n");
	}
	printf("\n");
}
