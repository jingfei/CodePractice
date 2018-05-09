#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[1501][300];
char ans[300];
int ar[100],Long;

int Single(int i,int j){
	char x=s[i][j-1];
	if(x=='h'){
		char y=s[i][j-2];
		if(y=='c' || y=='s' || y=='p') return j-2;
		else return j-1;
	}
	return j-1;
}

void Add(int Remain,int i){
	int Len=strlen(s[i]);
	bool Sym=false;
	int an=0;
	if(s[i][Len-1]=='.' || s[i][Len-1]==','){ --Len; Sym=true; }
	for(int j=0; j<Len-1; ++j){
		if(s[i][j]=='a' || s[i][j]=='e' || s[i][j]=='i' || s[i][j]=='o' || s[i][j]=='u'){
			if(j==0) ar[an++]=j;
			else if(s[i][j-1]=='a' || s[i][j-1]=='e' || s[i][j-1]=='i' || s[i][j-1]=='o' || s[i][j-1]=='u') continue;
			else ar[an++]=j;
		}
	}
	if(s[i][Len-1]=='a' || s[i][Len-1]=='y' || s[i][Len-1]=='i' || s[i][Len-1]=='o' || s[i][Len-1]=='u') ar[an++]=Len-1;
	for(int j=1; j<an; ++j){
		ar[j-1]=Single(i,ar[j]);
	}
	--an;
	if(Sym) ++Len;
	int p;
	int aLen=strlen(ans);
	if(an<=0){ p=-1; --aLen;}
	else ar[an-1]--;
	for(int j=0; j<an; ++j){
		if(Remain<ar[j]+1){
			if(j==0) p=-1;
			else p=ar[j-1];
			break;
		}
	}
	int blank=Remain;
	if(an<=0) ++blank;
	else if(p!=-1) blank=Remain-p-1;
	else if(p==-1){ --aLen; ++blank;}
	string ss="";
	for(int j=aLen-1; j>=0; --j){
		if(ans[j]!=' '){
			ss=ans[j]+ss;
			continue;
		}
		if(blank==0){
			ss=ans[j]+ss;
			continue;
		}
		--blank;
		ss="  "+ss;
	}
/*	int aa=2;
	while(blank>0){
		++aa;
		aLen=strlen(ans);
		if(p==-1) --aLen;
		ss="";
		for(int j=aLen-1; j>=0; --j){
			if(ans[j]!=' '){
				ss=ans[j]+ss;
				continue;
			}
			if(blank==0 && ans[j]==' '){
				string xx="";
				for(int h=1; h<aa; ++h) xx+=" ";
					ss=xx+ss;
				continue;
			}
			if(blank==0){
				ss=ans[j]+ss;
				continue;
			}
			--blank;
			string xx="";
			for(int h=0; h<aa; ++h) xx+=" ";
			ss=xx+ss;
		}
	}
*/	if(p!=-1){
		for(int j=0; j<p; ++j)
			ss+=s[i][j];
		ss+='-';
	}
	cout << ss << endl;
	if(p==-1){
		strcpy(ans,s[i]);
		strcat(ans," ");
		Long=strlen(s[i])+1;
	}
	else{
		strcpy(ans,"");
		for(int j=0,k=p; k<=Len; ++j,++k){
			ans[j]=s[i][k];
		}
		strcat(ans," ");
		Long=strlen(ans);
	}
}

int main(){
	int n,sn=0;
	scanf("%d",&n);
	char tmp[300];
	if(n==0) return 0;
	while(scanf("%s",tmp)!=EOF){
		strcpy(s[sn++],tmp);
	}
	strcpy(ans,"");
	Long=0;
	for(int i=0; i<sn; ++i){
		int Len=strlen(s[i]);
		if(Long+Len<n){
			Long+=(Len+1);
			strcat(ans,s[i]);
			strcat(ans," ");
		}
		else if(Long+Len==n){
			printf("%s",ans);
			printf("%s\n",s[i]);
			strcpy(ans,"");
			Long=0;
		}
		else{
			int Remain=n-Long;
			Add(Remain,i);
		}
	}
	if(Long!=0){
		int Len=strlen(ans);
		char Ans[300];
		for(int i=0; i<Len-1; ++i) Ans[i]=ans[i];
		Ans[Len-1]=ans[Len];
		printf("%s\n",Ans);
	}
	return 0;
}
