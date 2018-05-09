#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
	int n,ans=1;
	scanf("%d",&n);
	int tmp,pre=-1;
	for(int i=0; i<n; ++i){
		scanf("%d",&tmp);
		if(pre==-1) pre=tmp;
		else if(pre!=tmp) ++ans;
		pre=tmp;
	}
	printf("%d\n",ans);
	return 0;
}
