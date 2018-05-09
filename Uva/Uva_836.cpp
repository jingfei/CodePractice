#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char ar[30][30];
int N;
int Find(int,int);

int main(){
	int n; bool blank=false;
	scanf("%d",&n);
	getchar(); 
	while(n--){
		getchar();
		scanf("%s",ar[0]);
		getchar();
		N=strlen(ar[0]);
		for(int i=1; i<N; i++){
			scanf("%s",ar[i]);
			getchar();
		}
		int Ans=0;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(ar[i][j]=='1'){
					Ans=max(Ans,Find(i,j));
//					printf("i:%d j:%d Ans:%d\n",i,j,Ans);
				}
		if(blank)printf("\n");
		else blank=true;
		printf("%d\n",Ans);
	}
	return 0;
}

int Find(int y, int x){
	int L=y,W=x;
	for(int j=x; j<N-1; j++){
		if(ar[y][j+1]=='1') W++;
		else break;
	}
	for(int i=y+1; i<N; i++){
		if(ar[i][x]!='1'){break;}
		for(int j=x; j<=W; j++)
			if(ar[i][j+1]!='1'){W=j; break;}
		L=i;
	}
	return (W-x+1)*(L-y+1);
}
