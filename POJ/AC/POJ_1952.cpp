#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

int n,p;
int ar[5050];
int tmp[5050];
int dp[5050];
void Dfs(int,int,int);
int Ans;
map <vector<int>,int> Map;
vector <int> v;

int main(){
	while(scanf("%d",&n)!=EOF){
		v.clear();
		Map.clear();
		for(int i=n-1; i>=0; --i) scanf("%d",&ar[i]);
		p=0;
		tmp[p++]=ar[0];
		dp[0]=1;
		for(int i=1; i<n; ++i){
			if(ar[i]>tmp[p-1]){
				tmp[p++]=ar[i];
				dp[i]=p;
			}
			else{
				int temp=lower_bound(tmp,tmp+p,ar[i])-tmp;
				tmp[temp]=ar[i];
				dp[i]=temp+1;
			}
		}
		dp[n]=p+1;
		ar[n]=1e9;
//		for(int i=0; i<=n; ++i) printf("%d ",dp[i]); printf("\n");
		int Count[5050];
		for(int i=0; i<=n; ++i){
			if(dp[i]==1){
				Count[i]=1;
				for(int j=i-1; j>=0; --j)
					if(ar[i]==ar[j]){
						Count[j]=0; break;
					}
			}
			else{
				Count[i]=0;
				for(int j=i-1; j>=0; --j){
					if(dp[i]==dp[j] && ar[i]==ar[j]){
						Count[j]=0; dp[j]=0;
					}
					if(ar[j]<ar[i] && dp[j]==dp[i]-1) Count[i]+=Count[j];
				}
			}
//			printf("%d:%d ",i,Count[i]);
		}
//		for(int i=0; i<=n; ++i) printf("%d ",Count[i]); printf("\n");
		printf("%d %d\n",p,Count[n]);
	}
	return 0;
}

void Dfs(int index,int value,int dep){
	if(dep==p){ 
		map <vector<int>,int>::iterator it;
		it=Map.find(v);
		if(it==Map.end())
			Map.insert(pair<vector <int>,int>(v,++Ans));
		return;
	}
	for(int i=index; i<n; ++i){
		if(i>n-p+dep) break;
		if(ar[i]>value){
			v.push_back(ar[i]);
			Dfs(i+1,ar[i],dep+1);
			v.pop_back();
		}
	}
}
