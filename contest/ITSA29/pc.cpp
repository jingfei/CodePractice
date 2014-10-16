#include <iostream>
#include <cstdio>
using namespace std;

int Month[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
string Da[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

bool Leap(int y){
	if(y%400==0) return true;
	if(y%100==0) return false;
	if(y%4==0) return true;
	return false;
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a<2000 || b<1 || b>12 || c<1 || c>Month[b]){
			printf("invalid date\n"); 
			continue;
		}
		if(b==2 && c>28){
			if(!Leap(a)){printf("invalid date\n"); continue;}
		}
		if(a==2000 && b==1 && c==1){
			cout << Da[6] << endl;
			continue;
		}
		//2000/1/2 Sunday
		int Day=0;
		for(int i=2000; i<a; ++i){
			if(Leap(i)) Day+=366;
			else Day+=365;
		}
		for(int i=1; i<b; ++i) Day+=Month[i];
		if(b>2 && !Leap(a)) --Day;
		Day+=c;
		Day-=2;
		cout << Da[Day%7] << endl;
	}
	return 0;
}
