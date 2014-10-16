#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct Dot{
	double x1,y1,x2,y2;
	int Num;
};

vector <struct Dot> D;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF && n!=0){
		double x1,x2,y1,y2;
		D.clear();
		for(int i=0; i<n; ++i){
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			for(int j=0; j<D.size(); ++j){
				double x3=D[j].x1,x4=D[j].x2,y3=D[j].y1,y4=D[j].y2;
				double X12=x2-x1,Y12=y2-y1,X13=x3-x1,Y13=y3-y1,X14=x4-x1,Y14=y4-y1;	
				double X34=x4-x3,Y34=y4-y3,X31=x1-x3,Y31=y1-y3,X32=x2-x3,Y32=y2-y3;	
				if(((X12*Y13)-(X13*Y12))*((X12*Y14)-(X14*Y12))<0 && ((X34*Y31)-(X31*Y34))*((X34*Y32)-(X32*Y34))<0){ //互相外積都小於0 （代表兩者相交）
					D.erase(D.begin()+j);
					--j;  //vector 會往前移
				}
				else if((x4-x3)*(y2-y1)==(x2-x1)*(y4-y3) && (x3-x2)*(y2-y1)==(x2-x1)*(y3-y2)){ //如果在同一直線上 （再判斷有沒有相交）
					if(min(x1,x2)<=x3 && x3<=max(x1,x2) && min(y1,y2)<=y3 && y3<=max(y1,y2)){ D.erase(D.begin()+j); --j;}
					else if(min(x1,x2)<=x4 && x4<=max(x1,x2) && min(y1,y2)<=y4 && y4<=max(y1,y2)){ D.erase(D.begin()+j); --j;}
					else if(min(x3,x4)<=x1 && x1<=max(x3,x4) && min(y3,y4)<=y1 && y1<=max(y3,y4)){ D.erase(D.begin()+j); --j;}
					else if(min(x3,x4)<=x2 && x2<=max(x3,x4) && min(y3,y4)<=y2 && y2<=max(y3,y4)){ D.erase(D.begin()+j); --j;}
				}
			}
			struct Dot Tmp;
			Tmp.x1=x1; Tmp.x2=x2; Tmp.y1=y1; Tmp.y2=y2; Tmp.Num=i+1;
			D.push_back(Tmp);
		}
		printf("Top sticks:");
		for(int i=0; i<D.size()-1; ++i)
				printf(" %d,",D[i].Num);
		printf(" %d.\n",n);
	}
	return 0;
}
