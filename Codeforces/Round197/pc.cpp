#include <iostream>
#include <cstdio>
using namespace std;

int ans[1010];

int main(){
	char s[12];
	int m,an=0,ls=0,rs=0,sn=0,Suc=true,pre=-1,first=-1,last=-1;
	bool Scale[11];
	scanf("%s",s); getchar(); scanf("%d",&m);
	for(int i=1; i<=10; ++i){
		Scale[i]=(s[i-1]=='0'?false:true);
		if(Scale[i] && first==-1) first=i;
		else if(Scale[i]) last=i;
	}
	if(last==-1 && m>1){Suc=false; m=0;}
	else if(last==-1) m=0;
	--m; pre=first; ls=pre; ans[an++]=pre;
	for(int i=0; i<m; ++i){
		int tmp=-1;
		if(i%2==0){ //right
			if(ls-rs>=last){Suc=false; break;}
			for(int i=ls-rs+1; i<=last; ++i){
				if(i==pre) continue;
				else if(Scale[i]){tmp=i; rs+=i; break;} 
			}
		}
		else{ //left
			if(rs-ls>=last){Suc=false; break;}
			for(int i=rs-ls+1; i<=last; ++i){
				if(i==pre) continue;
				else if(Scale[i]){tmp=i; ls+=i; break;}
			}
		}
		if(tmp==-1){Suc=false; break;}
		ans[an++]=tmp; pre=tmp;
	}
	if(!Suc) printf("NO\n");
	else{
		printf("YES\n");
		for(int i=0; i<an-1; ++i) printf("%d ",ans[i]);
		printf("%d\n",ans[an-1]);
	}
	return 0;
}
