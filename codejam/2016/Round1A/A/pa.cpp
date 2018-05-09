#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int T; scanf("%d",&T); getchar();
	for(int Case=1; Case<=T; ++Case){
		char c,L,R; L=R=getchar();
		string s=""; s+=L;
		c=getchar();
		while(c!='\n'){
			if(c>=L){ s=c+s; L=c; }
			else{ s+=c; R=c; }
			c=getchar();
		}
		printf("Case #%d: ",Case);
		cout << s << endl;
	}
	return 0;
}
