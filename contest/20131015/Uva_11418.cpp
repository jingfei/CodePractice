#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct ar{
	bool used;
	int x; 
	struct ar2{
		int x1;
		char s[100000];
		bool operator<(const struct ar2 &t)const{
			return x1>t.x1;
		}
	}ar2[30];
/*	bool operator<(const struct ar &t)const{
		int i=x-1,i2=t.x-1;
		if(ar2[i].x1!=t.ar2[i2].x1) return ar2[i].x1<t.ar2[i2].x1;
		return ar2[0].x1<t.ar2[0].x1;
	}*/
}ar[30];
void Print(char *);
void Check(int,int);
int Find(int,int);

int main(){
	int N,n,k;
	scanf("%d",&N);
	for(int Case=1; Case<=N; ++Case){
		scanf("%d",&n);
		for(int i=0; i<n; ++i){
			scanf("%d",&k); ar[i].x=k; ar[i].used=false;
			for(int j=0; j<k; ++j){ 
				getchar(); scanf("%s",ar[i].ar2[j].s);
				ar[i].ar2[j].x1=(ar[i].ar2[j].s[0]>='A' && ar[i].ar2[j].s[0]<='Z'?ar[i].ar2[j].s[0]-'A':ar[i].ar2[j].s[0]-'a');
			}
			getchar();
			sort(ar[i].ar2,ar[i].ar2+k);
		}
		int p=-1;
		printf("Case #%d:\n",Case);
		for(int i=0; i<n; ++i){
			int I=Find(n,p);
			ar[I].used=true;
			int tmp=ar[I].x-1;
			p=ar[I].ar2[tmp].x1;
			Print(ar[I].ar2[tmp].s);
			Check(n,p);
		}
	}
	return 0;
}

int Find(int n,int p){
	++p;
	int tmp=30,fin;
	for(int i=0; i<n; ++i){
		if(ar[i].used) continue;
		int x=ar[i].x-1;
		if(ar[i].ar2[x].x1==p && ar[i].ar2[0].x1<tmp){fin=i; tmp=ar[i].ar2[0].x1;}
	}
	return fin;
}

void Check(int r,int p){
	for(int i=0; i<r; ++i){
		if(ar[i].used) continue;
		while(ar[i].ar2[ar[i].x-1].x1<=p && ar[i].x>0) --ar[i].x;
	}
}


void Print(char *t){
	if(t[0]>='a' && t[0]<='z') printf("%c",t[0]-('a'-'A'));
	else printf("%c",t[0]);
	int Len=strlen(t);
	for(int i=1; i<Len; ++i){
		if(t[i]>='A' && t[i]<='Z') printf("%c",t[i]+('a'-'A'));
		else printf("%c",t[i]);
	}
	printf("\n");
}

