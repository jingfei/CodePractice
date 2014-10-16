#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

queue <char> Q;
int n;
void Dfs(int t);

int main(){
	while(scanf("%d",&n)!=EOF){
		Dfs(0);	
	}
	return 0;
}

void Dfs(int n){
	Q.push('(');
	
}

