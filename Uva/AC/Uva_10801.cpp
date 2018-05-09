#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int n,k;
	int v[5],Dis[100];
	bool Ele[100][5];
	while(scanf("%d%d",&n,&k)!=EOF){
		memset(Ele,false,sizeof(Ele));
		for(int i=0; i<n; i++) scanf("%d",&v[i]);
		getchar();
		for(int i=0; i<n; i++){
			char s[1000];
			fgets(s,1000,stdin);
			int tmp=0;
			for(int j=0; j<strlen(s); j++){
				if(s[j]>='0' && s[j]<='9') tmp=tmp*10+s[j]-'0';
				else{Ele[tmp][i]=true; tmp=0;}
			}
			if(tmp) Ele[tmp][i]=true;
		}
		for(int i=0; i<100; i++) Dis[i]=1e9; Dis[0]=60;
		for(int l=1; l<100; l++)
		for(int i=0; i<n; i++){
			for(int j=1; j<100; j++){
				if(!Ele[j][i]) continue;
				for(int k=0; k<100; k++){
					if(Ele[k][i] && Dis[k]!=1e9){
						int tmp=(j-k)>=0?j-k:k-j;
						Dis[j]=min(tmp*v[i]+Dis[k]+60,Dis[j]);
//						break;
					}
				}
/*				for(int k=0; k<j; k++){
					if(Ele[k][i] && Dis[k]!=1e9){
						Dis[j]=min((j-k)*v[i]+Dis[k]+60, Dis[j]);
						break;
					}
				}
*/				if(Ele[0][i]) Dis[j]=min(j*v[i]+60,Dis[j]);
			}
		}
		if(Dis[k]==1e9) printf("IMPOSSIBLE\n");
		else printf("%d\n",Dis[k]-60);
	}
	return 0;
}
