#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
	char data;
	Node *next;
};
typedef struct Stack{
	Node *Head;
};
void CreatStack(Stack &s){
	s.Head=NULL;
}
bool isEmpty(Stack s){
	if(s.Head==NULL) return true;
	return false;
}

Node *CreatNode(char x){
	Node *temp;
	temp=temp=(Node*)malloc(sizeof(Node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
void Push(Stack &s,char x){
	Node *temp=CreatNode(x);
	if(s.Head==NULL){
		s.Head=temp;
	}else{
		temp->next=s.Head;
		s.Head=temp;
	}
}
char Pop(Stack &s){
	Node *temp=s.Head;
	if(temp==NULL){
		printf("Stack empty");
		return -1;
	}
	s.Head=s.Head->next;
	char x=temp->data;
	temp->next=NULL;
	free(temp);
	return x;	
}
char Peek(Stack s){
	if(s.Head==NULL){
		printf("Stack empty");
	}else{
		return s.Head->data;
	}
	
}
void makeEmptyStack(Stack &s){
	Node *temp=s.Head;
	while(temp!=NULL){	
		temp=temp->next;
		Pop(s);
	}
}
void printStack(Stack s){
	if(isEmpty(s)){
		printf("Stack empty");
		return;
	}
	Node *temp=s.Head;
	while(temp!=NULL){
		printf("%c",temp->data);
		temp=temp->next;	
	}
}
void daoXau(char Xau[]){
	Stack s;
	CreatStack(s);
	for(int i=0;i<strlen(Xau);i++){
		Push(s,Xau[i]);
	}
	printStack(s);
}
int main(){
	char Xau[100];
	printf("Nhap xau: ");
	gets(Xau);
	daoXau(Xau);	
	return 0;
}
