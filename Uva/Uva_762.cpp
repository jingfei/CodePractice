#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

stack <int> Ans,tmp,Ans2;
bool Road[700][700];
bool Visited[700];
int Find=1e9;
void Dfs(int,int,int);

int main(){
	int n;
	bool Blank=false;
	while(scanf("%d",&n)!=EOF){
		if(!Blank)Blank=true;
		else printf("\n");
		memset(Road,false,sizeof(Road));
		Find=1e9;
		char city1[3],city2[3];
		getchar();
		while(n--){
			scanf("%s %s",city1,city2);
			getchar();
			int C1=(city1[0]-'A')*26+(city1[1]-'A'), C2=(city2[0]-'A')*26+(city2[1]-'A');
			Road[C1][C2]=true;
			Road[C2][C1]=true;
		}
		scanf("%s %s",city1,city2);
		getchar(); 
		int C1=(city1[0]-'A')*26+(city1[1]-'A'), C2=(city2[0]-'A')*26+(city2[1]-'A');
		while(!tmp.empty()) tmp.pop();
		while(!Ans2.empty()) Ans2.pop();
		while(!Ans.empty()) Ans.pop();
		tmp.push(C1);
		memset(Visited,false,sizeof(Visited));
		Dfs(C1,C2,1);
		while(!Ans.empty()){ Ans2.push(Ans.top()); Ans.pop(); }
		while(!Ans2.empty()){
			if(Ans2.top()==C2)break;
			int T=Ans2.top();
			char a=(char)(T/26)+'A',b=(char)(T%26)+'A';
			printf("%c%c ",a, b);
			Ans2.pop();
			T=Ans2.top();
			a=(char)(T/26)+'A'; b=(char)(T%26)+'A';
			printf("%c%c\n",a, b);
		}
		if(Find==1e9) printf("No route\n");
	}
	return 0;
}

void Dfs(int City1, int City2, int num){
	if(City1==City2){
   		if(Find>num){
			Find=num;
			Ans=tmp;
		}
		return;
	}
	int T=City1;
	char a=(char)(T/26)+'A', b=(char)(T%26)+'A';
//	printf("T:%d City:%c%c\n",T,a,b);
	Visited[City1]=true;
	for(int i=0; i<700; i++)
		if(Road[City1][i] && !Visited[i]){
			tmp.push(i);
			Dfs(i,City2,num+1);
			tmp.pop();
		}
}
