#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <bitset>
using namespace std;

long long int Max = 1;

long long int ar[1000000];

int main(){
	for(int i=0; i<32; ++i){
		Max <<= 1;
		Max+=1;
	}
	printf("MAX: %u\n", Max);
	ar[0]=ar[1]=1;
	for(int i=2; ; ++i){
		ar[i]=ar[i-2]+ar[i-1];
		if(ar[i]>Max) break;
//		cout << dec << i+1 << "\t\t" << ar[i] << "\t\t" << hex << ar[i] << endl;
		printf("%d\t\t%u\t\t%08x\n",i+1,ar[i],ar[i]);
	}

	return 0;
}
