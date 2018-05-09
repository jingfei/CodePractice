#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map <string,int> Map;
map <int,string> Map2;

int main(){
	string s;
	while(cin>>s){
		Map.clear();
		Map2.clear();
		int a[105],b[105],an=1,bn=1;
		int num=0;
		do{
			map <string,int>::iterator it;
			it=Map.find(s);
			if(it==Map.end()){
				Map.insert(pair<string,int>(s,num++));
				Map2.insert(pair<int,string>(num-1,s));
				a[an++]=num-1;
			}
			else a[an++]=(*it).second;
		}while(cin>>s && s!="#");
		while(cin >> s && s!="#"){
			map <string,int>::iterator it;
			it=Map.find(s);
			if(it==Map.end()){
				Map.insert(pair<string,int>(s,num++));
				Map2.insert(pair<int,string>(num-1,s));
				b[bn++]=num-1;
			}
			else b[bn++]=(*it).second;
		}
		int dp[105][105][105]={{0}};
		for(int i=1; i<an; i++){
			for(int j=1; j<bn; j++){
				int A=dp[i][j-1][0],B=dp[i-1][j][0],C=0;
				if(a[i]==b[j]){C=dp[i-1][j-1][0]+1;}
				if(C>=A && C>=B){
					for(int k=1; k<=dp[i-1][j-1][0]; k++)
						dp[i][j][++dp[i][j][0]]=dp[i-1][j-1][k];
					if(C)dp[i][j][++dp[i][j][0]]=a[i];
				}
				else if(B>=A)
					for(int k=1; k<=dp[i-1][j][0]; k++)
						dp[i][j][++dp[i][j][0]]=dp[i-1][j][k];
				else
					for(int k=1; k<=dp[i][j-1][0]; k++)
						dp[i][j][++dp[i][j][0]]=dp[i][j-1][k];
			}
		}
		for(int i=1; i<dp[an-1][bn-1][0]; i++){
			map <int,string>::iterator it;
			it=Map2.find(dp[an-1][bn-1][i]);
			cout << (*it).second << ' ';
		}
		if(dp[an-1][bn-1][0]){
			map <int,string>::iterator it;
			it=Map2.find(dp[an-1][bn-1][dp[an-1][bn-1][0]]);
			cout << (*it).second << endl;
		}
	}
	return 0;
}
