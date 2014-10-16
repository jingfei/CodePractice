#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int ar[3],ans[3],a,b,c;

void Ans(){
	if(ar[0]==a && ar[1]==c && ar[2]==b) printf("%d %d %d\n",ans[2],ans[1],ans[0]);
	else if(ar[0]==a && ar[2]==c && ar[1]==b) printf("%d %d %d\n",ans[0],ans[1],ans[2]);
	else if(ar[1]==a && ar[0]==c && ar[2]==b) printf("%d %d %d\n",ans[1],ans[2],ans[0]);
	else if(ar[2]==a && ar[0]==c && ar[1]==b) printf("%d %d %d\n",ans[1],ans[0],ans[2]);
	else if(ar[2]==a && ar[1]==c && ar[0]==b) printf("%d %d %d\n",ans[2],ans[0],ans[1]);
	else if(ar[1]==a && ar[2]==c && ar[0]==b) printf("%d %d %d\n",ans[0],ans[2],ans[1]);
}

int main(){
	scanf("%d%d%d",&a,&b,&c);
	ar[0]=a; ar[1]=b; ar[2]=c; sort(ar,ar+3);
	if(ar[0]+ar[1]<ar[2]) printf("Impossible\n");
	else if(ar[0]+ar[1]==ar[2]){
		ans[0]=0; ans[1]=ar[1]; ans[2]=ar[0];
		Ans();
	}
	else{
		int tmp=ar[0]+ar[1]-ar[2];
		if(tmp%2==1) printf("Impossible\n");
		else{
			tmp/=2;
			ans[0]=tmp;
			ans[1]=ar[1]-tmp;
			ans[2]=ar[0]-tmp;
			Ans();
		}
	}
	return 0;
}
