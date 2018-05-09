#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[1000010];
int pi[1000010];
void Find(int,int);

int main(){
	while(scanf("%s",s)!=EOF && strcmp(s,".")){
		getchar();
		int Len=strlen(s);
		int q=-1; pi[0]=0; int n=0,ans=0;
		for(int i=1; i<Len; ++i){
			if(s[q+1]==s[i]){
				pi[i]=++n; ++q;
				if(s[0]==s[i]){
					bool Same=true;
					for(int j=i-n-1,k=0; j<i; ++j,++k)
						if(s[j]!=s[k+i]){ Same=false; break; }
					if(Same) ans=n-1;
				}
			}
			else if(n==0) pi[i]=0;
			else{
				ans=0; n=0; q=-1;
			}
		}
		printf("n:%d\n",n);
//		printf("Max:%d\n",Max);
//		if(n==0) p=1;
//		else if(p==-1){p=Len-n; p=Len/p;}
//		else{p-=Max; p=Len/p;}
		if(!ans) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}

