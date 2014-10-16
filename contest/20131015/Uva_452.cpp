#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct ar{
	int time; int task;
	int T[30];
}ar[30];
int Back(int);

int main(){
	int N; char s[10000];
	int Go[100],Gn=0;
	scanf("%d",&N); 
	getchar(); getchar();
	for(int I=0; I<N; ++I){
		if(I!=0) printf("\n");
		while(fgets(s,sizeof(s),stdin)!=0){
			if(!strcmp(s,"\n")) break;
			int Tmp=s[0]-'A'; 
			int tmp=0,l; int Len=strlen(s)-1;
			for(int i=2; ;++i){
				l=i;
				if(s[i]==' ' || s[i]=='\n') break;
				tmp=tmp*10+(s[i]-'0');
			}
			ar[Tmp].time=tmp;
			for(int i=l+1; i<Len; ++i) ar[s[i]-'A'].T[ar[s[i]-'A'].task++]=Tmp;
			if(Len==l) Go[Gn++]=Tmp;
		}
		int Ans=0;
		for(int i=0; i<Gn; ++i) Ans=max(Ans,Back(Go[i]));
		printf("%d\n",Ans);
	}
	return 0;
}

int Back(int n){
	int ans=ar[n].time;
	int Task=ar[n].task,tmp=0;
	if(Task==0) return ans;
	for(int i=0; i<Task; ++i)
		tmp=max(tmp,Back(ar[n].T[i]));
	return ans+tmp;
}


