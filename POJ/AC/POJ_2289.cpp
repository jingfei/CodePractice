#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge{
	int v,next;
}e[1010*510];
int N,M,en;
int Binary(int L,int R);
bool canbe(int mid);
bool Matching(int Max);
bool Augument(int y,int Max);
int first[1010];
int peo[1010];
int Mx[510][1010];
bool vx[2000];
int end;

int main(){
	while(scanf("%d%d",&N,&M)!=EOF && !(N==0 && M==0)){
		getchar();
		en=0;
		memset(first,-1,sizeof(first));
		for(int j=0; j<N; j++){
			char s[2000];
			fgets(s,2000,stdin);
			int Len=strlen(s),tmp=0;
			bool start=false;
			for(int i=0; i<Len; i++){
				if(s[i]>='0' && s[i]<='9'){
					start=true;
					tmp=tmp*10+(s[i]-'0');
				}
				else if(s[i]==' ' && start){ 
					e[en].v=tmp; e[en].next=first[j]; first[j]=en++;
					tmp=0;
					start=false;
				}
			}
			if(start) 
				e[en].v=tmp; e[en].next=first[j]; first[j]=en++;
		}
		int ans=Binary(0,N);
		printf("%d\n",ans);
	}
	return 0;
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

bool canbe(int mid){
	memset(peo,0,sizeof(peo));
	bool tmp=Matching(mid);
//	printf("mid:%d Matching:%d\n",mid,tmp);
//	printf("MY: ");
//	for(int i=M; i<M+N; i++) printf("%d ",my[i]); printf("\n");
	if(tmp) return true;
	return false;
}

bool Matching(int Max){
	for(int i=0; i<N; i++){
			memset(vx,false,sizeof(vx));
			if(!Augument(i,Max)){
				return false;
			}
	}
	return true;
}

bool Augument(int y,int Max){
	for(int x=first[y]; x!=-1; x=e[x].next){
		int i=e[x].v;
		if(!vx[i]){
			vx[i]=true;
			if(peo[i]<Max){
				Mx[i][peo[i]++]=y;
				return true;
			}
			for(int k=0; k<peo[i]; k++)
				if(Augument(Mx[i][k],Max)){
					Mx[i][k]=y;
					return true; 
				}
		}
	}
	return false;
}

