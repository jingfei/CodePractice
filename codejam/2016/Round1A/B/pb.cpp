#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N,res=-1,dir=0;
bool Find=false;

struct LIST {
	int a[100];
	bool operator<(const struct LIST &t)const{
		for(int i=0; i<N; ++i)
			if(a[i]!=t.a[i]) return a[i]<t.a[i];
		return true;
	}
}ar[100];
int ans[50][50];

void dfs(int n,int L,int T){
	//	printf("%d %d %d:\n",n,L,T);
	//	for(int i=0; i<N; ++i) printf(" %d",ar[n].a[i]);
	//	puts("");
	//	for(int i=0; i<N; ++i){
	//		for(int j=0; j<N; ++j)
	//			printf("%d ",ans[i][j]);
	//		puts("");
	//	}
	//	puts("");
	if(n==N*2-1 || Find){ Find=true; return; }
	bool find1=true,find2=true;
	int tmp[55];
	if(L==N) find1=false;
	else
		for(int i=0; i<N; ++i){
			if(i<T){
				if(ar[n].a[i]!=ans[L][i] && ans[L][i]!=-1){
					find1=false; break;
				}
			} else {
				if(L && ar[n].a[i]<=ans[L-1][i]){
					find1=false; break;
				}
			}
		}
	if(find1){ 
		for(int i=0; i<N; ++i){ 
			tmp[i]=ans[L][i];
			ans[L][i]=ar[n].a[i];
		}
		dfs(n+1,L+1,T);
		if(Find) return;
		for(int i=0; i<N; ++i) ans[L][i]=tmp[i];
	}
	if(T==N) find2=false;
	else
		for(int i=0; i<N; ++i){
			if(i<L){
				if(ar[n].a[i]!=ans[i][T] && ans[i][T]!=-1){
					find2=false; break;
				}
			} else {
				if(T && ar[n].a[i]<=ans[i][T-1]){
					find2=false; break;
				}
			}
		}
	if(find2){
		for(int i=0; i<N; ++i){
			tmp[i]=ans[i][T];
			ans[i][T]=ar[n].a[i]; 
		}
		dfs(n+1,L,T+1);
		if(Find) return;
		for(int i=0; i<N; ++i) ans[i][T]=tmp[i];
	}
		if(T<N-1){ 
			bool yes=true;
			for(int i=0; i<N; ++i){
				if(i<L){
					if(ar[n].a[i]!=ans[i][T+1]){
						yes=false;
						break;
					}
				}
				else{
					if(ar[n].a[i]<=ans[i][T-1]){
						yes=false;
						break;
					}
				}
			}
			if(yes){
				res=T;
				dir=1;
				dfs(n,L,T+1);
				if(Find) return;
				res=-1;
			}
		}
		if(L<N-1){
			bool yes=true;
			for(int i=0; i<N; ++i){
				if(i<T){
					if(ar[n].a[i]!=ans[L+1][i]){
						yes=false;
						break;
					}
				}
				else{
					if(ar[n].a[i]<=ans[L-1][i]){
						yes=false;
						break;
					}
				}
			}
			if(yes){
				res=L;
				dir=0;
				dfs(n,L+1,T);
				if(Find) return;
				res=-1;
			}
		}
}

int main(){
	int T; scanf("%d",&T); getchar();
	for(int Case=1; Case<=T; ++Case){
		scanf("%d",&N);
		for(int i=0; i<N*2-1; ++i)
			for(int j=0; j<N; ++j)
				scanf("%d",&ar[i].a[j]);
		sort(ar,ar+N*2-1);
		memset(ans,-1,sizeof(ans));
		Find=false; res=-1;
		/* dir 1 -> top, dir 0 -> left */
		for(int i=0; i<N; ++i) ans[0][i]=ar[0].a[i];
		if(ar[1].a[0]!=ans[0][0]){
			res=0; dir=1;
			dfs(1,1,1);
		}
		else{ 
			for(int i=0; i<N; ++i) ans[i][0]=ar[1].a[i];
			dfs(2,1,1);
		}
		printf("Case #%d:",Case);
	//	printf("%d %d\n",res,dir);
	//	for(int i=0; i<N; ++i){
	//		for(int j=0; j<N; ++j)
	//			printf("%d ",ans[i][j]);
	//		puts("");
	//	}
		if(res==-1){
			res=N-1;
			bool yes=true;
			for(int i=0; i<N; ++i)
				if(ar[N*2-2].a[i]!=ans[i][N-1]){
					yes=false;
					break;
				}
			if(yes)
				for(int i=0; i<N; ++i)
					printf(" %d",ans[res][i]);
			else
				for(int i=0; i<N; ++i)
					printf(" %d",ans[i][res]);
			puts("");
		}
		else{
			if(dir)
				for(int i=0; i<N; ++i)
					printf(" %d",ans[i][res]);
			else
				for(int i=0; i<N; ++i)
					printf(" %d",ans[res][i]);
			puts("");
		}
	}
	return 0;
}

