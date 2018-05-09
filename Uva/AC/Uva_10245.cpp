#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct DOT {
  double x,y;
  bool operator< (const struct DOT &t) const {
    return x < t.x;
  }
} dot[10010];

double getDis(int i, int j) {
  double X = dot[i].x-dot[j].x;
  double Y = dot[i].y-dot[j].y;
  return sqrt(X*X + Y*Y);
}

double merge(int L, int mid, int R, double min_dis) {
  double line = (dot[mid].x+dot[mid+1].x)*.5;
  double res = min_dis;
  for(int i=mid; dot[i].x>line-min_dis && i>=L; --i)
    for(int j=mid+1; dot[j].x<line+min_dis && j<=R; ++j)
      res = min(res,getDis(i,j));
  return res;
}

double divide(int L, int R) {
  if(R-L<=2) {
    double res = 1e9;
    for(int i=L; i<R; ++i)
      for(int j=i+1; j<=R; ++j)
        res = min(res,getDis(i,j));
    return res;
  }
  
  int mid = (L+R) >> 1;
  double min_left = divide(L,mid);
  double min_right = divide(mid+1,R);
  return merge(L,mid,R, min(min_left,min_right) );
}

int main() {
  int N;
  while(scanf("%d",&N)!=EOF && N) {
    for(int i=0; i<N; ++i) scanf("%lf%lf",&dot[i].x,&dot[i].y);
    sort(dot, dot+N);
    double ans = divide(0,N-1);
    if(ans < 10000.0) printf("%.4lf\n",ans);
    else puts("INFINITY");
  }
  return 0;
}

