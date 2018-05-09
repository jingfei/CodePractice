#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n;
  while(scanf("%d",&n)!=EOF && n) {
    vector <int> V;
    for(int i=0; i<n; ++i) {
      int tmp; scanf("%d",&tmp);
      V.push_back(tmp);
    }
    sort(V.begin(),V.end());
    printf("%d",V[0]);
    for(int i=1; i<n; ++i) printf(" %d",V[i]);
    puts("");
  }
  return 0;
}
