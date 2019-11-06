#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Node{
	int key;
	Node*left;
	Node *right;
};
typedef Node *Tree;
Node* createNode(int x){
	Node* n=(Node*) malloc(sizeof(Tree));
	n->key=x;	
	n->left=n->right=NULL;
	return n;
}
Node *searchNode(Tree root,int x){
	if(root->key==x) return root;
	Node* p=root;
	while(p!=NULL){
		if(p->key==x) return p;
		else if(p->key>x)
			p=p->left;
		else p=p->right;
	}
}
Node* findInsert(Tree root, int x){
	if(root==NULL) return NULL;
	Node* p=root;
	Node* f=p;
	while(p!=NULL){
		f=p;
		if(p->key>x) p=p->left;
		else p=p->right; 	 	
	}
	return f;
}
void InsertNode(Tree &root,int x){
	Node *n=createNode(x);
	if(root==NULL){ 
		root=n;
		return;
	}
	Node *f=findInsert(root,x);
	if(f!=NULL){
		if(f->key>x) f->left=n;
		else f->right=n;
	}
}
void NLR(Tree root){
	if(root!=NULL){
		printf("%d\t",root->key);
		NLR(root->left);
		NLR(root->right);
	}
}
void createTree(Tree &root, int a[],int n)
{
	for(int i=0;i<n;i++){
		InsertNode(root,a[i]);
	}	
}
int searchMax(Tree root){
	if(root->right==NULL){
		return root->key;
	}else{
		return searchMax(root->right);
	}
}
int searchMin(Tree root){
	if(root->left==NULL){
		return root->key;
	}else{
		return searchMin(root->left);
	}
}
void SearchMaxLeft(Tree &Q,Tree &q){
	if(q->right!=NULL){
		SearchMaxLeft(Q,q->right);	
	}else{
		Q->key=q->key;
		Q=q;
		q=q->left;
	}
}

void delNode(Tree &root,int x){	
		if(root==NULL) return;
		else{
			if(root->key>x) delNode(root->left,x);
			else if(root->key<x) delNode(root->right,x);
			else{
				Node *Q=root;
				if(root->left==NULL) root=root->right;
				else if(root->right==NULL) root=root->left;
				else{
					SearchMaxLeft(Q,root->left);
				}	
				free(Q);
			}
		}
		
}

int main(){
	Tree root=NULL;
	int a[]={40,4,34,45,15,55};
	int n=6;
	createTree(root,a,n);
	
	//NLR(root);
	//NODE *temp=searchNode(root,4);
//	if(temp!=NULL){
//		printf("tim thay node");
//	}
	//delNode(root,15);
	NLR(root);
	int max=searchMax(root);
	int min=searchMin(root);
	printf("\nmax %d",max);
	printf("\nmin %d",min);
	return 0;
}	

