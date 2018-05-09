#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool digit[10];

bool checkAll(){
	for(int i=0; i<10; ++i) if(!digit[i]) return false;
	return true;
}

int main(){
	int T; scanf("%d",&T);
	for(int Case=1; Case<=T; ++Case){
		long long int N,i; scanf("%lld",&N);
		memset(digit,false,sizeof(digit));
		if(!N){ printf("Case #%d: INSOMNIA\n",Case); continue; }
		for(i=N; ; i+=N){
			long long int tmp=i;
			while(tmp){
				int right = tmp%10;
				tmp/=10;
				if(!digit[right]){
					digit[right] = true;
				}
			}
			if(checkAll()) break;
		}
		printf("Case #%d: %lld\n",Case,i);
	}
	return 0;
}
