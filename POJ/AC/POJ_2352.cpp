#include <iostream>
#include <cstdio>
#define MAX 32002
using namespace std;

int N, lev[15001]={0}, s[MAX]={0};

inline int lowbit(int n) { return n&(-n); }

void modify(int index) {
  for(int i=index; i<MAX; i+=lowbit(i)) ++s[i];
}

int getsum(int index) {
  int ans=0;
  while(index>0) {
    ans+=s[index];
    index-=lowbit(index);
  }
  return ans;
}

int main() {
  scanf("%d",&N);
  for(int i=0; i<N; ++i) {
    int a,b; scanf("%d%d",&a,&b);
    modify(a+1);
    ++lev[getsum(a+1)];
  }
  for(int i=1; i<=N; ++i) printf("%d\n",lev[i]);
  return 0;
}

