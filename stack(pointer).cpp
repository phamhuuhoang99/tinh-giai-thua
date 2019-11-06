#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
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

Node *CreatNode(int x){
	Node *temp;
	temp=(Node*)malloc(sizeof(Node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
void Push(Stack &s,int x){
	Node *temp=CreatNode(x);
	if(s.Head==NULL){
		s.Head=temp;
	}else{
		temp->next=s.Head;
		s.Head=temp;
	}
}
int Pop(Stack &s){
	Node *temp=s.Head;
	if(temp==NULL){
		printf("Stack empty");
		return -1;
	}
	s.Head=s.Head->next;
	int x=temp->data;
	temp->next=NULL;
	free(temp);
	return x;	
}
int Peek(Stack s){
	if(s.Head==NULL){
		printf("Stack empty");
		return -1;
	}
	return s.Head->data;
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
		printf("%d",temp->data);
		temp=temp->next;	
	}
}
void decToBinary(int n){
	Stack s;
	CreatStack(s);
	while(n>0){
		Push(s,n%2);
		n=n/2;
	}
	printStack(s);	
}
int main(){
	//Stack s;
	//CreatStack(s);
//	Push(s,5);
//	Push(s,6);
//	//Pop(s);
//	//makeEmptyStack(s);
//
//	printStack(s);
//chuyen co so:
	int n;
	printf("Nhap so n: ");
	scanf("%d",&n);
	ChuyenCoSo(n);
	return 0;
	//;
}

