#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int Num[6],Ans[1000010];

int main(){
	int Case=0;
	while(scanf("%d%d%d%d%d%d",&Num[0],&Num[1],&Num[2],&Num[3],&Num[4],&Num[5])!=EOF){
		if(!Num[0] && !Num[1] && !Num[2] && !Num[3] && !Num[4] && !Num[5]) break;
		++Case;
		printf("Collection #%d:\n",Case);
		long long int Total=0;
		for(int i=0; i<6; ++i)
			Total+=(i+1)*Num[i];
		if(Total%2==1){printf("Can't be divided.\n\n"); continue;}
		Total>>=1;
		memset(Ans,0,sizeof(Ans));
		for(int i=0; i<6; ++i){
			for(int k=1; k<Num[i]; k*=2){
				for(int j=Total; j>=k*(i+1); --j){
					int Rest=j-(i+1)*k;
					if((i+1)*k+Ans[Rest]>Ans[j])
						Ans[j]=Ans[Rest]+(i+1)*k;
				}
				Num[i]-=k;
			}
			for(int j=Total; j>=Num[i]*(i+1); --j){
				int Rest=j-(i+1)*Num[i];
				if(Num[i]*(i+1)+Ans[Rest]>Ans[j])
					Ans[j]=Ans[Rest]+(i+1)*Num[i];
			}
		}
//		printf("%d %d\n",Total,Ans[Total]);
		if(Ans[Total]==Total) printf("Can be divided.\n\n");
		else printf("Can't be divided.\n\n");
	}
	return 0;
}
