#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct Num{
	long long int up,down;
};

struct Num ans;
bool Cmp(struct Num,struct Num);
long long int G(long long int,long long int);
void Find(int,int,int,struct Num,struct Num,struct Num);
struct Num Simple(struct Num);
struct Num dis(struct Num,struct Num);

int main(){
	struct Num zero,one;
	zero.up=0; zero.down=1; one.up=1; one.down=1;
	int N,k,r,s; bool blank=false;
	while(scanf("%d%d%d%d",&N,&k,&r,&s)!=EOF){
		if(blank) printf("\n");
		else blank=true;
		while(N--){
			struct Num n; scanf("%lld/%lld",&n.up,&n.down);
			if(n.down==1){
				if(n.up==0 || n.up==1){printf("%lld/%lld\n",n.up,n.down); continue;}
			}
			n=Simple(n);
			Find(r,s,k,n,zero,one);
			ans=Simple(ans);
			printf("%lld/%lld\n",ans.up,ans.down);
		}
	}
	return 0;
}

void Find(int r,int s,int k,struct Num n,struct Num L,struct Num R){
//	printf("k:%d L:%d/%d R:%d/%d\n",k,L.up,L.down,R.up,R.down);
	if(k==0){
		if(Cmp(dis(n,L),dis(n,R))){ans.up=L.up; ans.down=L.down;}
		else {ans.up=R.up; ans.down=R.down;}
		return;
	}
	struct Num now;
	long long int Down=G(L.down,R.down); 
	long long int Lup=Down/L.down*L.up, Rup=Down/R.down*R.up;
	long long int tmp1=G(Lup+Rup,r+s);
	long long int tmp=tmp1/(Lup+Rup);
	Lup*=tmp; Rup*=tmp;
	Down*=tmp;
	now.down=Down; now.up=(Lup+Rup)/(r+s)*r;
	now=Simple(now);
//	printf("now:%d/%d\n",now.up,now.down);
	if(now.up==n.up && now.down==n.down){ans=now; return;}
	if(Cmp(n,now)) Find(r,s,k-1,n,L,now);
	else Find(r,s,k-1,n,now,R);
}

struct Num dis(struct Num a, struct Num b){
	long long int Down=G(a.down,b.down);
	long long int A=Down/a.down*a.up,B=Down/b.down*b.up;
	struct Num tmp;
	tmp.down=Down;
	tmp.up=abs((double)(A-B));
//	tmp=Simple(tmp);
	return tmp;
}

long long int G(long long int a,long long int b){
	long long int A=a, B=b;
	if(a>b){long long int tmp=a; a=b; b=tmp;}
	while(a){
		long long int c=b%a;
		b=a; a=c;
	}
	return A/b*B;
}

bool Cmp(struct Num a,struct Num b){  //small->true
	long long int Down=G(a.down,b.down);
	long long int A=Down/a.down*a.up, B=Down/b.down*b.up;
	return A<B;
}


struct Num Simple(struct Num n){
	if(n.up==0){n.down=1; return n;}
	long long int x=(n.up>n.down?n.up:n.down);
	long long int U=n.up, D=n.down;
	for(int i=2; i<=sqrt(x); ++i){
		while(x%i==0){
			if(U%i==0 && D%i==0){U/=i; D/=i;}
			x/=i;
		}
		if(x==1) break;
	}
	n.up=U; n.down=D;
	return n;
}
