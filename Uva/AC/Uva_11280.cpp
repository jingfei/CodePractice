#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

struct edge{
	int a,b,dis;
}e[1010];

int main(){
	int n;
	scanf("%d",&n);
	for(int Case=1; Case<=n; Case++){
		int N,M,Q,en=0;
		map <string,int> City;
		scanf("%d",&N);
		for(int i=0; i<N; i++){
			char s[30];
			getchar();
			scanf("%s",s);
			City.insert(pair<string,int>(s,i));
		}
		scanf("%d",&M);
		while(M--){
			char s1[30],s2[30];
			int dis;
			getchar();
			scanf("%s %s %d",s1,s2,&dis);
			int a=City.find(s1)->second, b=City.find(s2)->second;
			e[en].a=a; e[en].b=b; e[en++].dis=dis;
		}
		if(Case!=1) printf("\n");
		printf("Scenario #%d\n",Case);
		scanf("%d",&Q);
			int Dis[105][105];
			int Dn[105];
			memset(Dn,0,sizeof(Dn));
			for(int i=1; i<N; i++)
				for(int j=0; j<N; j++) 
					Dis[i][j]=1e9;
			for(int i=0; i<N; i++) Dis[0][i]=0;
			for(int k=1; k<N; k++)
				for(int i=0; i<en; i++){
					int a=e[i].a, b=e[i].b, dis=e[i].dis;
					for(int j=0; j<=Dn[a]; j++){
						int Lev=j;
						if(Dis[b][Lev+1]>Dis[a][j]+dis){ 
							Dis[b][Lev+1]=Dis[a][j]+dis;
							Dn[b]=max(Dn[b],Lev+1);
							if(Lev>0 && Dis[b][Lev+1]>Dis[b][Lev])
								Dis[b][Lev+1]=Dis[b][Lev];
						}
					}
				}
		for(int i=0; i<N; i++){
			for(int j=1; j<=Dn[i]; j++)
				if(Dis[i][j]>Dis[i][j-1]) Dis[i][j]=Dis[i][j-1];
		}
		while(Q--){
			int q;
			scanf("%d",&q);
			if(q+1>Dn[N-1]){
				if(Dis[N-1][Dn[N-1]]==1e9) printf("No satisfactory flights\n");
				else printf("Total cost of flight(s) is $%d\n",Dis[N-1][Dn[N-1]]);
			}
			else if(Dis[N-1][q+1]==1e9) printf("No satisfactory flights\n");
			else printf("Total cost of flight(s) is $%d\n",Dis[N-1][q+1]);
		}
	}
	return 0;
}
