#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int num[8], ar[1000], Num=0;

void BST(int n){
	int L=0, R=1000, mid=(L+R)>>1;
	while(L<R){
		if(
	}
}

void putnum(){
	string s;
	getline(cin,s); getchar();
	int Len=s.length(), tmp=-1;
	for(int i=0; i<Len; ++i){
		if(s[i]==' '){ 
			num[Num++]=tmp; 
			tmp=-1; 
			continue;
		}
		else if(tmp==-1) tmp=0;
		tmp=tmp*10+(s[i]-'0');
	}
	if(s[Len-1]!=' ') num[Num++]=tmp;
}

int main(int argc, char *argv[]){
	freopen(argv[1], "r", stdin);
	putnum();
	for(int i=0; i<1000; ++i) scanf("%d",&ar[i]);
	freopen(argv[2], "w", stdout);
	for(int i=0; i<Num; ++i)
		BST(num[i]);
	return 0;
}
