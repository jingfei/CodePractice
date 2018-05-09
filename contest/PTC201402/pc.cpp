#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Ar{
	int v;
	int py,px;
}ar[100][100];
struct XX{
	int y,x,Path;
	bool Get;
}X[5000];

int Min,tmpM;
bool Get;
queue <struct XX> Que;

void Bfs(int,int,int);
bool Check(int y,int x);
int R,C,xn;

int main(){
	freopen("testdata.in","r",stdin);
	char s[100],tmp;
	while(scanf("%d",&R)!=EOF && R!=0){
		while(!Que.empty())
			Que.pop();	
		xn=2;
		Min=1e9;
		scanf("%d",&C);
		scanf("%s",s); getchar(); 
		for(int i=0; i<R-2; ++i){
			getchar();
			for(int j=0; j<C-2; ++j){
				ar[i][j].px=-1;
				tmp=getchar();
				if(tmp=='X'){
					X[xn].Get=false;
					X[xn].Path=0;
					X[xn].y=i; X[xn].x=j;
					ar[i][j].v=xn++;
				}
				else if(tmp=='|' || tmp=='+' || tmp=='-') ar[i][j].v=0;
				else ar[i][j].v=1;
			}
			getchar(); getchar();
		}
		scanf("%s",s); getchar(); 
		/*
		for(int i=2; i<xn; ++i){
			printf("%d %d\n",X[i].y,X[i].x);
		}
		*//*
		for(int i=0; i<R-2; ++i){
			for(int j=0; j<C-2; ++j)
				printf("%d ",ar[i][j].v); printf("\n");
		}
		*/
		for(int i=2; i<xn; ++i){
			tmpM=0; Get=false;
			X[i].Get=true;
			Que.push(X[i]);
			printf("\n%d %d\n",X[i].y,X[i].x);
			while(!Que.empty()){
				struct XX Font=Que.front();
	//					printf(" Front: %d %d\n",Font.y,Font.x);
				Que.pop();
				Bfs(Font.y,Font.x,Font.Path);
			}
			for(int j=2; j<xn; ++j)
				if(!X[j].Get){
					printf("%d %d\n",X[j].y,X[j].x);
					X[j].Get=true; X[j].Path=0;
					Que.push(X[j]); Get=false;
					while(!Que.empty()){
						struct XX Font=Que.front();
	//					printf("Front: %d %d\n",Font.y,Font.x);
						Que.pop();
						Bfs(Font.y,Font.x,Font.Path);
					}
					if(!Get) break;
				}
			if(tmpM<Min && Get) Min=tmpM;
			for(int i=2; i<xn; ++i) X[i].Get=false;
			for(int j=0; j<R-2; ++j)
				for(int k=0; k<C-2; ++k){
					ar[j][k].px=-1;
					if(ar[j][k].v==-1) ar[j][k].v=1;
				}
		}
		printf("%d\n",Min);
	}
	return 0;
}

void Bfs(int y,int x,int Path){
	printf("Path: %d %d %d\n",Path,y,x);
	if(Que.empty() && Path!=0){
//		printf("Empty\n");
		return;
	}
	if(ar[y][x].v>1 && Path!=0){
		if(X[ar[y][x].v].Get) return;
		Get=true;
		tmpM+=Path;
		printf("%d %d\n",y,x);
		printf("tmpM: %d\n",tmpM);
		for(int i=0; i<R-2; ++i)
			for(int j=0; j<C-2; ++j)
				ar[i][j].px=-1;
		X[ar[y][x].v].Get=true;
		while(!Que.empty()) Que.pop();
		struct Ar t=ar[y][x];
		while(ar[t.py][t.px].v==1){
			ar[t.py][t.px].v=-1;
			ar[t.py][t.px].px=1;
			t=ar[t.py][t.px];
		}
		ar[t.py][t.px].v=-1;
		ar[t.py][t.px].px=1;
		return;
	}
	struct XX tmp;
	tmp.Path=Path+2;
	if(Check(y,x+2) && ar[y][x+2].v>=1){
		tmp.x=x+2; tmp.y=y; 
		ar[y][x+2].py=y; ar[y][x+2].px=x; 
		Que.push(tmp);
	}
	if(Check(y-2,x) && ar[y-2][x].v>=1){
		tmp.x=x; tmp.y=y-2;
		ar[y-2][x].py=y; ar[y-2][x].px=x;
		Que.push(tmp);
	}
	if(Check(y+2,x) && ar[y+2][x].v>=1){
		tmp.x=x; tmp.y=y+2;
		ar[y+2][x].py=y; ar[y+2][x].px=x;
		Que.push(tmp);
	}
	if(Check(y,x-2) && ar[y][x-2].v>=1){
		tmp.x=x-2; tmp.y=y;
		ar[y][x-2].py=y; ar[y][x-2].px=x;
		Que.push(tmp);
	}
}

bool Check(int y,int x){
	if(y<0 || x<0 || y>=R-2 || x>=C-2) return false;
	if(ar[y][x].v==0 || ar[y][x].px!=-1) return false;
	return true;
}

