#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int ar[100];

int main(){
	int T; scanf("%d",&T); getchar();
	for(int Case=1; Case<=T; ++Case){
		int n=0;
		while(1){
			char c=getchar();
			if(c=='+') ar[n++]=1;
			else if(c=='-') ar[n++]=0;
			else break;
		}
		int flip=0;
		for(int i=n-1; i>=0; --i){
			if(flip%2==0 && !ar[i]) ++flip;
			else if(flip%2==1 && ar[i]) ++flip;
		}
		printf("Case #%d: %d\n",Case,flip);
	}
	return 0;
}
