#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char ar[25][25];
int DP[20010][20010];
int alph[26][26];
int S[20010],Sn;
int Lis();
void Track(char *ans,int N,int y,int x){
	getchar();
	char c;
	ans[1]=ar[y][x];
	for(int i=0; i<N; i++){
		c=getchar();
		switch(c){
			case 'E': x++; break;
			case 'S': y++; break;
			case 'W': x--; break;
			case 'N': y--; break;
		}
		ans[i+2]=ar[y][x];
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(int Case=1; Case<=t; Case++){
		int H,W;
		scanf("%d%d",&H,&W);
		getchar();
		for(int i=1; i<=H; i++){
			for(int j=1; j<=W; j++)
				scanf("%c",&ar[i][j]);
			getchar();
		}
		int N1,x1,y1,N2,x2,y2;
		scanf("%d%d%d",&N1,&y1,&x1);
		char A[20010];
		Track(A,N1,y1,x1);
//		for(int i=1; i<=N1+1; i++) printf("%c",A[i]);
		scanf("%d%d%d",&N2,&y2,&x2);
		char B[20010];
		Track(B,N2,y2,x2);
//		for(int i=1; i<=N2+1; i++) printf("%c",B[i]);
/* 		memset(DP,0,sizeof(DP));
		for(int i=1; i<=N1+1; i++)
			for(int j=1; j<=N2+1; j++){
				int a=DP[i-1][j], b=DP[i][j-1], c=0;
				if(A[i]==B[j]) c=DP[i-1][j-1]+1;
				if(c>a && c>b) DP[i][j]=c;
				else if(a>c && a>b) DP[i][j]=a;
				else DP[i][j]=b;
			}
*/		
		memset(alph,0,sizeof(alph));
		for(int i=1; i<=N1+1; ++i) alph[A[i]-'A'][++alph[A[i]-'A'][0]]=i;
		Sn=0;
		for(int i=1; i<=N2+2; ++i)
			for(int j=1; j<=alph[B[i]-'A'][0]; ++j)
				S[Sn++]=alph[B[i]-'A'][j];
		int Ans=Lis();
		printf("Case %d: %d %d\n",Case,N1+1-Ans,N2+1-Ans);
	}
	return 0;
}

int Lis(){
	int n=0,tmp[20010];
	for(int i=0; i<Sn; ++i){
		if(!n) tmp[n++]=S[i];
		else if(S[i]>tmp[n-1]) tmp[n++]=S[i];
		else *lower_bound(tmp,tmp+n,S[i])=S[i];
	}
	return n;
}

