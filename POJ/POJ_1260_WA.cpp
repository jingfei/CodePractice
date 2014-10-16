#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n,Case;
	scanf("%d",&Case);
	while(Case--){
		scanf("%d",&n);
		double tmp=1e9;
		int Ai=0,Ans=0,Pi;
		while(n--){
			int ai,pi;
			scanf("%d%d",&ai,&pi);
			if(tmp>=pi) ai+=Ai;
			else Ans+=(Ai+10)*Pi;
			tmp=10.0*pi/(double)ai+pi;
			Ai=ai; Pi=pi;
//			printf(" %d\n",Ans);
		}
		Ans+=(Ai+10)*Pi;
		printf("%d\n",Ans);
	}
	return 0;
}
