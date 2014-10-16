#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

struct Dot{
	int y,x;
	int loc;
	bool operator<(const struct Dot &t)const{
		if(loc==t.loc) return (double)y/(double)x<(double)t.y/(double)t.x;
		return loc<t.loc;
	}
}D[100];
bool Check(struct Dot,struct Dot,struct Dot);
bool LOC[4];
stack <struct Dot> stk;

int main(){
	int a,b,dn=0;
	memset(LOC,false,sizeof(LOC));
	while(scanf("%d%d",&a,&b)!=EOF){
		D[dn].x=a; D[dn].y=b;
		if(a>0 && b>0){D[dn++].loc=0; LOC[0]=true;}
		else if(a>0){D[dn++].loc=3; LOC[3]=true;}
		else if(b<0){D[dn++].loc=2; LOC[2]=true;}
		else if(b>0){D[dn++].loc=1; LOC[1]=true;}
		else D[dn++].loc=0;
	}
	sort(D+1,D+dn);
//	for(int i=0; i<dn; ++i) printf("%d,%d\n",D[i].x,D[i].y);
	stk.push(D[0]); stk.push(D[1]);
	for(int i=2; i<dn; ++i){
		struct Dot A,B,C;
		C=D[i]; B=stk.top(); stk.pop();
		A=stk.top();
		if(!Check(A,B,C)) stk.push(C);
		else{stk.push(B); stk.push(C);}
	}
	stack <struct Dot> stk1,stk2,stk3,stk0;
	int Start;
	for(int i=0; i<4; ++i){
		if(!LOC[i]) Start=i;
	}
	while(!stk.empty()){
		int X=stk.top().x,Y=stk.top().y;
		if(X>0 && Y>0){ stk0.push(stk.top()); stk.pop(); }
		else if(X<0 && Y>0){ stk1.push(stk.top()); stk.pop(); }
		else if(X<0 && Y<0){ stk2.push(stk.top()); stk.pop(); }
		else if(X>0 && Y<0){ stk3.push(stk.top()); stk.pop(); }
		else break;
	}
	printf("(0,0)\n");
	int tmp=Start+1;
	if(tmp>3) tmp-=4;
	while(tmp!=Start){
		if(tmp==0)
			while(!stk0.empty()){
				printf("(%d,%d)\n",stk0.top().x,stk0.top().y);
				stk0.pop();
			}
		else if(tmp==1)
			while(!stk1.empty()){
				printf("(%d,%d)\n",stk1.top().x,stk1.top().y);
				stk1.pop();
			}
		else if(tmp==2)
			while(!stk2.empty()){
				printf("(%d,%d)\n",stk2.top().x,stk2.top().y);
				stk2.pop();
			}
		else
			while(!stk3.empty()){
				printf("(%d,%d)\n",stk3.top().x,stk3.top().y);
				stk3.pop();
			}
		++tmp;
		if(tmp>3) tmp-=4;
	}
	return 0;
}

bool Check(struct Dot A,struct Dot B,struct Dot C){
	int x1=B.x-A.x,x2=C.x-A.x,y1=B.y-A.y,y2=C.y-A.y;
	if(x1*y2-x2*y1<0) return false;
	return true;
}

