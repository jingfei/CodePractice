#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char num[10][10]={"1111110","0110000","1101101","1111001","0110011","1011011","1011111","1110000","1111111","1111011"};
char s[10][15];
int N;

bool cmp(int sn,int Max,bool Burn[]){
	if(sn==N) return true;
	bool tmp[10];
	int i=Max-1; 
		bool Pair=true;
		for(int j=0; j<7; ++j) tmp[j]=Burn[j];
		for(int j=0; j<7; ++j){
			if(s[sn][j]=='Y' && tmp[j]){
				Pair=false; break;
			}
			else if(num[i][j]=='0' && s[sn][j]=='Y'){
				Pair=false; break;
			}
			else if(num[i][j]=='1' && s[sn][j]=='N'){
				tmp[j]=true;
			}
		}
		if(Pair && cmp(sn+1,i,tmp))
			return true;
	return false;
}

int main(){
	while(scanf("%d",&N)!=EOF && N){
		getchar();
		int Max=10;
		for(int i=0; i<N; ++i){
			scanf("%s",s[i]); getchar();
		}
		bool last[10],tmp[10],Match=false;
		for(int i=9; i>=N-1; --i){
			bool Pair=true;
			memset(tmp,false,sizeof(tmp));
			for(int j=0; j<7; ++j){
				if(num[i][j]=='0' && s[0][j]=='Y'){
					Pair=false; break;
				}
				else if(num[i][j]=='1' && s[0][j]=='N'){
					tmp[j]=true;
				}
			}
			if(Pair && cmp(1,i,tmp)){
				Match=true; 
				break;
			} 
		}
		if(Match) printf("MATCH\n");
		else printf("MISMATCH\n");
	}
	return 0;
}
