#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,F,E,Fighting;
char ar[55][55];
char Ar[55][55];
bool fight;
void Find(int y,int x);
void Trace(int y,int x, char Goal, int Sele);
bool Check(int y,int x);

int main(){
	while(scanf("%d",&n)!=EOF && n!=0){
		Fighting=0;
		getchar();
		int Sec=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%c",&ar[i][j]);
				Ar[i][j]=ar[i][j];
				if(Ar[i][j]!='.' && Ar[i][j]!='*')Ar[i][j]='*';
			}
			getchar();
		}
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(Ar[i][j]!='.'){
					F=0; E=0;
					Find(i,j);
					if(F!=0 || E!=0){
						printf("Sector #%d: ",++Sec);
						printf("contain %d freedom fighter group(s) & %d enemy group(s)\n",F,E);
					}
				}
		printf("Total %d group(s) are in fighting position.\n",Fighting);
		printf("\n");
/*		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)
				printf("%c",ar[i][j]);
			printf("\n");
		}
*/	}
	return 0;
}

void Find(int y,int x){
	if(ar[y][x]=='p'){Ar[y][x]='.';}
	else if(ar[y][x]=='x'){Ar[y][x]='.';}
	else if(ar[y][x]=='b'){Ar[y][x]='.';}
	else if(ar[y][x]=='*'){Ar[y][x]=ar[y][x]='.';}
	else if(ar[y][x]=='P'){Trace(y,x,'P',1); E++;}
	else if(ar[y][x]=='X'){Trace(y,x,'X',1); E++;}
	else if(ar[y][x]=='B'){fight=false; Trace(y,x,'B',1); F++;}

	if(Check(y+1,x) && Ar[y+1][x]!='.')Find(y+1,x);
	if(Check(y,x+1) && Ar[y][x+1]!='.')Find(y,x+1);
	if(Check(y-1,x) && Ar[y-1][x]!='.')Find(y-1,x);
	if(Check(y,x-1) && Ar[y][x-1]!='.')Find(y,x-1);
}

void Trace(int y,int x,char Goal,int Sele){
	if(Sele==1)ar[y][x]=Goal+('a'-'A');
	else if(Sele==2) ar[y][x]=Goal+('X'-'P');

	if(Check(y+1,x) && ar[y+1][x]==Goal) Trace(y+1,x,Goal,Sele);
	if(Check(y,x+1) && ar[y][x+1]==Goal) Trace(y,x+1,Goal,Sele);
	if(Check(y-1,x) && ar[y-1][x]==Goal) Trace(y-1,x,Goal,Sele);
	if(Check(y,x-1) && ar[y][x-1]==Goal) Trace(y,x-1,Goal,Sele);
	
	if(!fight && Goal=='B'){
		if(Check(y+1,x) && (ar[y+1][x]=='p' || ar[y+1][x]=='P')){
			fight=true; Fighting++;
			Trace(y+1,x,ar[y+1][x],2);
			Fighting++;
		}
		else if(Check(y,x+1) && (ar[y][x+1]=='p' || ar[y][x+1]=='P')){ 
			fight=true; Fighting++;
			Trace(y,x+1,ar[y][x+1],2);
			Fighting++;
		}
		else if(Check(y-1,x) && (ar[y-1][x]=='p' || ar[y-1][x]=='P')){ 
			fight=true; Fighting++;
			Trace(y-1,x,ar[y-1][x],2);
			Fighting++;
		}
		else if(Check(y,x-1) && (ar[y][x-1]=='p' || ar[y][x-1]=='P')){ 
			fight=true; Fighting++;
			Trace(y,x-1,ar[y][x-1],2);
			Fighting++;
		} 
		else if(Check(y,x-1) && (ar[y][x-1]=='x' || ar[y][x-1]=='X')){
			fight=true; Fighting++;}
		else if(Check(y,x-1) && (ar[y][x-1]=='x' || ar[y][x-1]=='X')) {
			fight=true; Fighting++;}
		else if(Check(y,x-1) && (ar[y][x-1]=='x' || ar[y][x-1]=='X')) {
			fight=true; Fighting++;}
		else if(Check(y,x-1) && (ar[y][x-1]=='x' || ar[y][x-1]=='X')){ 
			fight=true; Fighting++;}
	}
}

bool Check(int y,int x){
	if(y<0 || x<0 || y>=n || x>=n)return false;
	return true;
}
