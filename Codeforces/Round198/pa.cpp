#include <iostream>
#include <cstdio>
using namespace std;

int GCD(int a,int b){
	if(a>b){int tmp=a; a=b; b=tmp;}
	while(a){
		int x=a;
		b%=a;
		a=b; b=x;
	}
	return b;
}

int main(){
	int x,y,a,b;
	scanf("%d%d%d%d",&x,&y,&a,&b);
	int G=x/GCD(x,y)*y;
	if(a%G==0) printf("%d\n",b/G-a/G+1);
	else printf("%d\n",b/G-a/G);
	return 0;
}

