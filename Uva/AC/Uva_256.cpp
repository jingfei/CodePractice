#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int ar[4][100];

int main(){
	int n;
	ar[0][0]=ar[1][0]=ar[2][0]=ar[3][0]=0;
	ar[0][1]=0; ++ar[0][0];
	ar[1][1]=0; ++ar[1][0];
	ar[2][1]=0; ++ar[2][0];
	ar[3][1]=0; ++ar[3][0];
	for(int i=0; i<10000; ++i){
		for(int j=i+1; j<10000; ++j){
			if(i*10000+j==(i+j)*(i+j)) ar[3][++ar[3][0]]=i*10000+j;
			else if(i+j*10000==(i+j)*(i+j)) ar[3][++ar[3][0]]=i+j*10000;
			if(i>999 || j>999) continue;
			if(i*1000+j==(i+j)*(i+j)) ar[2][++ar[2][0]]=i*1000+j;
			else if(i+j*1000==(i+j)*(i+j)) ar[2][++ar[2][0]]=i+j*1000;
			if(i>99 || j>99) continue;
			if(i*100+j==(i+j)*(i+j)) ar[1][++ar[1][0]]=i*100+j;
			else if(i+j*100==(i+j)*(i+j)) ar[1][++ar[1][0]]=i+j*100;
			if(i>9 || j>9) continue;
			if(i*10+j==(i+j)*(i+j)) ar[0][++ar[0][0]]=i*10+j;
			else if(i+j*10==(i+j)*(i+j)) ar[0][++ar[0][0]]=i+j*10;
		}
	}
	while(scanf("%d",&n)!=EOF){
		sort(ar[n/2-1]+1,ar[n/2-1]+ar[n/2-1][0]+1);
		if(n==2) for(int i=1; i<=ar[0][0]; ++i) printf("%02d\n",ar[0][i]);
		else if(n==4) for(int i=1; i<=ar[1][0]; ++i) printf("%04d\n",ar[1][i]);
		if(n==6) for(int i=1; i<=ar[2][0]; ++i) printf("%06d\n",ar[2][i]);
		if(n==8) for(int i=1; i<=ar[3][0]; ++i) printf("%08d\n",ar[3][i]);
	}
	return 0;
}
