#include <iostream>
#include <cstdio>
using namespace std;

struct Edge{
    int v1,v2,dis;
}Edge[10000];

int Edge_n;

int main(){
    int F;
    scanf("%d",&F);
    while(F--){
        bool Ans=false;
        Edge_n=0;
        int N,M,W;
        scanf("%d%d%d",&N,&M,&W);
        for(int i=0; i<M; i++){
            int a,b,d;
            scanf("%d%d%d",&a,&b,&d);
            Edge[Edge_n].v1=a; Edge[Edge_n].v2=b; Edge[Edge_n++].dis=d;
            Edge[Edge_n].v2=a; Edge[Edge_n].v1=b; Edge[Edge_n++].dis=d;
        }
        for(int i=0; i<W; i++){
            int a,b,d;
            scanf("%d%d%d",&a,&b,&d);
            Edge[Edge_n].v1=a; Edge[Edge_n].v2=b; Edge[Edge_n++].dis=d*(-1);
        }
        int Dis[550];
            for(int i=1; i<=N; i++) Dis[i]=1e9;
            for(int k=1; k<=N; k++){
                for(int i=0; i<Edge_n; i++){
                    int v1=Edge[i].v1, v2=Edge[i].v2, dis=Edge[i].dis;
                    if(1==v1 && dis<Dis[v2]) Dis[v2]=dis;
                    if(Dis[v1]==1e9)continue;
                    if(Dis[v2]>Dis[v1]+dis) Dis[v2]=Dis[v1]+dis;
                }
            }
            for(int i=0; i<Edge_n; i++){
                int v1=Edge[i].v1, v2=Edge[i].v2, dis=Edge[i].dis;
                if(Dis[v1]==1e9)continue;
                if(Dis[v2]>Dis[v1]+dis){
					Dis[v2]=Dis[v1]+dis;
					Ans=true; break;
				}
            }
        if(Ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
