#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,d;
void BackTrack(int,int);
bool isPrime[3005];
bool Ans[1005],Finished;
int ans[1005];

void Sieze(){
	memset(isPrime,true,sizeof(isPrime));
	for(int i=2; i<3005; i++)
		if(isPrime[i])
			for(int j=i*i; j<3005; j+=i)
				isPrime[j]=false;
}

int main(){
	Sieze();
	while(scanf("%d%d%d",&n,&m,&d)!=EOF && !(n==0 && m==0 && d==0)){
		memset(Ans,false,sizeof(Ans));
		Finished=false;
		BackTrack(0,0);
		if(!Finished){
			printf("No anti-prime sequence exists.\n");
			continue;
		}
		printf("%d",ans[0]);
		for(int i=1; i<m-n+1; i++)
			printf(",%d",ans[i]);
		printf("\n");
	}
	return 0;
}

void BackTrack(int Tn,int loc){
	if(loc==m-n+1){
		int total=ans[loc-1];
		for(int i=loc-2; i>=loc-d; i--){
			total+=ans[i];
			if(isPrime[total]) return;
		}
		Finished=true;
		return;
	}
	if(loc<d && loc>1){
		int total=ans[loc-1];
		for(int i=loc-2; i>=0; i--){
			total+=ans[i];
			if(isPrime[total]) return;
		}
	}
	else if(d<=Tn){
		int total=ans[loc-1];
		for(int i=loc-2; i>=loc-d; i--){
			total+=ans[i];
			if(isPrime[total]) return;
		}
		BackTrack(Tn-1,loc);
		return;
	}
	for(int i=n; i<=m; i++)
		if(!Ans[i]){
			ans[loc]=i;
			Ans[i]=true;
			BackTrack(Tn+1,loc+1);
			if(Finished) return;
			Ans[i]=false;
		}
}

