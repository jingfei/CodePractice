#include <iostream>
#include <new>
#include <algorithm>
#include <cstdio>
#define MAX 252000
using namespace std;

int myrand(int a,int b){
	return a & b;
}

struct Treap{
	static Treap mem[MAX], *pmem;
	Treap *l, *r;
	int pri, key, val, big, small;
	Treap(){}
	Treap(int _key, int _val): l(NULL),r(NULL),pri(myrand(_key,_val)),key(_key),val(_val),big(_val),small(_val) {}
}Treap::mem[MAX], *Treap::pmem = Treap::mem;

int big(Treap *t){
	return t ? t->big : 0;
}

int small(Treap *t){
	return t ? t->small : 1e9;
}

void pull(Treap *t){
	t->big = max(t->val, max(big(t->l), big(t->r)));
	t->small = min(t->val, min(small(t->l), small(t->r)));
}

Treap* merge(Treap *a, Treap *b){
	if(!a || !b) return a ? a : b;
	if(a->pri > b->pri){
		a->r = merge(a->r, b);
		pull(a);
		return a;
	} else{
		b->l = merge(a, b->l);
		pull(b);
		return b;
	}
}

void split(Treap *t, int k, Treap *&a, Treap *&b){
	if(!t) a = b = NULL;
	else if(t->key <= k){
		a = t;
		split(t->r, k, a->r, b);
		pull(a);
	} else{
		b = t;
		split(t->l, k, a, b->l);
		pull(b);
	}
}

int main(){
	int n; scanf("%d",&n);
	Treap *t = NULL, *tl, *tr;
	for(int i=0,k=0; i<n; ++i)
		for(int j=0; j<n; ++j,++k){
			int tmp; scanf("%d",&tmp);
			t = merge(t, new (Treap::pmem++) Treap(k,tmp));
		}
	int q; scanf("%d",&q);
	while(q--){
		char c;
		int x1,x2,y1,y2,v;
		getchar();
		scanf("%c",&c);
		if(c=='q'){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			int B=0, S=1e9;
			for(int x=x1-1; x<x2; ++x){
				int l=x*n+y1-1;
				int r=x*n+y2-1;
				split(t, l-1, tl, t);
				split(t, r, t, tr);
				B=max(big(t),B);
				S=min(small(t),S);
				t = merge(merge(tl, t), tr);
			}
			printf("%d %d\n",B,S);
		} else {
			scanf("%d%d%d",&x1,&y1,&v);
			int k=(x1-1)*n+y1-1;
			split(t, k-1, tl, t);
			split(t, k, t, tr);
			t->val = t->big = v;
			t = merge(merge(tl, t), tr);
		}
	}
	return 0;
}

