#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	printf("INTERSECTING LINES OUTPUT\n");
	while(N--){
		int x1,x2,x3,x4,y1,y2,y3,y4;
		scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		if((x2-x1)*(y4-y3)==(x4-x3)*(y2-y1)){
			if((x3-x2)*(y4-y3)==(x4-x3)*(y3-y2))
				printf("LINE\n");
			else printf("NONE\n");
		}
		else{
			int X13=x3-x1,X12=x2-x1,Y13=y3-y1,Y12=y2-y1,X14=x4-x1,Y14=y4-y1;
			int X34=x4-x3,Y34=y4-y3,X31=x1-x3,Y31=y1-y3,X32=x2-x3,Y32=y2-y3;
//			if((X12*Y13-X13*Y12)*(X12*Y14-X14*Y12)>0 || (X34*Y31-X31*Y34)*(X34*Y32-X32*Y34)>0)
//				printf("NONE\n");
//			else{
				printf("POINT ");
				double X;
				if(x2-x1==0) X=x2;
				else if(x4-x3==0) X=x4;
				else X=(y3-y1-(y4-y3)*x3/(double)(x4-x3)+(y2-y1)*x1/(double)(x2-x1))/(double)((y2-y1)/(double)(x2-x1)-(y4-y3)/(double)(x4-x3));
				double Y;
				if(y2-y1==0) Y=y2;
				else if(y4-y3==0) Y=y4;
				else Y=(y2-y1)/(double)(x2-x1)*X+y1-(y2-y1)*x1/(double)(x2-x1);
				printf("%.2lf %.2lf\n",X,Y);
//				printf("%.2lf %.2lf\n",(y2-y1)/(double)(x2-x1),y1-(y2-y1)*x1/(double)(x2-x1));
//			}
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
