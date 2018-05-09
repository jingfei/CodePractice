#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

map <char,int> Size;
void mapInit(){
	Size.insert(pair<char,int>('S',0));
	Size.insert(pair<char,int>('M',1));
	Size.insert(pair<char,int>('L',2));
	Size.insert(pair<char,int>('X',3));
	Size.insert(pair<char,int>('T',4));
}
//S M L X T (0 1 2 3 4)

struct edge{
	int v,next;
}e[100];
int first[100];
int limit[5];
int Mx[100][100];
int y[100];
bool vx[100];
int Cloth[5];
int Matching();
bool Augument(int y);
int en,n;

int main(){
	mapInit();
	char end[100]="ENDOFINPUT";
	char s[100];
	while(scanf("%s",s)!=EOF && strcmp(end,s)){
		en=0;
		memset(first,-1,sizeof(first));
		memset(limit,0,sizeof(limit));
		scanf("%d",&n);
		for(int i=0; i<n; i++){
			char a,b; int A,B;
			getchar();
			scanf("%c%c",&a,&b);
			A=Size.find(a)->second; B=Size.find(b)->second;
			for(int j=A; j<=B; j++){
				e[en].v=j; e[en].next=first[i]; first[i]=en++;
				limit[j]++;
			}
		}
		for(int i=0; i<5; i++){
			scanf("%d",&Cloth[i]);
			limit[i]=min(limit[i],Cloth[i]);
		}
		getchar();
		scanf("%s",s);
		getchar();
		int ans=Matching();
		if(ans==n) printf("T-shirts rock!\n");
		else printf("I'd rather not wear a shirt anyway...\n");
	}
	return 0;
}

int Matching(){
	int match=0;
	memset(y,0,sizeof(y));
	for(int i=0; i<n; i++){
		memset(vx,false,sizeof(vx));
		if(!Augument(i)) return false;
		match++;
	}
	return match;
}

bool Augument(int Y){
	for(int x=first[Y]; x!=-1; x=e[x].next){
		int i=e[x].v;
		if(!vx[i]){
			vx[i]=true;
			if(y[i]<limit[i]){
				Mx[i][y[i]++]=Y;
				return true;
			}
			for(int k=0; k<y[i]; k++)
				if(Augument(Mx[i][k])){
					Mx[i][k]=Y;
					return true;
				}
		}
	}
	return false;
}

