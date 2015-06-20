#include <iostream>
#include <cstdio>
using namespace std;

typedef struct Tree *TreePtr;
struct Tree{
	TreePtr Left,Right;
	int Count,Key;
}; 

void Insert(TreePtr*,int);
void Delete(TreePtr*,int);
void DeleteAll(TreePtr*);
void Print(TreePtr);

int Menu(){
	int n;
	printf("1) Insert node\n");
	printf("2) Delete node\n");
	printf("3) Quit\n");
	printf("Select one: ");
	scanf("%d",&n);
	return n;
}

int main(){
	int n;
	TreePtr TREE=NULL;
	do{
		n=Menu();
		switch(n){
			int num;
			case 1:
				scanf("%d",&num);
				Insert(&TREE,num);
				printf("Insert %d\n",num);
				printf("[Preorder] [Count]\n");
				Print(TREE);
				printf("\n");
				break;
			case 2:
				scanf("%d",&num);
				Delete(&TREE,num);
				printf("Delete %d\n",num);
				printf("[Preorder] [Count]\n");
				Print(TREE);
				printf("\n");
				break;
			case 3:
				if(TREE) DeleteAll(&TREE);
				printf("Quit\n");
				break;
		}
	}while(n!=3);
	return 0;
}

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

void Delete(TreePtr* TREE,int n){
	TreePtr tmp=Search(n,*TREE);
	bool Right;
	/* find if the Key of node is the right if tmp */
	if(tmp!=NULL && tmp->Right==NULL) Right=false;
	else if(tmp!=NULL) tmp->Right->Key==n?Right=true:Right=false;
	
	/* Key is the root, and its counting > 1 */
	if(tmp==NULL && (*TREE)!=NULL && (*TREE)->Key==n && (*TREE)->Count!=1)
		--((*TREE)->Count);
	/* Key is the right leaf of tmp and counting > 1 */
	else if(tmp!=NULL && tmp->Right!=NULL && tmp->Right->Key==n && tmp->Right->Count!=1) 
		--(tmp->Right->Count);
	/* Key is the left leaf of tmp and counting > 1 */
	else if(tmp!=NULL && tmp->Left!=NULL && tmp->Left->Key==n && tmp->Left->Count!=1) 
		--(tmp->Left->Count);
	/* the Key will be delete  */
	else{
		TreePtr tmp2;
		/* tmp2 is the Key */
		if(tmp!=NULL) tmp2=(Right?tmp->Right:tmp->Left);
		else tmp2=(*TREE);
		/* no leaves */
		if(tmp2->Left==NULL && tmp2->Right==NULL){
			if(!tmp) (*TREE)=NULL;
			else if(Right) tmp->Right=NULL;
			else tmp->Left=NULL;
			delete tmp2;
		}
		/* has no left leaf */
		else if(tmp2->Left==NULL){
			if(!tmp) (*TREE)=tmp2->Right;
			else if(Right) tmp->Right=tmp2->Right;
			else tmp->Left=tmp2->Right;
			delete tmp2;
		}
		/* has no right leaf */
		else if(tmp2->Right==NULL){
			if(!tmp) (*TREE)=tmp2->Left;
			else if(Right) tmp->Right=tmp2->Left;
			else tmp->Left=tmp2->Left;
			delete tmp2;
		}
		/* have two leaves, assign the rightest of left subtree to Key */
		else{
			TreePtr Temp; // the replaced Key
			Temp=tmp2->Left;
			/* find the rightest of left subtree */
			while(Temp && Temp->Right && Temp->Right->Right) 
				Temp=Temp->Right;
			/* the left subtree has no leaves */
			if(tmp2->Left==Temp) tmp2->Left=NULL;
			/* the rightest node */
			else{
				TreePtr Temp2=Temp->Right;
				Temp->Right=NULL;
				Temp=Temp2;
			}
			/* assign the node to the pointer of Key deleted */
			if(tmp==NULL) (*TREE)=Temp;
			else if(Right) tmp->Right=Temp;
			else tmp->Left=Temp;
			Temp->Left=tmp2->Left;
			Temp->Right=tmp2->Right;
			delete tmp2;
		}
	}
}

void Print(TreePtr p){
	if(p){
		printf("%-10d %-7d\n",p->Key,p->Count);
		Print(p->Left);
		Print(p->Right);
	}
}

void DeleteAll(TreePtr* x){ //call by value to delete all TREE
	TreePtr tmp=(*x);
	if((*x)->Left) DeleteAll(&((*x)->Left));
	if((*x)->Right) DeleteAll(&((*x)->Right));
	delete (*x);
}

