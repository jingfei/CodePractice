#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Trie{
	int Child[26], isWord;
}Trie[1000000];
int Set[1000000];
int Find(int a){return a==Set[a]?Set[a]:Find(Set[a]);}

int main(){
	char a[15], b[15];
	memset(Trie,0,sizeof(Trie));
	int T_n=26;
	for(int i=0; i<300000; i++) Set[i]=i;
	int Sa=-1,Sb=-1;
	while(scanf("%s %s",a,b)!=EOF){
		if(strlen(a)==1){
			Trie[a[0]-'a'].isWord++;
			Sa=a[0]-'a';
		}
		else{
			int Pre=a[0]-'a';
			for(int i=1; i<strlen(a); i++){
				int tmp=a[i]-'a';
				if(Trie[Pre].Child[tmp]==0){
					Trie[Pre].Child[tmp]=T_n++;
					Pre=T_n-1;
				}
				else Pre=Trie[Pre].Child[tmp];
			}
			Trie[Pre].isWord++;
			Sa=Pre;
		}
		if(strlen(b)==1){
			Trie[b[0]-'a'].isWord++;
			Sb=b[0]-'a';
		}
		else{
			int Pre=b[0]-'a';
			for(int i=1; i<strlen(b); i++){
				int tmp=b[i]-'a';
				if(Trie[Pre].Child[tmp]==0){
					Trie[Pre].Child[tmp]=T_n++;
					Pre=T_n-1;
				}
				else Pre=Trie[Pre].Child[tmp];
			}
			Trie[Pre].isWord++;
			Sb=Pre;
		}
		Set[Find(Sb)]=Find(Sa);
	}
	if(Sa==-1){printf("Possible\n"); return 0;}
	int Ans=true;
	for(int i=0; i<T_n; i++) Set[i]=Find(Set[i]);
	int ss=Set[Sb], odd=0;
	for(int i=0; i<T_n; i++){
		if( (Trie[i].isWord)%2==1){ 
			odd++; 
			if(odd>2){ Ans=false;  break;} 
		}
		if(Trie[i].isWord>0 && Set[i]!=ss){Ans=false; break;}
	}
	if(odd==1) Ans=false;
	if(!Ans) printf("Impossible\n");
	else printf("Possible\n");
	return 0;
}
