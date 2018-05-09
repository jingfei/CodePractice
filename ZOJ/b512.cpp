#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct T{
  int i,v;
  bool operator<(const struct T &t)const{return i<t.i;}
}ar1[1000010],ar2[1000010];

int main() {
  int a,b,n1=0,n2=0;
  while(scanf("%d:%d",&a,&b)!=EOF && (a|b)!=0) ar1[n1].i=a,ar1[n1++].v=b;
  while(scanf("%d:%d",&a,&b)!=EOF && (a|b)!=0) ar2[n2].i=a,ar2[n2++].v=b;
  sort(ar1,ar1+n1); sort(ar2,ar2+n2);
  long long int ans=0;
  for(int i=0,j=0; i<n1 || j<n2;) {
    if(i>=n1) ++j;
    if(j>=n2) ++i;
    else if(ar1[i].i==ar2[j].i) ans+=ar1[i].v*ar2[j].v,++i,++j;
    else if(ar1[i].i>ar2[j].i) ++j;
    else if(ar1[i].i<ar2[j].i) ++i;
  }
  printf("%lld\n",ans);
  return 0;
}
