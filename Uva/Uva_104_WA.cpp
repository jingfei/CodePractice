#include <iostream>
#include <cstdio>
using namespace std;

double Ch[25][25][25];
double ar[25][25];
struct ans{
	int A[25],An,last;
}ans[25][25];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				if(i==j) ar[i][j]=1.0;
				else scanf("%lf",&ar[i][j]);
			}
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				for(int k=0; k<n; k++)
					Ch[i][j][k]=ar[i][j]*ar[j][k];
		bool find=false;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(i==j)continue;
				if(Ch[i][j][i]>1.01){
					find=true;
					printf("%d %d %d\n",i+1,j+1,i+1);
					break;
				}
				else{
					ans[i][j].A[0]=i; ans[i][j].A[1]=j; 
					ans[i][j].An=2; ans[i][j].last=j;
				} 
			}
			if(find) break;
		}
		if(find) continue;
		for(int k=2; k<n; k++){
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					if(i==j)continue;
					double Max=-1;
					int ml=0, last=ans[i][j].last;
					for(int l=0; l<n; l++){
						if(l==last || l==i) continue;
						if(Ch[last][l][i]>Max){
							ml=l; Max=Ch[last][l][i];
						}
					}
					if( ar[i][j]*Max>1.01){
						find=true;
						for(int ii=0; ii<ans[i][j].An; ii++) 
							printf("%d ",ans[i][j].A[ii]+1);
						printf("%d %d\n",ml+1,i+1);
						break;
					}
					Max=-1;
					for(int l=0; l<n; l++){
						if(l==last)continue;
						if(Ch[last][l][l]>Max){Max=Ch[last][l][l]; ml=l;}
					}
					ar[i][j]=ar[i][j]*Max;
					ans[i][j].last=ml;
					ans[i][j].A[ans[i][j].An++]=ml;
				}
				if(find) break;
			}
			if(find) break;
		}
		if(find)continue;
		printf("no arbitrage sequence exists\n");
	}
	return 0;
}
