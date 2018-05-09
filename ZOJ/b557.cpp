#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
  int N; int T; scanf("%d",&T);
  int ar[110];
  while(T--){
    scanf("%d",&N);
    int MAX=0;
    memset(ar,0,sizeof(ar));
    long long int ans=0;
    while(N--){
      int i; scanf("%d",&i);
      ++ar[i];
      if(i>MAX) MAX=i;
    }
    int MMAX=MAX*MAX;
    for(int i=1; i<MAX; ++i) {
      if(!ar[i]) continue;
      for(int j=i+1; j<MAX; ++j) {
        if(!ar[j]) continue;
        int t=i*i+j*j;
        if(t>MMAX) break;
        int T=sqrt(t);
        if(T*T!=t) continue;
        t=T;
        if(!ar[t]) continue;
        ans+=ar[i]*ar[j]*ar[t];
      }
    }
    printf("%lld\n",ans);
  }
  return 0;
}
