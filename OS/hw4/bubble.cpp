#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int ar[10]={10,9,8,7,6,5,4,3,2,1};
	for(int i=0; i<10; ++i){
		for(int j=0; j<10; ++j)
			if(ar[i]<ar[j]){
				int tmp=ar[i];
				ar[i]=ar[j];
				ar[j]=tmp;
			}
	}
	for(int i=0; i<10; ++i)
		printf("%d ",ar[i]);
	printf("\n");
	return 0;
}
