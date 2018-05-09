#include <iostream>
#include <cstdio>
#define Max 16000010
#include <cstring>
#include <vector>
using namespace std;

char s[Max];
int W[1000],wn;
bool Num[Max];

int main(){
	int N,p,ans=0; wn=0;
	memset(W,-1,sizeof(W));
	memset(Num,false,sizeof(Num));
	scanf("%d%d",&N,&p);
	getchar(); scanf("%s",s);
	int Len=strlen(s);
	int temp=1,tmp=0; 
	for(int i=0; i<=Len-N; ++i){
		if(i==0){
			for(int j=i; j<N+i; ++j){
				if(i!=j) temp*=p;
				if(W[s[j]]==-1) W[s[j]]=wn++;
				tmp+=(W[s[j]]*temp);
			}
		}
		else{
			if(W[s[i+N-1]]==-1) W[s[i+N-1]]=wn++;
			tmp-=W[s[i-1]];
			tmp/=p;
			tmp+=(W[s[i+N-1]]*temp);
		}
		if(!Num[tmp]){ Num[tmp]=true; ++ans;}
	}
	printf("%d\n",ans);
	return 0;
}

