#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n;
	char str[250];
	int A[105],B[105];
	while(scanf("%d",&n)!=EOF){
		scanf("%s",str);
		for(int i=0; i<n; i++) A[i]=str[i]-'0';
		for(int i=n; i<n*2; i++) B[i]=str[i+n]-'0';
		sort(A,A+n);
		sort(B,B+n);
		bool large=true, small=false;
		for(int i=0; i<n; i++)
			if(A[i]<=B[i]){
				large=false; break;
			} 
		if(!large){
			small=true;
			for(int i=0; i<n; i++)
				if(A[i]>=B[i]){
					small=false; break;
				}
		}
		if(large || small) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
