#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  char s[210];
  while(fgets(s,sizeof(s),stdin)!=0){
    if(!strcmp(s,"START\n") || !strcmp(s,"END\n")) continue;
    if(!strcmp(s,"ENDOFINPUT")) break;
    int len=strlen(s)-1;
    for(int i=0; i<len; ++i) {
      if(s[i]>='A' && s[i]<='Z') {
        s[i]+=('V'-'A');
        if(s[i]>'Z') s[i]-=26;
      }
    }
    printf("%s",s);
  }
  return 0;
}
