#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node *next;
};
typedef struct Queue{
	Node *Head;
	Node *Tail;
};
void CreateQueue(Queue &q){
	q.Head=NULL;
	q.Tail=NULL;
}
Node *CreatNode(int x){
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
bool isEmpty(Queue q){
	Node *temp=q.Head;
	if(temp==NULL) return true;
	return false;
}
void Put(Queue &q,int x){
	Node *temp=CreatNode(x);
	if(isEmpty(q)){
		q.Head=q.Tail=temp;
	}else{
		q.Tail->next=temp;
		q.Tail=temp;
	}
}
int Get(Queue &q){
	if(isEmpty(q)){
		printf("Queue empty");
		return -1;
	}
	Node *temp=q.Head;
	q.Head=q.Head->next;
	int x=temp->data;
	temp->next=NULL;
	free(temp);
	return x;	
}
void printQueue(Queue q){
	if(isEmpty(q)){
		printf("Queue empty");
		return;
	}
	Node *temp=q.Head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void readDataFromFile(Queue &q){
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
		Put(q,x);
	}
}
void makeEmptyQueue(Queue &q){
	Node *temp=q.Head;
	while(temp!=NULL){
		temp=temp->next;
		Get(q);
	}
}
int main(){
	Queue q;
	CreateQueue(q);
	//readDataFromFile(q);
	Put(q,5);
	Put(q,6);
	Put(q,9);
	Get(q);
	Get(q);
	Get(q);
	//makeEmptyQueue(q);
	printQueue(q);
	return 0;
}
