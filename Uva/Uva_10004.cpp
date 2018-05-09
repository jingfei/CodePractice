#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define Max 210
using namespace std;

int Color[Max];
struct ar{
	int a,b;
	bool operator<(const struct ar &t)const{
		if(t.a==a)return b<t.b;
		return a<t.a;
	}
}ar[Max];
bool Ans;
void Dfs(int,int);
int Edge;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF && n!=0){
		memset(Color,0,sizeof(Color));
		scanf("%d",&Edge);
		for(int i=0; i<Edge; i++){
			int a,b;
			scanf("%d%d",&a,&b);
			if(a>b){int tmp=a; a=b; b=tmp;}
			ar[i].a=a;
			ar[i].b=b;
		}
		sort(ar, ar+Edge);
		Ans=true;
		Dfs(0,1);
		if(!Ans){
			Ans=true;
			Dfs(0,2);
		}
		if(Ans) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}
	return 0;
}

void Dfs(int i,int c){
	if(!Ans) return;
	if(i+1>=Edge){Ans=true; return;}
	int A=ar[i].a, B=ar[i].b;
	int tmpA=Color[A], tmpB=Color[B];
	Color[A]=c;
	Color[B]=c%2+1;
	A=ar[i+1].a; B=ar[i+1].b;
	if(Color[A]==0 && Color[B]==0){
		Dfs(i+1,1);
		if(!Ans) Ans=true;
		else return;
		Dfs(i+1,2);
	}
	else if(Color[A]!=0 && Color[B]==0)
		Dfs(i+1,Color[A]);
	else if(Color[B]!=0 && Color[A]==0)
		Dfs(i+1,Color[B]%2+1);
	else{
		if(Color[A]==Color[B]){
			Ans=false;
			return;
		}
	}
	Color[A]=tmpA;
	Color[B]=tmpB;
}
