#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int ar[100010][2];
int an;
bool V[100010];
void PutIn(int,int,bool);

int main(){
	int T; scanf("%d",&T);
	while(T--){
		an=0;
		int N; scanf("%d",&N);
		bool First=true;
		while(N--){
			int x; scanf("%d",&x);
			memset(V,false,sizeof(V));
			while(x--){
				int a,b; scanf("%d%d",&a,&b);
				PutIn(a,b,First);
				if(First) First=false;
				for(int i=0; i<an; ++i)
					if(!V[i])
						ar[i][0]=ar[i][1]=0;
			}
		}
		bool Ans=false;
		for(int i=0; i<an; ++i)
			if(ar[i][0]!=ar[i][1]){Ans=true; break;}
		if(Ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

void PutIn(int a,int b,bool Put){
	int In=false;
	for(int i=0; i<an; ++i){
		if(a>=ar[i][1] || b<=ar[i][0]) continue;
		V[i]=true;
		if(a>=ar[i][0]){
			if(b<=ar[i][1]){
				ar[i][0]=a; ar[i][1]=b;
			}
			else{
				ar[i][0]=a;
				PutIn(ar[i][1],b,false);
			}
			In=true;
		}
		else{
			if(b<=ar[i][1]){
				ar[i][1]=b;
				PutIn(a,ar[i][0],false);
			}
			else{
				PutIn(ar[i][1],b,false);
				PutIn(a,ar[i][0],false);
			}
			In=true;
		}
	}
//		for(int i=0; i<an; ++i){
//			printf("%d %d\n",ar[i][0],ar[i][1]);
//		}
//		printf("\n");
	if(!In && Put){ ar[an][0]=a; ar[an][1]=b; V[an++]=true;}
}

