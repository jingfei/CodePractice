#include <iostream>
#include <cstdio>
using namespace std;

int main (){
  int T; scanf("%d",&T);
  for(int Case=1; Case<=T; ++Case) {
    int a,b; scanf("%d%d",&a,&b);
    if(a*b%2==0)
      printf("Scenario #%d:\n%d.00\n\n",Case,a*b);
    else
      printf("Scenario #%d:\n%d.41\n\n",Case,a*b);
  }
  return 0;
}
