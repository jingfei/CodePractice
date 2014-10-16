#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int n,m,d;
void BackTrack(int);
bool Check(int,int);
bool isPrime[3005];
bool Ans[1005],Finished;
int ans[1005];

void Sieze(){
	memset(isPrime,true,sizeof(isPrime));
	for(int i=2; i<3005; ++i)
		if(isPrime[i])
			for(int j=i*i; j<3005; j+=i)
				isPrime[j]=false;
}

int main(){
	Sieze();
	while(scanf("%d%d%d",&n,&m,&d)!=EOF && !(n==0 && m==0 && d==0)){
		memset(Ans,false,sizeof(Ans));
		Finished=true;
		BackTrack(0);
		if(!Finished){
			printf("No anti-prime sequence exists.\n");
			continue;
		}
		printf("%d",ans[0]);
		for(int i=1; i<m-n+1; ++i)
			printf(",%d",ans[i]);
		printf("\n");
	}
	return 0;
}

void BackTrack(int loc){
	stack <int> Stk,tmp;
	for(int i=m; i>=n; --i) Stk.push(i);
	while(!Stk.empty()){
		int i=Stk.top();
		while(!Check(i,loc) ){
			tmp.push(i);
			Stk.pop();
			i=Stk.top();
		}
		Stk.pop();
		ans[loc++]=i;
		cout << i << endl;
	//	Ans[i]=true;
		while(!tmp.empty()){
			i=tmp.top();
			Stk.push(i);
			tmp.pop();
		}
	}
}

bool Check(int n, int p){
	if(!p) return true;
	int total=n;
	for(int i=p-1; i>=p-d; --i){
		if(i<0) return true;
		total+=ans[i];
		if(isPrime[total]) return false;
	}
	return true;
}
