#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int Queue[MAX];
int rear=-1;
int front=-1;
bool isEmpty(){
	if(front==-1) return true;
	return false;
}
bool isFull(){
	if(rear==MAX-1) return true;
	return false;
}
void Put(int x){
	if(isFull()){
		printf("Queue Overflow");
		return ;	
	}
	if(isEmpty()){
		front=0;
	}
	rear++;
	Queue[rear]=x;
}
void Get(){
	if(isEmpty()){
		printf("Queue empty");
		return;
	}
 	//return Queue[front++];	
	front=front+1;
	
}
void readDataFromFile(){
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
		Put(x);
	}
}
void printQueue(){
	if(isEmpty()){
		printf("Queue empty");
		return;
	}
	for(int i=front;i<=rear;i++){
		printf("%d ",Queue[i]);
	}
}

int main(){
//	Put(5);
//	Put(6);
//	Put(7);
//	Put(8);
//	Get();
//	Get();
 	readDataFromFile();
	printQueue();
	return 0;
}
