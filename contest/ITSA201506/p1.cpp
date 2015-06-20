#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int T; scanf("%d",&T);
	while(T--){
		long long int a;
		scanf("%lld",&a);
		printf("%lld\n",a);
		while(a!=1){
			if(a%2==0) a/=2;
			else a=a*3+1;
			printf("%lld\n",a);
		}
	}
	return 0;
}
