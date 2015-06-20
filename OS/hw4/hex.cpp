#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	for(int i=1,j=1; i<100000; i*=16, ++j){
		printf("%d:\t%d\n",j,i);
	}
	return 0;
}
