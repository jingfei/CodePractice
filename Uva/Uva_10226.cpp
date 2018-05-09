#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int Change(char);
char Change2(int);
void Trace(int,string);
int Num;
struct Trie{
	int isWord;
	int Child[53];
};
vector <struct Trie> T;

int main(){
	int Case;
	bool blank=false;
	scanf("%d",&Case);
	getchar(); getchar();
	char s[100];
	while(Case--){
		T.clear();
		if(!blank) blank=true;
		else printf("\n");
		int tn=53;
		Num=0;
		for(int i=0; i<53; ++i){
			struct Trie Tmp;
			Tmp.isWord=0;
			memset(Tmp.Child,0,sizeof(Tmp.Child));
			T.push_back(Tmp);
		}
		while(fgets(s,sizeof(s),stdin)!=0 && strcmp("\n",s)){
			int Len=strlen(s)-1;
			int x=Change(s[0]);
//			printf("x:%d\n",x);
			for(int i=1; i<Len; ++i){
				int Next=Change(s[i]);
				if(T[x].Child[Next]) x=T[x].Child[Next];
				else{
					T[x].Child[Next]=tn;
					x=tn++;
					struct Trie Tmp;
					Tmp.isWord=0;
					memset(Tmp.Child,0,sizeof(Tmp.Child));
					T.push_back(Tmp);
				}
			}
			++T[x].isWord;
			++Num;
		}
		for(int i=0; i<53; ++i){
			string tmp=""; tmp+=Change2(i);
			for(int j=0; j<53; ++j)
				if(T[i].Child[j]){
					tmp+=Change2(j);
//					cout << tmp << endl;
					Trace(T[i].Child[j],tmp);
				}
		}
	}
	return 0;
}

int Change(char c){
	if(c==' ') return 0;
	if(c>='A' && c<='Z') return c-'A'+1;
	return c-'a'+27;
}

char Change2(int i){
	if(i==0) return ' ';
	if(i<27) return 'A'+i-1;
	return 'a'+i-27;
}

void Trace(int x,string S){
	if(T[x].isWord){
		cout << S;
		printf(" %.4lf\n",T[x].isWord*100.0/Num);
	}
	for(int i=0; i<53; ++i){
		if(T[x].Child[i]){
			S+=Change2(i);
			Trace(T[x].Child[i],S);
		}
	}
}

