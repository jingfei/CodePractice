#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int gcd(int a,int b) { return !a ? b : gcd(b%a,a); }

int main() {
  int a,b;
  while(scanf("%d%d",&a,&b)!=EOF) {
    stack <pair<char,int> > s;
      int g=gcd(a,b); a/=g,b/=g;
    while(a!=1 || b!=1){
      if(a>b){ 
        if(b>1) a-=b;
        else --a;
        if(!s.empty() && s.top().first=='*') ++s.top().second;
        else s.push(pair<char,int>('*',1));
      }
      else { 
        int c=a; a=b; b=c; 
        if(!s.empty() && s.top().first=='+') ++s.top().second;
        else s.push(pair<char,int>('+',1)); 
      }
      int g=gcd(a,b); a/=g,b/=g;
    }
    long long int ANS=1;
    while(!s.empty()) {
      pair<char,int> c=s.top();
      if(c.first=='+') ANS+=c.second;
      else ANS<<=c.second;
      s.pop();
    }
    printf("%lld\n",ANS);
  }
  return 0;
}
