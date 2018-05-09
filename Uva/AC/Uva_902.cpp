#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct Trie{
	int isWord;
	int Child[26];
};
vector <struct Trie> T;
int tn;

int main(){
	int n;
	string s;
	while(cin >> n >> s){
		T.clear();
		for(int i=0; i<26; ++i){
			struct Trie tmp;
			tmp.isWord=0;
			memset(tmp.Child, 0,sizeof(tmp.Child));
			T.push_back(tmp);
		}
		int Len=s.length();
		tn=26;
		int Ans=0; 
		string ans,tmp;
		bool begin=false;
		for(int i=0; i<=Len-n; ++i){
			tmp="";
			tmp+=s[i];
			int x=s[i]-'a';
			for(int j=i+1,tt=1; j<i+n; ++j,++tt){
				tmp+=s[j];
				int Next=s[j]-'a';
				if(!T[x].Child[Next]){
					T[x].Child[Next]=tn;
					x=tn++;
					struct Trie Tmp;
					Tmp.isWord=0;
					memset(Tmp.Child, 0,sizeof(Tmp.Child));
					T.push_back(Tmp);
				}
				else x=T[x].Child[Next];
			}
			++T[x].isWord;
			if(Ans<T[x].isWord){
				Ans=T[x].isWord;
				ans=tmp;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

