#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int ar[105][105];
	int N;
	while(scanf("%d",&N)!=EOF){
		for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d",&ar[i][j]);
		int colSum[105][105]={{0}};
		for(int i=1; i<=N; i++) 
			for(int j=0; j<N; j++) colSum[i][j]=colSum[i-1][j]+ar[i-1][j];
		int Ans=0;
		for(int i=1; i<=N; i++)
			for(int j=i; j<=N; j++){
				int sum=0;
				for(int k=0; k<N; k++){
					sum+=(colSum[j][k]-colSum[i-1][k]);
					if(sum<0)sum=0;
					Ans=max(sum,Ans);
				}
			}
		printf("%d\n",Ans);
	}
	return 0;
}
