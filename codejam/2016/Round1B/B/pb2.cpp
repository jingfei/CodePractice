#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

string C,J;
int len;
int minAbs=1e9;
int minC=1e9,minJ=1e9;
string rC,rJ;

int toDigit(string s){
	int res = 0, tmp=1;
	for(int i=len-1; i>=0; --i)
		res+=(s[i]-'0')*tmp, tmp*=10;
	return res;
}

void dfs(int c,int j){
	if(j==len){
		int nc=toDigit(C),nj=toDigit(J),r=nc-nj;
//		printf("%d %d\n",nc,nj);
		if(r<0) r=-r;
		if(r<minAbs){minAbs=r; minC=nc; minJ=nj; rC=C; rJ=J;}
		else if(r==minAbs){
			if(nc<minC){minC=nc; minJ=nj; rC=C; rJ=J;}
			else if(nc==minC && nj<minJ){ minJ=nj; rC=C; rJ=J; }
		}
		return;
	}
	if(c==len && J[j]=='?'){
		for(int i=0; i<10; ++i){ J[j]=i+'0'; dfs(c,j+1); }
		J[j]='?';
	}
	else if(c==len && J[j]!='?') dfs(c,j+1);
	else if(c!=len && C[c]=='?'){
		for(int i=0; i<10; ++i){ C[c]=i+'0'; dfs(c+1,j); }
		C[c]='?';
	}
	else dfs(c+1,j);
}

int main(){
	int T; scanf("%d",&T); getchar();
	for(int Case=1; Case<=T; ++Case){
		minAbs=1e9;
		minC=1e9,minJ=1e9;
		cin >> C >> J;
		len = C.length();
		dfs(0,0);
		printf("Case #%d:",Case);
		cout << " " << rC << " " << rJ << endl;
	}
	return 0;
}

