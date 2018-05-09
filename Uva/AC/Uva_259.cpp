#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int Num[50],Y,X;
bool ar[50][50];
int Mx[50][50];
int peo[50];
bool vx[50];

bool Augument(int y){
	for(int i=0; i<X; ++i){
		if(!ar[y][i] || Num[i]==0) continue;
		if(!vx[i]){
			vx[i]=true;
			if(peo[i]<Num[i]){
				Mx[i][peo[i]++]=y;
				return true;
			}
			for(int k=0; k<peo[i]; ++k)
				if(Augument(Mx[i][k])){
					Mx[i][k]=y;
					return true;
				}
		}
	}
	return false;
}

bool Matching(){
	for(int i=0; i<Y; ++i){
		memset(vx,false,sizeof(vx));
		Augument(i);
	}
	return true;
}

int main(){
	char s2[20];
	char a=0,b;
		memset(ar,false,sizeof(ar));
		memset(peo,0,sizeof(peo));
		memset(Num,0,sizeof(Num));
		memset(Mx,0,sizeof(Mx));
		Y=10; X=26;
	a=getchar();
	while(a!=EOF){
		b=getchar();
		getchar();
		scanf("%s",s2);
		Num[a-'A']=b-'0';
//		printf("%c %c\n",a,b);
		int Len=strlen(s2)-1;
		for(int i=0; i<Len; ++i)
			ar[s2[i]-'0'][a-'A']=true;
		getchar();
		a=getchar();
		if(a=='\n'){
			Matching();
			int Ans=true;
			for(int i=0; i<26; ++i)
				if(peo[i]!=Num[i]){ Ans=false; break;}
			if(!Ans) printf("!\n");
			else{
				char ans[10]={0};
				for(int i=0; i<26; ++i){
					for(int j=0; j<peo[i]; ++j)
						ans[Mx[i][j]]=i+'A';
				}
				for(int i=0; i<10; ++i){
					if(ans[i]) printf("%c",ans[i]);
					else printf("_");
				}
				printf("\n");
			}
			a=getchar();
			memset(ar,false,sizeof(ar));
			memset(peo,false,sizeof(peo));
			memset(Num,0,sizeof(Num));
			memset(Mx,0,sizeof(Mx));
		}
	}
			Matching();
			int Ans=true;
			for(int i=0; i<26; ++i)
				if(peo[i]!=Num[i]){ Ans=false; break;}
			if(!Ans) printf("!\n");
			else{
				char ans[10]={0};
				for(int i=0; i<26; ++i){
					for(int j=0; j<peo[i]; ++j)
						ans[Mx[i][j]]=i+'A';
				}
				for(int i=0; i<10; ++i){
					if(ans[i]) printf("%c",ans[i]);
					else printf("_");
				}
				printf("\n");
			}
	return 0;
}
