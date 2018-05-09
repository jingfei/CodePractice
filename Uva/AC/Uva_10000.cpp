#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct EDGE { int s,t; } e[10000];

int main(){
  int n, en, Case=1;
  while(scanf("%d",&n)!=EOF && n){
    int s; scanf("%d",&s);
    int p,q; en=0;
    while(scanf("%d%d",&p,&q) && p!=0 && q!=0) {
      e[en].s=p; e[en++].t=q;
    }
    int dis[110]; memset(dis,-1,sizeof(dis));
    dis[s]=0;
    for(int k=1 ; k<n; ++k){  //找每個邊N-1次
      for(int i=0; i<en; ++i){
        int v1=e[i].s, v2=e[i].t;
        if(dis[v1]==-1) continue;
        if(dis[v2]<dis[v1]+1) dis[v2]=dis[v1]+1;
      }
    }
    int len=0, finish;
    for(int i=1; i<=n; ++i) if(dis[i]>len) {len=dis[i]; finish=i;}
    printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",Case++,s,len,finish);
  }
  return 0;
}
