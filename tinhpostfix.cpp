#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	float data;
	Node *pNext;
};
typedef struct Node* Stack;
Node *CreateNode(char c){
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->data=c;
	temp->pNext=NULL;
	return temp;	
}
void push(Stack *first,char c){
//	Node *temp=CreateNode(c);
//	temp->pNext=*first;
//	temp=*first;
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->data = c; 
	temp->pNext=*first; 
	(*first) = temp;
}
char pop(Stack *first){
	Node *temp=(*first);
	if(temp==NULL) return 0;
	*first=(*first)->pNext;
	char c=temp->data;
	free(temp);
	return c;
}
int Pri(char c){
	if(c=='/'||c=='*') return 4;
	if(c=='+'||c=='-') return 3;
	if(c=='(')	return 2;
	if(c=='$') return 1;
	if(c==')') return 0;
	return -1;
}
float TopStack(Stack first){
	return first->data;
}
float TinhToan(int a,int b,char c){
	switch(c){
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a*0.1/b;
	}
}
void TinhPosfix(char postfix[]){
	Stack s=NULL;
	int i=0;
	while(postfix[i]!='\0'){
		char c=postfix[i];
		if(Pri(c)==-1){
			push(&s,c-48);
		}
		if(Pri(c)==3||Pri(c)==4){
			int a=(int)pop(&s);
			int b=(int)pop(&s);
			int kq=TinhToan(a,b,c);
			//int kqc=(char)kq;
			push(&s,kq);
		}	
		i++;
	}	
	printf("Ket qua: %d",TopStack(s));
}
void TinhPrefix(char prefix[]){
	Stack s=NULL;
	int i=strlen(prefix)-1;
	while(i>=0){
		char x=prefix[i];
		if(Pri(x)==-1){
			push(&s,x-48);
		}else if(Pri(x)==3||Pri(x)==4){
			int a=pop(&s);
			int b=pop(&s);
			float kq=TinhToan(a,b,x);
			push(&s,kq);
		}	
		i--;
	}
	printf("Ket Qua= %f ",TopStack(s));	
	
}
int main(){
	char in[100],pre[100];
	printf("Nhap chuoi: ");
	gets(pre);
	//TinhPosfix(in);	
//	char post[100];
//	inFixtoPosfix(in,post);
//	puts(post);
	TinhPrefix(pre);
	return 0;
}
