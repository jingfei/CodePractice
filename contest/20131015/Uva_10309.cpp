#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
	
int Ans;
char ar[10][10];
bool Tmp[10][10];
bool T[10];
void Back(int,int);
int Trace(int);

int main(){
	char s[100];
	while(scanf("%s",s)!=EOF && strcmp(s,"end")){
		Ans=1e9; getchar();
		memset(T,false,sizeof(T));
		for(int i=0; i<10; ++i){scanf("%s",ar[i]); getchar();}
		Back(0,0);
		printf("%s %d\n",s,Ans);
	}
	return 0;
}

void Press(int t,int y,int x){
	if(t==1){
		ar[y][x]=(ar[y][x]=='#'?'O':'#');
		if(y-1>=0) ar[y-1][x]=(ar[y-1][x]=='#'?'O':'#');
		if(x-1>=0) ar[y][x-1]=(ar[y][x-1]=='#'?'O':'#');
		if(x+1<10) ar[y][x+1]=(ar[y][x+1]=='#'?'O':'#');
		if(y+1<10) ar[y+1][x]=(ar[y+1][x]=='#'?'O':'#');
	}
	else{
		Tmp[y][x]=(Tmp[y][x]?0:1);
		if(y-1>=0) 	Tmp[y-1][x]=(Tmp[y-1][x]?0:1);
		if(x-1>=0)	Tmp[y][x-1]=(Tmp[y][x-1]?0:1);
		if(x+1<10)	Tmp[y][x+1]=(Tmp[y][x+1]?0:1);
		if(y+1<10)	Tmp[y+1][x]=(Tmp[y+1][x]?0:1);
	}
}

void Back(int dep,int ans){
	if(dep==10){
		 Ans=min(Ans,Trace(ans));
		return;
	}
	T[dep]=1; ++ans;
	Press(1,0,dep);
	Back(dep+1,ans);
	T[dep]=0; --ans;
	Press(1,0,dep);
	Back(dep+1,ans);
}

int Trace(int ans){
	for(int i=0; i<10; ++i)
		for(int j=0; j<10; ++j)
			Tmp[i][j]=(ar[i][j]=='#'?0:1);
	for(int i=1; i<10; ++i)
		for(int j=0; j<10; ++j)
			if(Tmp[i-1][j]){ Press(0,i,j); ++ans;}
	for(int i=0; i<10; ++i) if(Tmp[9][i]) return 1e9;
	return ans;
}

