#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct Link *LinkPtr;
typedef struct Link{
	LinkPtr next;
	int v;
};
LinkPtr cmp[1000000];
char s1[1000000],s2[1000000];
int ar[1000000];
bool Judge[1000000];
long long int Sum;
bool Ans=true;
void Add(int,int);
void Find(int,int);
void Erase();

int main(){
	int n,L;
	scanf("%d",&L);
	for(int Case=1; Case<=L; ++Case){
		scanf("%d",&n); getchar();
		scanf("%s",s1); getchar();
		scanf("%s",s2); getchar();
		int Len1=strlen(s1),Len2=strlen(s2),tmp=0;
		Sum=0; Ans=true;
		for(int i=0; i<=Len1; ++i){
			if(i!=Len1 && s1[i]>='0' && s1[i]<='9') 
				tmp=tmp*10+(int)(s1[i]-'0');
			else{ Sum+=tmp; tmp=0; }
		}
		Sum/=n;
//		printf("Sum: %lld\n",Sum);
		for(int i=0; i<Sum; ++i){
			cmp[i]=new Link;
			cmp[i]->next=cmp[i];
		}
		int now1=0,now2=0,tmp2=0,remain1=0,remain2=0;
		char rch1,rch2;
		bool First=true;
		while(n--){
			if(!Ans) break;
			int i,k=0; tmp=0;
			if(remain1)
				for(k=0; k<Sum && k<remain1; ++k)
					ar[k]=rch1;
			for(i=now1,k; i<=Len1 && k<Sum; ++i){
				if(i!=Len1 && s1[i]>='0' && s1[i]<='9') 
					tmp=tmp*10+(int)(s1[i]-'0');
				else{ 
					for(int j=0 ; j<tmp && k<Sum; ++k,++j){
						ar[k]=s1[i];
//						printf("i: %d %c k: %d\n",i,(char)s1[i],k);
					}
					if(k>Sum){ remain1=tmp-k+1; rch1=s1[i]; }
					tmp=0;
				}
			}
			now1=i;
			/**/
			k=0; tmp=0;
			if(remain2)
				for(k=0; k<Sum && k<remain2; ++k)
					ar[k]=rch2;
			for(i=now2,k; i<=Len2 && k<Sum; ++i){
				if(i!=Len2 && s2[i]>='0' && s2[i]<='9') 
					tmp=tmp*10+(int)(s2[i]-'0');
			else{ 
					for(int j=0 ; j<tmp && k<Sum; ++j,++k){
						if(First) Add(s2[i],k);
						else Find(s2[i],k);
					}
					if(k>Sum){ remain2=tmp-k+1; rch2=s2[i]; }
					tmp=0;
				}
			}
			now2=i;
			if(First){
				First=false;
			}
		}
/*				for(int i=0; i<Sum; ++i){
					printf("%d: ",i);
					for(LinkPtr tmp=cmp[i]->next; tmp!=cmp[i]; tmp=tmp->next)
						printf("%d ",tmp->v);
					printf("\n");
				}  */
		if(Ans){
			memset(Judge,false,sizeof(Judge));
			for(int i=0; i<Sum; ++i){
				for(LinkPtr tmp=cmp[i]->next; tmp!=cmp[i]; tmp=tmp->next){
					Judge[tmp->v]=true;
				}
			}
			for(int i=0; i<Sum; ++i)
				if(!Judge[i]){Ans=false; break;}
		}
		if(Ans) printf("Case %d: Yes\n",Case);
		else printf("Case %d: No\n",Case);
	}
	Erase();
	return 0;
}

void Add(int c,int k){
	for(int i=0; i<Sum; ++i)
		if(ar[i]==c){
//			printf(" %d %d\n",i,k);
			LinkPtr tmp=new Link;
			tmp->v=i;
			tmp->next=cmp[k]->next;
			cmp[k]->next=tmp;
		}
}

void Find(int c,int k){
	for(LinkPtr tmp=cmp[k]->next, Last=cmp[k]; tmp!=cmp[k]; tmp=tmp->next){
		if(c!=ar[tmp->v]){
//			printf("delete: %d %d\n",k,tmp->v);
			LinkPtr x;
			x=tmp; tmp=tmp->next;
			Last->next=tmp;
			tmp=Last;
			delete x;
		}
		else Last=Last->next;
	}
	if(cmp[k]->next==cmp[k]) Ans=false;
}

void Erase(){
	for(int k=0; k<Sum; ++k){
		for(LinkPtr tmp=cmp[k]->next; tmp!=cmp[k]; tmp=tmp->next){
			LinkPtr x=tmp; tmp=tmp->next; delete x;
		}
		delete cmp[k];
	}
}
