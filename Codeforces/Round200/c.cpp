#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	long long int a,b,ans;
	cin >> a >> b;
	if(b>a){long long int tmp=a; a=b; b=tmp;}
	ans=a/b;
	while(b!=1){
		long long int tmp=a%b;
		a=b; b=tmp;
		ans+=a/b;
	}
	cout << ans << endl;
	return 0;
}
