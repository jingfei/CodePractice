#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int Num[1000],en;
int Dis[1000];
int First[1000];
bool Visit[1000];
double ans;

bool Dfs(int x,double Len,double mid){
	for(int I=x; I!=-1; I=First[I]){
		Visit[I]=true;
		if(Len+(Dis[I]-mid)>=0)
			return true;
		if(Dfs(I,Len+(Dis[I]-mid),mid))
			return true;
	}
	return false;
}

bool Find(double mid){
	memset(Visit,false,sizeof(Visit));
	for(int i=0; i<en; ++i){
//		if(!Visit[i]){
			if(Dfs(i,0,mid))
				return true;
//		}
	}
	return false;
}

void Binary(double L,double R){
	while(100*(R-L)>1){
		double mid=(L+R)*0.5;
		bool CanBe=Find(mid);
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
		ans=0.0;
		int Ans2=0; en=0;
		double R=0.0;
		memset(Num,-1,sizeof(Num));
		memset(First,-1,sizeof(First));
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
			First[b]=a;
			Dis[b]=Len;
		}
		Binary(ans,R);
		if(ans==0.0){
			if(Ans2==0) printf("No solution.\n");
			else printf("%.2lf\n",(double)Ans2);
		}
		else printf("%.2lf\n",max((double)Ans2,ans));
	}
	return 0;
}

