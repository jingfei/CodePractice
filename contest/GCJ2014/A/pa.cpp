#include <iostream>
#include <cstdio>
using namespace std;

int ar1[4][4],ar2[4][4];

int main(){
	int T; scanf("%d",&T);
	for(int Case=1; Case<=T; ++Case){
		int c1,c2;
		scanf("%d",&c1);
		for(int i=0; i<4; ++i) for(int j=0; j<4; ++j) scanf("%d",&ar1[i][j]);
		scanf("%d",&c2);
		for(int i=0; i<4; ++i) for(int j=0; j<4; ++j) scanf("%d",&ar2[i][j]);
		int tmp=-1; --c1; --c2;
		for(int i=0; i<4; ++i)
			for(int j=0; j<4; ++j)
				if(ar1[c1][i]==ar2[c2][j]){
					if(tmp==-1) tmp=ar1[c1][i];
					else{ tmp=-2; break; }
				}
		printf("Case #%d: ",Case);
		if(tmp==-1) printf("Volunteer cheated!\n");
		else if(tmp==-2) printf("Bad magician!\n");
		else printf("%d\n",tmp);
	}
	return 0;
}
