#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	string s;
	cin >> s;
	int Len=s.length();
	double p,ans=0.0;
	scanf("%lf",&p);
	int n1=p*(double)Len;
	int c1=0,c0=0,cq=0;
	for(int i=0; i<Len; ++i){
		if(s[i]=='1') ++c1;
		else if(s[i]=='0') ++c0;
		else ++cq;
	}
	ans=(double)(n1-c1)*p;
	for(int i=0; i<cq; ++i) ans/=2.0;
	cq-=(n1-c1);
	ans+=(double)cq*(1-p);
	printf("%lf\n",ans);
	return 0;
}

