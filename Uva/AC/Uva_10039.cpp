#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

struct Train{
	int v1,v2,t1,t2;
}e[100010];
int Dis[105],Start[105][105],Sn[105];

int main(){
	int N;
	scanf("%d",&N);
	for(int Case=1; Case<=N; Case++){
		int C,T,en=0;
		scanf("%d",&C);
		map <string,int> Map1;
		memset(Sn,0,sizeof(Sn));
		for(int i=0; i<C; i++){
			char s[1000];
			getchar();
			scanf("%s",s);
			Map1.insert(pair<string,int>(s,i));
		}
		scanf("%d",&T);
		while(T--){
			int t;
			scanf("%d",&t);
			t--;
				int t1,v1;
				char s[1000];
				scanf("%d %s",&t1,s);
				v1=Map1.find(s)->second;
				Start[v1][Sn[v1]++]=t1;
			while(t--){
				int v2,t2;
				scanf("%d %s",&t2,s);
				v2=Map1.find(s)->second;
				e[en].v1=v1; e[en].v2=v2; e[en].t1=t1; e[en++].t2=t2;
				t1=t2; v1=v2;
				Start[v1][Sn[v1]++]=t1;
			}
		}
		printf("Scenario %d\n",Case);
		int Time;
		char S1[1000],S2[1000];
		scanf("%d",&Time);
		getchar(); scanf("%s",S1); getchar(); scanf("%s",S2);
		int B,E;
		map <string,int>::iterator it1,it2;
		it1=Map1.find(S1); it2=Map1.find(S2);
		if(it1==Map1.end() || it2==Map1.end()){
			printf("No connection\n\n");
			continue;
		}
		B=it1->second; E=it2->second;
		sort(Start[E],Start[E]+Sn[E]);
		int Ans[2]={0,1e9};
		for(int j=0; j<Sn[E]; j++){
			memset(Dis,-1,sizeof(Dis));
			Dis[E]=Start[E][j];
			int k=(C==1?0:1);
			for(;k<C; k++)
				for(int i=0; i<en; i++){
					int v1=e[i].v1,v2=e[i].v2,t1=e[i].t1,t2=e[i].t2;
					if(Dis[v2]!=-1 && Dis[v2]>=t2 && Dis[v1]<t1) Dis[v1]=t1;
				}
			if(Dis[B]==-1 || Dis[B]<Time)continue;
			if(Dis[E]<Ans[1]){Ans[1]=Start[E][j]; Ans[0]=Dis[B];}
			else if(Dis[E]==Ans[1]) Ans[0]=max(Ans[0],Dis[B]);
			if(j==Sn[E]-1 || Start[E][j+1]!=Start[E][j]) break;
		}
		if(Ans[1]==1e9) printf("No connection\n\n");
		else{
			printf("Departure ");
			printf("%04d %s\n",Ans[0],S1);
			printf("Arrival   ");
			printf("%04d %s\n\n",Ans[1],S2);
		}
	}
	return 0;
}
