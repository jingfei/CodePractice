#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[105],b[105];

int main(){
	char s1[105],s2[105];
	int Case=0,Na,Nb;
	while(gets(s1)!=0 && strcmp(s1,"#")){
		gets(s2);
		int dp[105][105]={{0}};
		Na=strlen(s1);
		Nb=strlen(s2);
		for(int i=1; i<=Na; i++){
			for(int j=1; j<=Nb; j++){
				int A=dp[i-1][j],B=dp[i][j-1],C=0;
				if(s1[i-1]==s2[j-1]) C=dp[i-1][j-1]+1;
				dp[i][j]=max(A,B);
				dp[i][j]=max(dp[i][j],C);
			}	
		}
//		printf("%s %s\n",s1,s2);
		printf("Case #%d: you can visit at most %d cities.\n",++Case,dp[Na][Nb]);
	}
	return 0;
}
