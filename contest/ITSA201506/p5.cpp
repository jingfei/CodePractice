#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int ar[6];
int ans;
string str;
int s[6];

void dfs(int dep,int x){
	if(dep==6){
		int total=0;
		int tmpans=0;
		int n=0;
		for(int i=0; i<6; i++)
			if(s[i]){
				++n;
				tmpans=i;
				total+=ar[i];
			}
		tmpans-=n; ++tmpans;
		if(total==x && tmpans<ans){
			ans=tmpans;
			string tmps;
			stringstream ss(tmps);
			ss << "The best combination is ";
			for(int i=0; i<6; ++i)
				if(s[i])
					ss << ar[i] << ", ";
			ss << "Complaint=" << tmpans << endl;
			str = ss.str();
		}
		return ;
	}
	s[dep] = 1;
	dfs(dep+1,x);
	s[dep] = 0;
	dfs(dep+1,x);
}

int main(){
	int T; scanf("%d",&T);
	while(T--){
		ans=100;
		scanf("%d,%d,%d,%d,%d,%d",&ar[0],&ar[1],&ar[2],&ar[3],&ar[4],&ar[5]);
		int n=6;
		do{
			dfs(0,n);
			--n;
		}while(ans==100);
		cout << str;
	}
	return 0;
}
