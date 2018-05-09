#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Dot{
	int N,an;
	int Len[1000];
	int ar[1000];
}Vec[1000];
int Num[1000],en;
bool Visit[1000];
double ans;

bool Dfs(int x,double Len,double mid){
//	printf("x: %d,xN: %d, ",x,Vec[x].N);
	Visit[x]=true;
	for(int i=0; i<Vec[x].N; ++i){
		int I=Vec[x].ar[i];
//		printf("I: %d ",I);
		if(Visit[I]){
			if(Len+(Vec[x].Len[I]-mid)>=0)
				return true;
		}
		else if(Dfs(I,Len+(Vec[x].Len[I]-mid),mid))
			return true;
	}
	Visit[x]=false;
	return false;
}

bool Find(double mid){
	memset(Visit,false,sizeof(Visit));
	for(int i=0; i<en; ++i){
		if(!Visit[i]){
//			printf("start %d: ",i);
			if(Dfs(i,0,mid))
				return true;
		}
	}
	return false;
}
//int Bin;
void Binary(double L,double R){
	while(100*(R-L)>1){
		double mid=(L+R)*0.5;
//		++Bin;
//		if(Bin>=10) return;
//		printf("mid: %lf\n",mid);
		bool CanBe=Find(mid);
//		printf("Canbe: %d, mid: %lf\n",CanBe,mid);
		if(CanBe){
			ans=L;
			L=mid;
		}
		else 
			R=mid;
	}
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF && n!=0){
		int Max=0; ans=0.0;
		int Ans2=0; en=0;
		double R=0.0;
		memset(Vec,0,sizeof(Vec));
		memset(Num,-1,sizeof(Num));
		while(n--){
			char s[1010];
			getchar(); scanf("%s",s);
			int Len=strlen(s);
			if(Len<=1) continue;
			R=max(R,(double)Len);
			int a=(s[0]-'a')*26+(s[1]-'a');
			int b=(s[Len-2]-'a')*26+(s[Len-1]-'a');
			if(Num[a]==-1) Num[a]=en++;
			if(Num[b]==-1) Num[b]=en++;
			a=Num[a]; b=Num[b];
			if(a==b){ Ans2=max(Ans2,Len); continue; }
			if(Vec[a].Len[b]==0){
				Vec[a].ar[Vec[a].N]=b;
				Vec[a].Len[b]=Len;
				++Vec[a].N;
			}
			else Vec[a].Len[b]=max(Vec[a].Len[b],Len);
//			printf("%d %d\n",a,b);
			Max=max(Max,Len);
		}
		Binary(ans,R);
//		for(int i=0; i<Vec[217].N; ++i)
//			printf("%d ",Vec[217].ar[i]);
//		printf("\n");
//		ans*=100;
		if(ans==0.0){
			if(Ans2==0) printf("No solution.\n");
			else printf("%.2lf\n",(double)Ans2);
		}
//		else printf("%.2lf\n",floor(ans)/100.0);
		else printf("%.2lf\n",max((double)Ans2,ans));
	}
	return 0;
}

