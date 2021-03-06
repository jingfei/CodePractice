#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, Max, Last;
bool mx[1010], my[1010];
int ar2[1010][1010];

struct Dot{
	int y,x,v;
	bool used;
	bool operator<(const struct Dot &t)const{
		if(v==t.v && x==t.x) return y<t.y;
		if(v==t.v) return x<t.x;
		return v>t.v;
	}
}ar[1000010];

void Dfs(int p, int num, int total){
	if(num==n){ Max=max(Max,total); Last=ar[p-1].v; 
	return; }
	if(Max && ar[p].v<=Last) return;
	bool Go=false;
	for(int i=p; i<n*n; ++i){
		if(!ar[p].used && !mx[ar[p].x] && !my[ar[p].y]){
			mx[ar[p].x]=my[ar[p].y]=ar[p].used=true;
			Go=true;
			printf("num %d: %d -> %d, %d\n",num,ar[p].v,ar[p].y,ar[p].x);
			Dfs(p+1, num+1, total+ar[p].v);
			mx[ar[p].x]=my[ar[p].y]=false;
		}
		if(i==n*n-1 || ar[i].v!=ar[i+1].v) break;
	}
	if(!Go)
		Dfs(p+1, num, total);
}

int main(){
	int t; scanf("%d",&t);
	while(t--){
		Max=0;
		memset(mx,false,sizeof(mx));
		memset(my,false,sizeof(my));
		memset(ar2,0,sizeof(ar));
		scanf("%d",&n);	
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j){
				ar[i*n+j].y=i;
				ar[i*n+j].x=j;
				scanf("%d",&ar[i*n+j].v);
				ar[i*n+j].used=false;
				for(int i2=0; i2<n; ++i2) ar2[i2][j]+=ar[i*n+j].v;
				for(int j2=0; j2<n; ++j2) ar2[i][j2]+=ar[i*n+j].v;
				ar2[i][j]-=ar[i*n+j].v;
				ar2[i][j]-=ar[i*n+j].v;
			}
//		sort(ar,ar+n*n);
//		Last = ar[n*n-1].v;
//		Dfs(0,0,0);
//		printf("%d\n",Max);
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j)
				printf("%3d ", ar2[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

