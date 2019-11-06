#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node *right,*left;
};
typedef struct Stack{
	Node *Head;
	Node *Tail;
};
void CreateStack(Stack &s){
	s.Head=NULL;
	s.Tail=NULL;
}
Node *CreateNode(int x){
	Node *temp=(Node *) malloc(sizeof(Node));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
bool isEmpty(Stack s){
	if(s.Head==NULL) return true;
	return false;
}
void push(Stack &s,int x){
	Node *temp=CreateNode(x);
	if(isEmpty(s)){
		s.Head=s.Tail=temp;
		return;
	}
	temp->right=s.Head;
	s.Head->left=temp;
	temp=s.Head;
}
int pop(Stack &s){
	if(isEmpty(s)){
		printf("Stack empty");
		return -1;
	}
	Node *temp=s.Head;
	s.Head=s.Head->right;
	int x=temp->data;
	temp->right=NULL;
	s.Head->left=NULL;
	free(temp);
	return x;	
}
int peek(Stack s){
	if(isEmpty(s)){
		printf("Stack empty");
		return -1;
	}
	return s.Head->data;
}
void makeEmptyStack(Stack &s){
	Node *temp=s.Head;
	while(temp!=NULL){
		temp=temp->right;
		pop(s);
	}
}
int main(){
	return 0;
}
