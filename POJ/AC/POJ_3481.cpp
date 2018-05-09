#include <iostream>
#include <set>
#include <cstdio>
using namespace std;

struct Node{
	int P, Value;
	bool operator<(const struct Node &t)const{
		return P<t.P;
	}
};

int main(){
	int n;
	set <struct Node> S;
	set <struct Node>::iterator it;
	int P, K;
	while(scanf("%d",&n)!=EOF && n){
		int Size = S.size();
		switch(n){
			case 1:
				scanf("%d%d",&K,&P);
				struct Node tmp;
				tmp.P=P;
				tmp.Value=K;
				S.insert(tmp);
				break;
			case 2:
				if(Size){
					it=S.end();
					--it;
					printf("%d\n",it->Value);
					S.erase(it);
				}
				else printf("0\n");
				break;
			case 3:
				if(Size){
					it=S.begin();
					printf("%d\n",it->Value);
					S.erase(it);
				}
				else printf("0\n");
				break;
		}
	}
	return 0;
}
