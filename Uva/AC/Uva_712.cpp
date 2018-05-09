#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Ar{
	int b;
	int n;
	bool operator<(const struct Ar &t)const{
		return n<t.n;
	}
}ar[10000];
int seq[10000];

int main(){
	int n,m,Case=0;
	while(scanf("%d",&n)!=EOF && n!=0){
		char s[5000],tr[5000]; getchar();
		for(int i=0; i<n; ++i){
			scanf("%s",s); 
			seq[s[1]-'0']=i;
		}
		getchar(); 
		scanf("%s",tr); getchar();
		scanf("%d",&m); getchar();
		printf("S-Tree #%d:\n",++Case);
		while(m--){
			scanf("%s",s); getchar();
			int Len=strlen(s);
			for(int i=0; i<Len; ++i){
				ar[i].n=seq[i];
				ar[i].b=s[i]-'0';
			}
			sort(ar,ar+Len);
			int p=0;
			for(int i=0; i<Len; ++i){
				if(ar[i].b) p=p*2+1;
				else p*=2;
			}
			printf("%c",tr[p]);
		}
		printf("\n\n");
	}
	return 0;
}
