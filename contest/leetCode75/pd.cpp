#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int ar[20010];
int size;
void cal(int i, int num) {
  if(i<num) {
    int Max = size-num+i;
    int Min = i+1;
    for(int j=Min; j<=Max; ++j) ++ar[j];
  } else {
    int Min = i-num;
    int Max = i+1;
    printf("num: %d, Min: %d\n, Max: %d\n", num, Min, Max);
    for(int j=0; j<=Min; ++j) ++ar[j];
    for(int j=Max; j<size; ++j) ++ar[j];
  }
}

int bestRotation(vector<int>& A) {
  memset(ar,0,sizeof(ar));
  size = A.size();
  for(int i=0; i<size; ++i) cal(i, A[i]);
  int max = -1, ans=0;;
  for(int i=0; i<size; ++i) if(ar[i] > max) ans = i, max = ar[i];
  for(int i=0; i<size; ++i) printf("%d ",ar[i]);
  puts("");
  return ans;
}

int main() {
  vector<int> A;
  for(int i=0; i<5; ++i) {
    int tmp;
    scanf("%d",&tmp);
    A.push_back(tmp);
  }
  printf("%d\n",bestRotation(A));
  return 0;
}
