#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;

struct Ar{
	int a,b;
	bool visit;
	bool operator<(const struct Ar &t)const{
		if(a==t.a) return b<t.b;
		return a<t.a;
	}
}ar[100];

void Dfs(int,int,int);
int an;
bool Ans;

int main(){
	while(scanf("%d",&n)!=EOF && n){
		Ans=false;
		scanf("%d",&m);
		int a,b,c,d;
		an=0;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for(int i=0; i<m; ++i){
			int y,x;
			scanf("%d%d",&y,&x);
			struct Ar tmp;
			tmp.a=y; tmp.b=x;
			tmp.visit=false;
			ar[an++]=tmp;
		}
		Dfs(b,c,0);
		if(Ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

void Dfs(int a,int b,int N){
	if(N>n || Ans) return;
	for(int i=0; i<an; ++i){
		if(ar[i].visit) continue;
		if(ar[i].a==a){
			if(ar[i].b==b && n==N+1){ Ans=true; break;}
			else{
				ar[i].visit=true;
				Dfs(ar[i].b,b,N+1);
				ar[i].visit=false;
			}
		}
		if(ar[i].b==a){
			if(ar[i].a==b && n==N+1){Ans=true; break;}
			else{
				ar[i].visit=true;
				Dfs(ar[i].a,b,N+1);
				ar[i].visit=false;
			}
		}
	}
}

