#include <iostream>
#include <cstdio>
using namespace std;

int Tree[20][1000000],n;
void Change(int,int);

int main(){
	int m;
	scanf("%d%d",&n,&m);
	int i=-1;
	while(true){
		scanf("%d%d",&Tree[0][i+1],&Tree[0][i+2]); i+=2;
		int j=i,k=1;
		while(j%2==1){
			j=(j-1)>>1;
			if(k%2==1) //or
				Tree[k][j]=Tree[k-1][j*2]|Tree[k-1][j*2+1];
			else
				Tree[k][j]=Tree[k-1][j*2]^Tree[k-1][j*2+1];
			++k;
			if(j==0) break;
		}
		if(k==n+1) break;
	}
	while(m--){
		int p,b; scanf("%d%d",&p,&b);
		Change(p-1,b);
		printf("%d\n",Tree[n][0]);
	}
	return 0;
}

void Change(int p,int b){
	Tree[0][p]=b; 
	for(int i=1; i<=n; ++i){
		if(p%2==1) p=(p-1)>>1;
		else p>>=1;
		if(i%2==1) Tree[i][p]=Tree[i-1][p*2]|Tree[i-1][p*2+1];
		else Tree[i][p]=Tree[i-1][p*2]^Tree[i-1][p*2+1];
	}
}

