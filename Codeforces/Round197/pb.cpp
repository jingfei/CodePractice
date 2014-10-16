#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n,m,pre=1; long long int ans=0;
	scanf("%d%d",&n,&m);
	while(m--){
		int x; scanf("%d",&x);
		if(x>=pre) ans+=(x-pre);
		else ans+=(x+n-pre);
		pre=x;
	}
	cout << ans << endl;
	return 0;
}
