#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int w[50010], s[500010], pi[50010], ans[50010], an;

int main() {
  int N; scanf("%d",&N);
  while(N--) {
    map <char,int> m;
    string A,W,S; cin >> A >> W >> S;
    int lenA = A.length(), lenW = W.length(), lenS=S.length();
    for(int i=0; i<lenA; ++i) m.insert(pair<char,int>(A[i],i));
    for(int i=0; i<lenW; ++i) w[i] = m[W[i]];
    for(int i=0; i<lenS; ++i) s[i] = m[S[i]];
    pi[0]=-1;
    for(int i=1,k=-1; i<lenW; ++i){
      while(~k && w[i]!=w[k+1]) k=pi[k];
      if(w[i]==w[k+1]) ++k;
      pi[i]=k;
    }
    an=0;
    for(int j=0; j<lenA; ++j) {
      int match=0; 
      for(int i=0,k=-1; i<lenS; ++i){
        int move = s[i]-j; if(move<0) move+=lenA;
        while(~k && move!=w[k+1]) k=pi[k];
        if(move==w[k+1]) ++k;
        if(k+1==lenW){ ++match; k=pi[k];}
      }
      if(match==1) ans[an++]=j;
    }
    if(an==0) puts("no solution");
    else if(an==1) printf("unique: %d\n",ans[0]);
    else {
      printf("ambiguous:");
      for(int i=0; i<an; ++i) printf(" %d",ans[i]);
      puts("");
    }
  }
  return 0;
}
