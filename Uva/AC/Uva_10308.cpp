#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct Array{
    vector <int> point;
    vector <int> Dis;
}ar[10010];

long long int Long[10010];
bool Visit[10010];
long long int Max;
void Dfs(int);

int main(){
    char s[100];
    int a,b,dis;
    int tmp=-1;
	bool Begin=false;
    memset(Visit,false,sizeof(Visit));
    memset(Long,0,sizeof(Long));
    while(fgets(s,100,stdin)!=0){
        if(!strcmp("\n",s)){
			Max=0;
            Visit[tmp]=true;
            Dfs(tmp);
			printf("%lld\n",Max);
			
            tmp=-1;
            memset(Visit,false,sizeof(Visit));
            memset(Long,0,sizeof(Long));
            for(int i=0; i<10010; ++i){
                ar[i].point.clear();
                ar[i].Dis.clear();
            }
            continue;
        }
        a=-1; b=-1; dis=-1;
        int itmp=0,Len=strlen(s);
		bool Start=false;
        for(int i=0; i<Len; ++i){
            if(!Start && s[i]==' ')continue;
            if(s[i]>='0' && s[i]<='9'){
				Start=true;
				itmp=itmp*10+s[i]-'0';
			}
            else if(a==-1){a=itmp; itmp=0; Start=false;}
            else if(b==-1){b=itmp; itmp=0; Start=false;}
			else dis=itmp;
        }
        if(dis==-1) dis=itmp;
        ar[a-1].point.push_back(b-1); ar[a-1].Dis.push_back(dis);
        ar[b-1].point.push_back(a-1); ar[b-1].Dis.push_back(dis);
        if(tmp==-1) tmp=a-1;
    }
    Max=0;
    Visit[tmp]=true;
    Dfs(tmp);
    printf("%lld\n",Max);
    return 0;
}

void Dfs(int x){
    Visit[x]=true;
    vector <int>::iterator it;
    int P=0;
    for(it=ar[x].point.begin(); it!=ar[x].point.end(); ++it,++P){
        int p=(*it);
        if(Visit[p])continue;
		Dfs(p);
        long long int tdis=ar[x].Dis[P]+Long[p];
        Visit[p]=false;
		Max=max(Max,tdis+Long[x]);
        if(tdis>Long[x]){
            Long[x]=tdis;
            Max=max(Long[x],Max);
        }
    }
}

