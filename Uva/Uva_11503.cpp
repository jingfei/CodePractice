#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define Max 100010
using namespace std;

int Rank[Max],Set[Max],Num[Max],Set_n;
string Fri[Max];
void Union(int,int);
void Link(int,int);
int Find(int);

int main(){
	int Case;
	scanf("%d",&Case);
	int Friends;
	while(Case--){
		map <string,int> Fri;
		map <string,int>::iterator it;
		memset(Rank,0,sizeof(Rank));
		scanf("%d",&Friends);
		Set_n=0;
//		char a[100],b[100];
		string a,b;
		for(int i=0; i<Friends; i++){
			getchar();
//			scanf("%s%s",a,b);
			cin >> a >> b;
			int Ia,Ib;
			it=Fri.find(a);
			if(it==Fri.end()){Fri.insert(pair<string,int>(a,Set_n++)); Ia=Set_n-1; Set[Ia]=Ia; Num[Ia]=1;}
			else Ia=(*it).second;
			it=Fri.find(b);
			if(it==Fri.end()){Fri.insert(pair<string,int>(b,Set_n++)); Ib=Set_n-1; Set[Ib]=Ib; Num[Ib]=1;}
			else Ib=(*it).second;
			Union(Ia,Ib);
			Ia=Num[Find(Ia)]; Ib=Num[Find(Ib)];
			printf("%d\n",Ia>Ib?Ia:Ib);
		}
	}
	return 0;
}

void Union(int a,int b){
	int A=Find(a), B=Find(b);
	if(A==B)return;
	Link(A,B);
}

void Link(int a,int b){
	if(Rank[a]<Rank[b]){
		Num[b]+=Num[a];
		Num[a]=0;
		Set[a]=b;
	}
	else{
		Num[a]+=Num[b];
		Num[b]=0;
		Set[b]=a;
		if(Rank[a]==Rank[b])
			Rank[a]++;
	}
}

int Find(int x){
	if(Set[x]!=x) Set[x]=Find(Set[x]);
	return Set[x];
}
