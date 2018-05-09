#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double Dis[105][105];
double Loc[105][2];
bool Jud[105];
int Que[105];
int Que_n,n;
double ans;
double Min();
void MST();

int main(){
	bool blank=false;
	int Case;
	scanf("%d",&Case);
	for(int k=0; k<Case; k++){
		memset(Jud,true,sizeof(Jud));
		double x,y;
		Que_n=0; ans=0;
		scanf("%d",&n);
		for(int i=0; i<n; i++) scanf("%lf%lf",&Loc[i][0],&Loc[i][1]);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				int X=Loc[i][0]-Loc[j][0], Y=Loc[i][1]-Loc[j][1];
				Dis[i][j]=sqrt(X*X+Y*Y);
			}
/*		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("%6.2lf",Dis[i][j]);
			}	
			printf("\n");	
		}
		printf("\n");
*/		Que[Que_n++]=0;
		Jud[0]=false;
		MST();
		if(!blank)blank=true;
		else printf("\n");
		printf("%.2lf\n",ans);
	}
}

void MST(){
	while(Que_n<n){
		ans+=Min();
//		printf("%lf\n",ans);
	}
}

double Min(){
	double Mmin=1e9;
	int Back=-1;
	for(int i=0; i<Que_n; i++){
		int I=Que[i];
		for(int j=0; j<n; j++){
			if(j==I)continue;
			if(Jud[j] && Dis[I][j]<Mmin){
				Que[Que_n]=j; Back=j;
				Mmin=Dis[I][j];
//				printf("I:%d j:%d Mmin:%lf\n",I,j,Mmin);
			}
		}
	}
	Jud[Back]=false;
	Que_n++;
	return Mmin;
}
