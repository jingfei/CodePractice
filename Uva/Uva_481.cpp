#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int ar[100010];
int tmp[100010];
int pos[100010];
int ans[100010];

int main(){
	int top=0;
	while(scanf("%d",&ar[top])!=EOF){top++;}
	tmp[0]=ar[0];
	pos[0]=0;
	int m=1;
	for(int i=1; i<top; i++){
		int t=lower_bound(tmp,tmp+m,ar[i])-tmp;
		tmp[t]=ar[i];
		pos[i]=t;
		m=t+1>m?t+1:m;
	}
	printf("%d\n-\n",m--);
	int ans_n=0;
	for(int i=top-1; i>=0; i--)
		if(pos[i]==m) {ans[ans_n++]=ar[i]; m--;}
	for(int i=ans_n-1; i>=0; i--) printf("%d\n",ans[i]);
	return 0;
}
