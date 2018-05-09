#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 5000001
using namespace std;

struct Num{
	int i;
	int C;
}Num[MAX];

bool cmpi(struct Num &a, struct Num &b){
	return a.i<b.i;
}

bool cmpC(struct Num &a, struct Num &b){
	return a.C<b.C;
}

bool p[ MAX ] ;     //紀錄質數
void Sieve( ) {
	int t1 , t2 ;
	memset( p , 0 , sizeof( p ) ) ;
	for(int i = 1 ; i < MAX ; i++ ) Num[i ].C = 1, Num[i].i=i;
	p[0] = p[ 1 ] = 1 ;
	for(int i = 2 ; i < MAX ; i++ )
		if(!p[ i ] ) {
			Num[ i ].C++ ;                        //i為質數, 因數加上自己
			for( int j = i+i ; j < MAX ; j += i ) {
				p[ j ] = 1 ;                        //篩法
				t1 = 0 ;                         //紀錄數字j, 有幾個質因數 i
				t2 = j ;                            //暫存數字j
				while( t2 % i == 0 ) t2 /= i , t1++ ;
				Num[ j ].C = Num[ j ].C * ( t1+1 ) ;        //更新因數量
			}
		}
}

int main(){
	Sieve();
	int n; scanf("%d",&n);
	while(n--){
		int a,b; scanf("%d%d",&a,&b);
		if(b-a==1){ printf("%d\n",abs(Num[b].C-Num[a].C)); continue;}
		sort(Num+a, Num+b+1, cmpC);
		int i=a;
		int Max=Num[i+1].C-Num[i].C;
		for(int j=i+2; j<=b; ++j,++i)
			Max = max(Num[j].C-Num[i].C,Max);
		Max = max(Num[b].C-Num[b-1].C,Max);
		printf("%d\n",Max);
		sort(Num+a, Num+b+1, cmpi);
	}
	return 0;
}

