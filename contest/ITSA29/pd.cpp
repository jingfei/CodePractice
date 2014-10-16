#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ar1[100],ar2[100],ar3[100];
bool Card[4][13];

int main(){
	int a,b;
	while(scanf("%d",&a)!=EOF){
		memset(Card,false,sizeof(Card));
		for(int i=0; i<a; ++i) scanf("%d",&ar1[i]);
		scanf("%d",&b);
		for(int i=0; i<b; ++i) scanf("%d",&ar2[i]);
		sort(ar2,ar2+b);
		for(int i=0; i<a; ++i){
			int x=ar1[i]/13, y=ar1[i]%13;
			Card[x][y]=true;
		}
		int an=0;
		for(int i=0; i<4; ++i){
			if(Card[i][6]){
				for(int j=5; j>=0; --j)
					if(!Card[i][j]){
						ar3[an++]=(i*13+j);
						break;
					}
				for(int j=7; j<13; ++j)
					if(!Card[i][j]){
						ar3[an++]=(i*13+j);
						break;
					}
			}
		}
		int ans=0,i=0,j=0;
		while(true){
			if(ar2[i]>ar3[j]) ++j;
			else if(ar2[i]<ar3[j]) ++i;
			else{
				++ans; ++i; ++j;
			}
			if(i>=b || j>=an) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
