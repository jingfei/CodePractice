#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Phone{
	int Len;
	char num[15];
	bool operator<(const Phone &t)const{
		return Len<t.Len;
	}
}Phone[1000010];

struct Trie{
	int Child[10];
}Trie[1000010];

bool App[10]; 

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(App,false,sizeof(App));
		bool Ans=true;
		int P_n=0;
		int n;
		scanf("%d",&n);
		for(int i=0; i<n; i++){
			char Num[15];
			scanf("%s",Num);
			Phone[P_n].Len=strlen(Num);
			strcpy(Phone[P_n].num,Num);
			P_n++;
		}
		int Div=0;
		int T=10;
		sort(Phone,Phone+P_n);
		memset(Trie,0,sizeof(Trie));
		for(int i=P_n-1; i>=0; i--){
			bool New=false;
			int len=strlen(Phone[i].num);
			if(len==1){
				int x=Phone[i].num[0]-'0';
				if(!App[x]){App[x]=true; New=true;}
				else {Ans=false; break;}
			}
			int Pre=Phone[i].num[0]-'0';
			App[Pre]=true;
			for(int j=1; j<len; j++){
				int x=Phone[i].num[j]-'0';
				if(Trie[Pre].Child[x]==0){
					New=true;
					Trie[Pre].Child[x]=T++;
					Pre=T-1;
				}
				else Pre=Trie[Pre].Child[x];
			}
			if(!New){ 
			//	printf("%s\n",Phone[i].num); 
				Ans=false;
			}
			if(!Ans)break;
		}
		if(Ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

bool Jud(char *a, char *b){
	int n2=strlen(b);
	for(int i=0; i<n2; i++){
		if(a[i]!=b[i]) return false;
	}
	return true;
}
