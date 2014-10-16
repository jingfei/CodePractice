#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool T[100010];

int main(){
	int k,l,m,n,t;
	while(scanf("%d%d%d%d%d",&k,&l,&m,&n,&t)!=EOF){
		memset(T,false,sizeof(T));
		for(int i=k-1; i<t; i+=k) T[i]=true;
		for(int i=l-1; i<t; i+=l) T[i]=true;
		for(int i=m-1; i<t; i+=m) T[i]=true;
		for(int i=n-1; i<t; i+=n) T[i]=true;
		int total=0;
		for(int i=1; i<t; i++)
			if(T[i]) total++;
		printf("%d\n",total);
	}
	return 0;
}
