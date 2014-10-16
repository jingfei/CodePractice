#include <iostream>
#include <cstdio>
using namespace std;

int n,ar[1010];

bool Check(){
	for(int i=1; i<=n; ++i)
		if(ar[i]!=i) return false;
	return true;
}

void Change(int l,int r){
	int mid=(l+r)>>1;
	for(int i=l,j=r; i<=mid; ++i,--j){
		int tmp=ar[i]; ar[i]=ar[j]; ar[j]=tmp;
	}
}

int Find(int x){
	for(int i=1; i<=n; ++i) if(ar[i]==x) return i;
}

int main(){
	scanf("%d",&n);
	int ans=0; int Ans[3][2];
	for(int i=1; i<=n; ++i) scanf("%d",&ar[i]);
	for(int i=1; i<=n; ++i){
		if(ar[i]!=i){
			int x=Find(i);
			Change(i,x);
			Ans[ans][0]=i; Ans[ans][1]=x;
			++ans;
		}
	}
	printf("%d\n",ans);
	for(int i=0; i<ans; ++i) printf("%d %d\n",Ans[i][0],Ans[i][1]);
	return 0;
}

