#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int main(){
	int T; scanf("%d",&T); getchar();
	for(int Case=1; Case<=T; ++Case){
		int N; scanf("%d",&N);
		int n=0,ans=0;
		string a,b;
		map<string,int> mymap;
		map<string,int>::iterator it;
		while(N--){
			cin >> a >> b;
			int pa=-1,pb=-1;
			it=mymap.find(a);
			if(it==mymap.end()) 
				mymap.insert(pair<string,int>(a,n++));
			else pa=(*it).second;
			it=mymap.find(b);
			if(it==mymap.end()) mymap.insert(pair<string,int>(b,n++));
			else pb=(*it).second;
			if(pa>-1 && pb>-1){
				if(pa%2==0 && pb%2==1) ++ans;
			}
		}
		printf("Case #%d: %d\n",Case,ans);
	}
	return 0;
}
