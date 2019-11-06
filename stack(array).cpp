#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int stack[MAXSIZE], top =-1;
bool isEmpty(){
	if(top<0){
		return true;
	}
	return false;
}
bool isFull(){
	if(top>=MAXSIZE){
		return true;
	}
	return false;
}
void push(int data){
	if(isFull()){
		printf("Stack Overflow");
		return;
	}
	stack[++top]=data;
}
int pop(){
	if(isEmpty()){
		printf("Stack empty");
		return -1;
	}
	return stack[top--];
}
int sizeStack(){
	return top+1;
}
int peek(){
	if(isEmpty()){
		printf("Stack empty");
		return -1;
	}
	return stack[top];
}
void makeEmty(){
	top=-1;
}
int main(){
	return 0;
}
