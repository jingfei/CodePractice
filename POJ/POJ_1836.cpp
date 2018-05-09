#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int Bin(double *A, int Range, double key);

int main(){
	int n;
	double ans1[1005], ans2[1005], ar[1005], tmp1[1005], tmp2[1005], Same[1005];
	int ans_n,ans2_n, pos[1005],tmp_n, Same_n;
	while(scanf("%d",&n)!=EOF){
		ans_n=0; ans2_n=0; Same_n=0;
		int m=1;
		for(int i=0; i<n; i++){
			double x;
			scanf("%lf",&x);
			ar[i]=x;
			if(i==0){tmp1[0]=x; pos[i]=0; continue;}
			if(x==ar[i-1]) 
				if(Same_n==0 || x!=Same[Same_n-1])
					Same[Same_n++]=x;
			int t=lower_bound(tmp1,tmp1+m,x)-tmp1;
			pos[i]=t;
			tmp1[t]=x;
			m=t+1>m?t+1:m;
		}
		ans_n=m;
		m--;
		int tt=m;
		for(int i=n-1; i>=0; i--)
			if(pos[i]==m){ans1[tt--]=ar[i]; m--;}
		m=1;
		pos[0]=0; tmp2[0]=ar[n-1];
		for(int i=n-2; i>=0; i--){
			int t=lower_bound(tmp2,tmp2+m,ar[i])-tmp2;
			printf("ar[i]: %.3lf  t: %d\n",ar[i],t);
			pos[i]=t;
			tmp2[t]=ar[i];
			m=t+1>m?t+1:m;
		}
		ans2_n=m;
		m--;
		tt=m;
		for(int i=0; i<n; i++)
			if(pos[i]==m){ans2[tt--]=ar[i]; m--;}
		for(int i=0; i<ans_n; i++) printf("%lf ",ans1[i]); printf("\n");
		for(int i=0; i<ans2_n; i++) printf("%lf ",ans2[i]); printf("\n");
		int Ans=0;
		if(Bin(Same,Same_n,ans1[ans_n-1])!=-1) Ans=max(ans_n+1,Ans);
		else Ans=max(ans_n,Ans);
		if(Bin(Same,Same_n,ans2[ans2_n-1])!=-1) Ans=max(ans2_n+1,Ans);
		else Ans=max(ans2_n,Ans);
		for(int i=0; i<ans_n; i++){
			int Find=Bin(ans2,ans2_n,ans1[i]);
			if(Find!=-1){
				if(Bin(Same,Same_n,ans1[i])!=-1) Ans=max(i+Find+2,Ans);
				else Ans=max(i+Find+1,Ans);	
			}
		}
		printf("%d\n",n-Ans);
	}	
	return 0;
}

int Bin(double *A, int Range, double key){
	int L=0, R=Range,mid;
	while(L<R){
		mid=(L+R)/2;
		if(key>A[mid]) L=mid+1;
		else if(key<A[mid]) R=mid;
		else return mid;
	}
	return -1;
}
