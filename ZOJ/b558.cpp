#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  int n;
  while(scanf("%d",&n)!=EOF) {
    printf("%d\n",(n*(n-1)>>1)+1);
  }
  return 0;
}
