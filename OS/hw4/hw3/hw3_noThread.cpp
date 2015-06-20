#include <iostream>
#include <cstdio>
#include <cstring>
//#include <thread>
using namespace std;

int num[8], Num=0;
//thread myThreads[8];

typedef struct Tree *TreePtr;
struct Tree{
	TreePtr Left,Right;
	int Count,Key;
}; 

int cmp(int a,int b){
	if(a>b) return 1;
	if(a<b) return -1;
	return 0;
}

TreePtr Search(int n,TreePtr tmp){  //return previous Tree pointer
	TreePtr last=NULL;
	while(tmp)
		switch(cmp(n,tmp->Key)){
			case 0: return last; //find the Key
			case 1: last=tmp; tmp=tmp->Right; break; // n > tmp->Key
			case -1: last=tmp; tmp=tmp->Left; break; // n < tmp->Key
		}
	return last;
}

void Insert(TreePtr* TREE, int n){
	TreePtr tmp=Search(n,*TREE);
	/* find the Key, adding counting */
	if(tmp==NULL && (*TREE)!=NULL && (*TREE)->Key==n) //Key is the root
		++((*TREE)->Count);
	else if(tmp!=NULL && tmp->Right!=NULL && tmp->Right->Key==n)
		++(tmp->Right->Count);
	else if(tmp!=NULL && tmp->Left!=NULL && tmp->Left->Key==n) 
		++(tmp->Left->Count);
	/* new Key */
	else{ 
		TreePtr New=new Tree;
		New->Count=1; New->Key=n;
		New->Right=New->Left=NULL;
		if(*TREE==NULL) (*TREE)=New;
		else if(n<tmp->Key) tmp->Left=New;
		else tmp->Right=New;
	}
}

void DeleteAll(TreePtr* x){ //call by value to delete all TREE
	TreePtr tmp=(*x);
	if((*x)->Left) DeleteAll(&((*x)->Left));
	if((*x)->Right) DeleteAll(&((*x)->Right));
	delete (*x);
}

void Find(int n, TreePtr *TREE){
	TreePtr tmp=Search(n, *TREE);
	/* find the Key, print count */
	if(tmp==NULL && (*TREE)!=NULL && (*TREE)->Key==n) //Key is the root
		printf("%3d: %4d time(s)\n", n, (*TREE)->Count);
	else if(tmp!=NULL && tmp->Right!=NULL && tmp->Right->Key==n)
		printf("%3d: %4d time(s)\n", n, tmp->Right->Count);
	else if(tmp!=NULL && tmp->Left!=NULL && tmp->Left->Key==n) 
		printf("%3d: %4d time(s)\n", n, tmp->Left->Count);
	/* not find */
	else
		printf("%3d: 0 time(s)\n", n);
}

void BST(char *fileout){
	TreePtr TREE=NULL;
	for(int i=0; i<1000; ++i){
		int tmp;
		scanf("%d",&tmp);
		Insert(&TREE,tmp);
	}
	freopen(fileout, "w", stdout);
	for(int i=0; i<Num; ++i)
		Find(num[i], &TREE);
//		myThreads[i] = thread(Find,num[i],&TREE); 
//	for(int i=0; i<Num; ++i)
//		myThreads[i].join();
	DeleteAll(&TREE);
}

void putnum(){
	string s;
	getline(cin,s);
	int Len=s.length(), tmp=-1;
	for(int i=0; i<Len; ++i){
		if(s[i]==' '){ 
			num[Num++]=tmp; 
			tmp=-1; 
			continue;
		}
		else if(tmp==-1) tmp=0;
		tmp=tmp*10+(s[i]-'0');
	}
	if(s[Len-1]!=' ') num[Num++]=tmp;
}

int main(int argc, char *argv[]){
	freopen(argv[1], "r", stdin);
	putnum();
	BST(argv[2]);
	return 0;
}

