#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF && n){
		int ans=0;
		for(int i=n; i; --i){
			ans+=i*i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
