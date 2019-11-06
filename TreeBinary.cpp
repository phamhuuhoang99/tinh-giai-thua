#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int key;
	node *left;
	node *right;
};
typedef struct node NODE;
typedef NODE *Tree;
void CreatTree(Tree &T){
	T=NULL;
}
NODE* createNode(int x){
	NODE* n=(NODE*) malloc(sizeof(NODE));
	n->key=x;	
	n->left=n->right=NULL;
	return n;
}
//dùng de quy tim kiem
NODE *searchNode_RE(Tree T,int x){
	if(T->key==x) return T;
	if(T->key>x) searchNode_RE(T->left,x);
	else searchNode_RE(T->right,x);
	return NULL;	
}
NODE *searchNode(Tree &T,int x){
	if(T==NULL){
		return NULL;
	}	
	if(T->key==x) return T;
	NODE* p=T;
	while(p!=NULL){
		if(p->key==x) return p;
		else if(p->key>x)
			p=p->left;
		else p=p->right;
	}
	if(p==NULL){
		return NULL;	
	}	
}		
//tim NODE can chen
NODE* findInsert(Tree T, int x){
	if(T==NULL) return NULL;
	NODE* p=T;
	NODE* f=NULL;
	while(p!=NULL){
		f=p;
		if(p->key>x) p=p->left;
		else p=p->right; 	 	
	}
	return f;
}
//chen node co khoa la x;
void InsertNode(Tree &T,int x){
	NODE *n=createNode(x);
	if(T==NULL){ 
		T=n;
		return;
	}
	NODE *f=findInsert(T,x);
	if(f!=NULL){
		if(f->key>x) f->left=n;
		else f->right=n;
	}
}
//NLR
void NLR(Tree T){
	if(T!=NULL){
		printf("%d\t",T->key);
		NLR(T->left);
		NLR(T->right);
	}
}			
void createTree(Tree &T, int a[],int n)
{
	for(int i=0;i<n;i++){
		InsertNode(T,a[i]);
	}	
}
//LNR
void LNR(Tree T){
	if(T!=NULL){
		LNR(T->left);
		printf("%d\t",T->key);
		LNR(T->right);
	}
}
//LRN
void LRN(NODE *root){
	if(root!=NULL){
		LRN(root->left);
		LRN(root->right);
		printf("%d\t",root->key);
	}
}
int searchMax(Tree T){
	if(T->right==NULL){
		return T->key;
	}else{
		return searchMax(T->right);
	}
}
int searchMin(Tree T){
	if(T->left==NULL){
		return T->key;
	}else{
		return searchMin(T->left);
	}
}
void NodeTheMang(Tree &X,Tree &Y){
	if(Y->left!=NULL){
		NodeTheMang(X,Y->left);
	}else{
		X->key=Y->key;
		X=Y;
		Y=Y->right;
	}
}
void deleteNode(Tree &t,int x){
	if(t==NULL){
		return;
	}
	if(t->key>x) deleteNode(t->left,x);
	else if(t->key<x) deleteNode(t->right,x);
	else{
		NODE* temp=t;
		if(t->left==NULL){
			t=t->right;
		}else if(t->right==NULL){
			t=t->left;
		}else{
			NODE *Y=t->right;
			NodeTheMang(t,Y);
		}
		free(temp);
	} 
}
void CreateTreeFromFile(Tree &t){
	FILE  *fin;
	fin=fopen("input.txt","r");
	if(fin==NULL){
		printf("Could not found file");
		return;
	}
	int n,x;
	fscanf(fin,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(fin,"%d",&x);
		InsertNode(t,x);
	}	
}
int main(){
	Tree t;
	CreatTree(t);
	int a[]={40,4,34,45,15,55};
	int n=6;
	//createTree(t,a,n);
	CreateTreeFromFile(t);
	//NLR(root);
//	NODE *temp=searchNode(t,90);
//	if(temp==NULL){
//		printf("ko tim thay node");
//	}
//	deleteNode(t,55);
	LNR(t);
	return 0;	
}

