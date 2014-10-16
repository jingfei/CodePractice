#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int All;
struct Ar{
	int Vote,index,Ans;
}ar[100];
int an;
bool cmpVote(struct Ar a,struct Ar b){return a.Vote<b.Vote;}
bool cmpIndex(struct Ar a,struct Ar b){return a.index<b.index;}
int Weight[1000010];

int main(){
	char s[100];
	while(scanf("%s",s)!=EOF){
		getchar();
		int Len = strlen(s);
		an=0; 
		int tmp=-1;
		for(int i=0; i<=Len; ++i){
			if(s[i]==' ' || i==Len){
				if(tmp==-1) All=tmp;
				else if(tmp!=0){ 
					ar[an].Vote=tmp;
					ar[an].Ans=0;
					ar[an].index=an++;
				}
				tmp=0;
			}
			else tmp=tmp*10+s[i]-'0';
		}
		sort(ar,ar+an,cmpVote);
		memset(Weight,0,sizeof(Weight));
		for(int k=0; k<ar; ++k){
			int Start = All-ar[k].Vote;
			int ans=0;
			for(int i=Start; i; --i)
				for(int j=0; j<ar; ++j){
					int Rest=i-ar[j].Vote;
					if(ar[j].Vote+Weight[Rest]>Weight[ar[j].Vote])
						Weight[ar[j].Vote]=ar[j].Vote+Weight[Rest];
				}

		}
	}
	return 0;
}
