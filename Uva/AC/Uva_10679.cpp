#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>
#include <queue>
using namespace std;

string A;
int q;
bool ans[1000];

typedef struct TRIE {
	struct TRIE *fail;
	map <char,struct TRIE*> child;
	vector <int> id;
	int cnt;
	TRIE():fail(NULL),cnt(0){}
} Node;

void addTRIE(Node *root, string s, int id){
	Node *now = root;
	for(int i=0; s[i]!='\0'; ++i){
		map <char,Node*>::iterator it = now->child.find(s[i]);
		if(it==now->child.end()){
			Node *t = new TRIE;
			now->child.insert(pair<char,Node*>(s[i],t));
			now=now->child[s[i]];
		}
		else now=(*it).second;
	}
	now->id.push_back(id);
}

void buildFailFunc(Node *root){
	root->fail = NULL;
	queue<Node*> que;
	que.push(root);
	while( !que.empty() ){
		Node *F = que.front(); que.pop();
		for(auto it : F->child){
			Node *cur = it.second, *ptr = F->fail;
			while(ptr && !ptr->child.count(it.first) ) ptr = ptr->fail;
			cur->fail = ptr ? ptr->child[it.first] : root;
			que.push(cur);
		}
	}
}

void findAns(Node *root){
	Node *ptr = root;
	for(int i=0; A[i]!='\0'; ++i){
		while(ptr && !ptr->child.count(A[i]) ) ptr = ptr->fail;
		if(ptr) ptr = ptr->child[A[i]];
		else ptr = root;
		
		if(ptr->cnt!=-1){
			for(Node *it=ptr; it; it=it->fail)
				if(it->id.size()){
					it->cnt=-1;
					for(int id : it->id)
						ans[id]=true;
				}
		}
	}
}

void freeAll(Node *root){
	for(auto it : root->child) freeAll(it.second);
	free(root);
}

int main(){
	int n; scanf("%d",&n);
	while(n--){
		Node *root = new TRIE;
		string pat;
		memset(ans,false,sizeof(ans));
		cin >> A;
		scanf("%d",&q);
		for(int i=0; i<q; ++i){
			cin >> pat;
			addTRIE(root,pat,i);
		}
		buildFailFunc(root);
		findAns(root);
		for(int i=0; i<q; ++i)
			printf("%c\n", ans[i] ? 'y' : 'n');
		freeAll(root);
	}
	return 0;
}

