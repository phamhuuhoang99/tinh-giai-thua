#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node *left;
	Node *right;
};
typedef struct Tree{
	Node *root;
};
void CreateTree(Tree &T){
	T.root=NULL;
}
Node *CreateNode(int x){
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
//de quy tim kiem
Node *searchNode_RE(Node T,int x){
	if(T.root->data==x) return T.root;
	Node *temp=T.root; 
	if(temp->data>x) searchNode_RE(temp->left,x);
	else searchNode_RE(temp->right);
	if(temp==NULL){
		printf("Could not found Node");
		return NULL;
	}
}	
//tim kiem bt
Node *searchNode(Tree T,x){
	if(T.root==x) return T.root;
	Node *temp=T.root;
	while(temp!=NULL){
		if(temp->data==x) return temp;
		else if(temp->data>x) temp=temp->left;
		else temp=temp-right;
	}
	if(temp==NULL){
		printf("Could not found Node");
		return NULL;
	}
}
void insertNode(Tree &T,int x){
	Node *temp=CreateNode(x);
	if(T.root==NULL){
		T.root=temp;
		return;
	}
	Node *temp1=T.root;
	Node *temp2=NULL;
	while(temp1!=NULL){
		temp2=temp1;
		if(temp1->data>x) temp1=temp1->left;
		else temp1=temp1->right;
	}
	if(temp2->data>x) temp2->left=temp;
	else temp2->right=temp;
}
void NodeTheMang(Tree &X,Tree &Y){
	if(Y.root->left!=NULL){
		NodeTheMang(X,Y.root->left);
	}else{
		X.root->data=Y.root->data;
		X.root=Y.root;
		Y.root=Y.root->right;
	}
}
void deleteNode(Tree &T,int x){
	if(T.root==NULL){
		return;
	}
	Node *t=T.root;
	if(t->data>x) deleteNode(t->left,x);
	else(t->data<x) deleteNode(t->right,x);
	else{
		Node *temp=t;
		if(t->left==NULL){
			t=t->right;
		}else if(t->right==NULL){
			t=t->left;
		}else{
			Node *Y=t->right;
			NodeTheMang(t,Y);
		}
		free(temp);
		
	} 
}
void NLR(Tree &T){
	if(T.root!=NULL){
		printf("%d ",root->key);
		NLR(root->left);
		NLR(root->right);
	}
}			
//LNR
void LNR(Tree &T){
	if(T.root!=NULL){
		LNR(root->left);
		printf("%d ",root->key);
		LNR(root->right);
	}
}
//LRN
void LRN(Tree &T){
	if(T.root!=NULL){
		LRN(root->left);
		LRN(root->right);
		printf("%d ",root->key);
	}
}
void createTreeFromFile(NODE* &root, int a[],int n)
{	
}





