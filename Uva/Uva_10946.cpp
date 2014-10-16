#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Letter{
	char Name;
	int Num;
	bool operator<(const struct Letter &t)const{
		if(Num==t.Num) return Name<t.Name;
		return Num>t.Num;
	}
}Letter[3600];

int h,w,Letter_n,Count;
char ar[60][60];
int Dfs(int y,int x,char Name);
bool Check(int y,int x);

int main(){
	int Case=0;
	while(scanf("%d%d",&h,&w)!=EOF && !(w==0 && h==0)){
		Letter_n=0;
		getchar();
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++)
				scanf("%c",&ar[i][j]);
			getchar();
		}
		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
				if(ar[i][j]!='.'){
					Letter[Letter_n].Name=ar[i][j];
					Count=0;
					Dfs(i,j,ar[i][j]);
					Letter[Letter_n++].Num=Count;
				}
		sort(Letter, Letter+Letter_n);
		printf("Problem %d:\n",++Case);
		for(int i=0; i<Letter_n; i++)
			printf("%c %d\n",Letter[i].Name,Letter[i].Num);
	}
	return 0;
}

int Dfs(int y,int x,char Name){
	Count++;
	ar[y][x]='.';
	if(Check(y+1,x) && ar[y+1][x]==Name)Dfs(y+1,x,Name);
	if(Check(y,x+1) && ar[y][x+1]==Name)Dfs(y,x+1,Name);
	if(Check(y-1,x) && ar[y-1][x]==Name)Dfs(y-1,x,Name);
	if(Check(y,x-1) && ar[y][x-1]==Name)Dfs(y,x-1,Name);
}

bool Check(int y,int x){
	if(y>=h || x>=w || y<0 || x<0)return false;
	return true;
}
