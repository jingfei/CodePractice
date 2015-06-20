#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int num[10], Num=3, ar[1000];

int main(){
	for(int i=0; i<Num; ++i)
		scanf("%d",&num[i]);
	for(int i=0; i<1000; ++i)
		scanf("%d",&ar[i]);
//	sort(ar, ar+1000);
//	int t=1, all=0;
//	for(int i=1; i<=1000; ++i){
//		if(i==1000 || ar[i]!=ar[i-1]){
//			printf("%2d: %3d time(s)\n", ar[i-1], t);
//			all+=t;
//			t=1;
//		}
//		else ++t;
//	}
//	printf("all: %d\n",all);
	for(int i=0; i<Num; ++i){
		int times=0;
		for(int j=0; j<1000; ++j){
			if(ar[j]==num[i])
				times++;
		}
		printf("%3d: %4d time(s)\n", num[i], times);
	}
	return 0;
}
