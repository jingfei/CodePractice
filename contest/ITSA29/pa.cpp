#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
using namespace std;
const int MAX =10000;
int arr[MAX][MAX];


int main(){
	int testcase,n,r;
	memset(arr,0,sizeof(arr));
	arr[0][0]=1;
	arr[1][0]=1;
	arr[1][1]=1;
	int j=0;
	for(int i=2;i<=20;++i){
		for(j=0;j<i;++j){
			if(j==0)arr[i][j]=arr[i-1][j];
			else arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
		}
		arr[i][j]=1;
	}
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d%d",&n,&r);
		printf("%d\n",arr[n][r]);
	}
	return 0;
}
