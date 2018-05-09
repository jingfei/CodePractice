#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	string a,b;
	while(cin>>a>>b){
		int lenA = a.length();
		int lenB = b.length();
		string c=a;
		for(int i=0; i<lenA; ++i) a[i]=c[lenA-1-i];
		c=b;
		for(int i=0; i<lenB; ++i) b[i]=c[lenB-1-i];
		c="";
		int maxLen = lenA > lenB ? lenA : lenB;
		for(int i=0; i<maxLen*2; ++i) c+='0';
		for(int i=0; i<lenA; ++i){
			for(int j=0; j<lenB; ++j){
				int tmp=(a[i]-'0')*(b[j]-'0')+(c[i+j]-'0');
				c[i+j]=(tmp%10)+'0';
				c[i+j+1]+=tmp/10;
			}
		}
		bool start=false;
		for(int i=c.length()-1; i>=0; --i){
			if(!start && c[i]=='0') continue;
			else start=true;
			printf("%c",c[i]);
		}
		if(!start) puts("0");
		else puts("");
	}
	return 0;
}
