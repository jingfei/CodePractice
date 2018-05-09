#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

void cmp(struct Ar a,struct Ar b){
	return a.dis<b.dis;
}

struct Ar{
	int dis,fu,Stop,i;
	bool operator<(const struct Ar &t)const{
		return fu>t.fu;
	}
}ar[10010],Goal;
priority_queue <struct Ar> Que;

int main(){
	int N,Min=1e9;
	scanf("%d",&N);
	ar[0].dis=0; ar[0].fu=0; ar[0].Stop=1e9; ar[0].i=0;
	for(int i=1; i<=N; ++i){
		scanf("%d%d",&ar[i].dis,&ar[i].fu);
		ar[i].Stop=1e9;  
	}
	scanf("%d%d",&Goal.dis,&Goal.fu);
	Goal.Stop=0; Goal.i=N+1; 
	sort(ar+1,ar+N+1);
	Stk.push(Goal);
	while(!Stk.empty()){
		struct Ar T=Stk.top();
//		printf(" %d %d\n",F.i,F.Stop);
		Stk.pop();
		if(T.Stop-1>=Min) continue;
		if(T.i==0){
			if(T.Stop-1<Min) Min=T.Stop-1;
			continue;
		}
		for(int i=T.i-1; i>=0; --i){
			if(T.dis-ar[i].dis<=T.fu){
				struct Ar tmp;
				tmp.i=i; tmp.dis=ar[i].dis;
				tmp.fu=ar[i].fu+T.fu-T.dis+ar[i].dis;
				tmp.Stop=T.Stop+1;
				if(tmp.Stop<=ar[i].Stop){
					ar[i].Stop=tmp.Stop;
					Stk.push(tmp);
				}
			}
			else break;
		}
	}
	if(Min!=1e9) printf("%d\n",Min);
	else printf("-1\n");
	return 0;
}
