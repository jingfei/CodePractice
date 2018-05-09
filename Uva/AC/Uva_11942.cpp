#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n; scanf("%d",&n);
	int ar[10];
	puts("Lumberjacks:");
	while(n--){
		for(int i=0; i<10; ++i) scanf("%d",&ar[i]);
		bool increase = true, ordered=true;
		if(ar[1]-ar[0]<0) increase = false;
		for(int i=2; i<10; ++i){
			if(ar[i]-ar[i-1]<0 && increase) ordered=false;
			else if(ar[i]-ar[i-1]>0 && !increase) ordered=false;
		}
		if(ordered) puts("Ordered");
		else puts("Unordered");
	}
	return 0;
}
