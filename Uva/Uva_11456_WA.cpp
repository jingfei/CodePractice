#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,x;
		scanf("%d",&n);
		if(n==0){printf("0\n"); continue;}
		scanf("%d",&x);
		vector <int> v;
		v.push_back(x);
		n--;
		while(n--){
			scanf("%d",&x);
			if(x<v[0]) v.insert(v.begin(),x);
			else if(x>v[v.size()-1]) v.push_back(x);
			else *lower_bound(v.begin(),v.end(),x)=x;
		}
		printf("%d\n",v.size());
	}
	return 0;
}
