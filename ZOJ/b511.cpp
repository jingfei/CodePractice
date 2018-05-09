#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int ar[10][3];
int N;

void dfs(int n,int remain) {
  if(n==N) {
    if(!remain) {
      printf("(");
      for(int i=0; i<N; ++i){
        if(!i) printf("%d",ar[i][2]);
        else printf(",%d",ar[i][2]);
      }
      puts(")");
    }
    return;
  }
  for(int i=0; i<=ar[n][1]; ++i){
    ar[n][2]=i;
    if(remain-ar[n][0]*i>=0)
      dfs(n+1,remain-ar[n][0]*i);
    else 
      break;
  }
}

int main() {
  int M; scanf("%d",&N);
  memset(ar,0,sizeof(ar));
  for(int i=0; i<N; ++i) scanf("%d",&ar[i][0]);
  scanf("%d",&M);
  for(int i=0; i<N; ++i) ar[i][1]=M/ar[i][0];
  dfs(0,M);
  return 0;
}
