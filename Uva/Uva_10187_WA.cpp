#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

struct Road{
	int v1,v2,dis,t1,t2;
}Road[2000];

struct Dis{
	int d,t2;
}Dis[2000];

int main(){
	int T, Road_n,num;
	scanf("%d",&T);
	for(int Case=1; Case<=T; Case++){
		num=0;
		Road_n=0;
		int Rou;
		map <string,int> MyMap;
		scanf("%d",&Rou);
		while(Rou--){
			string a,b;
			int beg,dis,na,nb,end;
			cin >> a >> b;
			scanf("%d%d",&beg,&dis);
			end=beg+dis; if(end>24) end-=24;
			if(beg<18 && beg>6)continue;
			if(end<18 && end>6)continue;
			map <string,int>::iterator it;
			it=MyMap.find(a);
			if(it==MyMap.end()){
				MyMap.insert(pair<string,int>(a,num++));
				na=num-1;
			}
			else na=it->second;
			it=MyMap.find(b);
			if(it==MyMap.end()){
				MyMap.insert(pair<string,int>(b,num++));
				nb=num-1;
			}
			else nb=it->second;
			Road[Road_n].v1=na;
			Road[Road_n].v2=nb;
			Road[Road_n].dis=dis;
			Road[Road_n].t1=beg;
			Road[Road_n++].t2=end;
		}
		bool Find=true;
		string a,b;
		map <string,int>::iterator it;
		cin >> a >> b;
		int A,B;
		it=MyMap.find(a); if(it==MyMap.end()) Find=false; 
		if(Find) A=it->second;
		it=MyMap.find(b); if(it==MyMap.end()) Find=false;
		if(Find) B=it->second;
		if(Find) for(int i=0; i<num; i++){ 
			if(i==A) Dis[i].d=0; 
			else Dis[i].d=1e9;
		}
		if(Find){
		int k;
		if(Road_n==1) k=0;
		else k=1;
		for(k; k<Road_n; k++){
			for(int i=0; i<Road_n; i++){
				int v1,v2,t1,t2,dis;
				v1=Road[i].v1; v2=Road[i].v2; t1=Road[i].t1; 
				t2=Road[i].t2; dis=Road[i].dis;
				if(t2<12) t2+=24; if(t1<12) t1+=24;
				if(v1==A){
//					printf("v1==A\n");
//					if(v2==A){Dis[v2].d=0; continue;}
					if(Dis[v2].d==1e9){Dis[v2].d=1; Dis[v2].t2=t2; continue;}
					else if(Dis[v2].t2>t2){Dis[v2].d=1; Dis[v2].t2=t2; continue;}
				}
				if(Dis[v1].d==1e9) continue;
				if(Dis[v2].d==1e9){
					if(Dis[v1].t2<=t1){Dis[v2].d=Dis[v1].d; Dis[v2].t2=t2; continue;}
					else{Dis[v2].d=Dis[v1].d+1; Dis[v2].t2=t2; continue;}
				}
				if(Dis[v1].t2<=t1 && Dis[v1].d<=Dis[v2].d){
					if(Dis[v1].d==Dis[v2].d){Dis[v2].t2=min(Dis[v2].t2,t2); continue;}
					Dis[v2].d=Dis[v1].d; Dis[v2].t2=t2; continue;
				}
				if(Dis[v1].t2>t1 && Dis[v1].d+1<=Dis[v2].d){
					if(Dis[v1].d+1==Dis[v2].d){Dis[v2].t2==min(Dis[v2].t2,t2); continue;}
					Dis[v2].d=Dis[v1].d+1; Dis[v2].t2=t2; continue;
				}
			}	
		}}
//		printf("FInd:%s",Find?"Find!\n":"not Find!\n");
		printf("Test Case %d.\n",Case);
		if(Find && num==0) printf("There is no route Vladimir can take.\n");
//		if(!Find || Dis[B].d==1e9) printf("There is no route Vladimir can take.\n");
		else if(!Find) printf("Vladimir needs 0 litre(s) of blood.\n");
		else if(Dis[B].d==1e9 || Dis[B].d==0) printf("There is no route Vladimir can take.\n");
		else printf("Vladimir needs %d litre(s) of blood.\n",Dis[B].d-1);
	}
	return 0;
}
