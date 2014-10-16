#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

struct edge{
	int v,next;
}e[10000];
int rank[1100][25];
int Barn[25];
int first[1100];
bool vx[1100];
int Mx[1100][25];
int Now[25];
int N,B,en;

bool Augument(int y){
	for(int x=first[y]; x!=-1; x=e[x].next){
		int i=e[x].v;
		if(!vx[i]){
			vx[i]=true;
			if(Now[i]<Barn[i]){
				Mx[i][Now[i]++]=y;
				return true;
			}
			for(int k=0; k<Now[i]; k++){
				if(Augument(Mx[i][k])){
					Mx[i][k]=y;
					return true;
				}
			}
		}
	}
	return false;
}

bool Matching(){
	for(int i=0; i<N; i++){
		memset(vx,false,sizeof(vx));
		if(!Augument(i)) return false;
	}
	return true;
}

bool canbe(int mid){
	memset(Now,0,sizeof(Now));
	memset(first,-1,sizeof(first));
	en=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<mid; j++){
			e[en].v=rank[i][j]-1; e[en].next=first[i]; first[i]=en++;
		}
	}
	bool tmp=Matching();
	if(tmp) return true;
	return false;
}

int Binary(int L,int R){
	int mid;
	while(L<R){
		mid=(L+R)>>1;
		if(canbe(mid)) R=mid;
		else L=mid+1;
	}
	return R;
}

int main(){
	while(scanf("%d%d",&N,&B)!=EOF){
		for(int i=0; i<N; i++)
			for(int j=0; j<B; j++)
				scanf("%d",&rank[i][j]);
		for(int i=0; i<B; i++) scanf("%d",&Barn[i]);
		int ans=Binary(0,B+1);
		if(ans<1) printf("1\n");
		else printf("%d\n",ans);
	}
	return 0;	
}
