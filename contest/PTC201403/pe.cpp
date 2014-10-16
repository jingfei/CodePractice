#include <iostream>
#include <cstdio>
using namespace std;

int ar[50],ans[50];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF && n!=0){
		char c; getchar(); scanf("%c",&c); getchar();
		for(int i=0; i<n; ++i) scanf("%d",&ar[i]);
		if(c=='p'){
			for(int i=0; i<n; ++i){
				int ans=0;
				for(int j=0; j<i; ++j)
					if(ar[j]<ar[i]) ++ans;
				if(!i) printf("%d",ans);
				else printf(" %d",ans);
			}
			printf("\n");
		}
		else{
			int Now=n-1;
			while(Now>=0)
				for(int i=n-1; i>=0; --i){
					if(ar[i]==i){
						ans[i]=Now--;
						for(int j=i; j<n; ++j) ++ar[j];
						break;
					}
				}
			for(int i=0; i<n; ++i){
				if(i==n-1) printf("%d\n",ans[i]);
				else printf("%d ",ans[i]);
			}
		}
	}
	return 0;
}
