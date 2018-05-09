#include <iostream>
#include <cstdio>
#define ll long long int
using namespace std;

inline int gcd(int a,int b) { return !a ? b : gcd(b%a,a); }

int main(){
  ll a,b,c,d; char e;
  while(scanf("%lld %lld %lld %lld %c",&a,&b,&c,&d,&e)!=EOF) {
    ll g,down,top,tmp;
    switch(e) {
      case '+':
      case '-':
        if(b<0) b=-b,a=-a;
        if(d<0) d=-d,c=-c;
        g=gcd(b,d);
        down=b/g*d;
        top= e=='+' ? d/g*a+b/g*c : d/g*a-b/g*c;
        g=gcd(top<0?-top:top,down<0?-down:down);
        top/=g, down/=g;
        if(down==1) printf("%lld\n",top);
        else printf("%lld/%lld\n",top,down);
        break;
      case '/':
        tmp=c; c=d; d=tmp;
      case '*':
        tmp=0; 
        if(a<0) a=-a,++tmp;
        if(b<0) b=-b,++tmp;
        if(c<0) c=-c,++tmp;
        if(d<0) d=-d,++tmp;
        g=gcd(a,b);
        a/=g, b/=g;
        g=gcd(c,d);
        c/=g, d/=g;
        g=gcd(a,d);
        a/=g, d/=g;
        g=gcd(b,c);
        b/=g, c/=g;
        top = a*c;
        down = b*d;
        if(tmp%2) printf("-");
        if(down==1) printf("%lld\n",top);
        else printf("%lld/%lld\n",top,down);
        break;
    }
  }
  return 0;
}
