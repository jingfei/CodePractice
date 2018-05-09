#include <iostream>
#include <cstdio>
using namespace std;

int exGcd(int a, int b, int &x, int &y){  
	if(b == 0){  
		x = 1;  y = 0;  
		return a;  
	}
	int r = exGcd(b, a % b, x, y);  
	int t = x;  
	x = y;  y = t - a / b * y;  
	return r;
}

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		int x,y,D;
		D=exGcd(a,b,x,y);
		printf("%d %d %d\n",x,y,D);
	}
	return 0;
}
