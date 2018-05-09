#include <iostream>
#include <cstdio>
using namespace std;

bool KMP(string A, string B) {
  int LenA = A.length(), LenB=B.length();
  int pi[110]; pi[0]=-1;
  for(int i=1,k=-1; i<LenA; ++i){
    while(k>=0 && A[i]!=A[k+1]) k=pi[k]; if(A[i]==A[k+1]) ++k;
    pi[i]=k;
  }
  for(int i=0,k=-1; i<LenB; ++i){
    while(k>=0 && B[i]!=A[k+1]) k=pi[k];
    if(B[i]==A[k+1]) ++k;
    if(k+1==LenA){ return true;}
  }
  return false;
}
bool rotateString(string A, string B) {
  if(A.length() != B.length()) return false;
  A += A;
  return KMP(A,B);
}

int main() {
  string A,B;
  while(cin >> A >> B) {
    cout << (rotateString(A, B) ? "true" : "false") << endl;
  }
  return 0;
}

