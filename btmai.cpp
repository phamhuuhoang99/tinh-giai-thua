#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
	char data;
	Node *pNext;	
};
typedef struct Stack
{
 	Node *pHead;
	Node *pTail;	
};
void Initialize(Stack &stack)
{
	stack.pHead->data=NULL;		
}
Node *CreateNode(char c)
{
	Node *Temp;
	Temp=(Node*)malloc(sizeof(Node));
	Temp->data=c;
	Temp->pNext=NULL;
	return Temp;
}
void push(Stack &stack,char c)
{
	Node *Temp;
	Temp=(Node*)malloc(sizeof(Node));
	Temp->data=c;
	Temp->pNext=stack.pHead;
	stack.pHead=Temp;
	//stack.pHead=Temp;
}
void deleteAtFirst(Stack &stack){
	if(stack.pHead==NULL)
	{
		return;
	}
	Node*temp=stack.pHead;
	stack.pHead=stack.pHead->pNext;
	free(temp);
}
void pop(Stack stack)
{
	Node *Temp;
	Node *Del;
	Temp=stack.pHead;
	while(Temp!=NULL)
	{
		Del=Temp;
		printf("%c ",Temp->data);
		Temp=Temp->pNext;
		stack.pHead=Temp;
		free(Del);
	}
}
int UuTien(char c)
{
	if(c=='(') return 0;
	if(c=='+'||c=='-')return 1;
	if(c=='*'||c=='/')return 2;
	return -1;
}
int main()
{
	Stack stack;
	Initialize(stack);
	int index=0;
	char ex[]="a*(b+c)-d/e";
	char kq[100];
	int len=strlen(ex);
	for(int i=0;i<len;i++)
	{
		int x=UuTien(ex[i]);
		char c=ex[i];
		if(x==-1)
		{
			kq[index]=c;
			index++;
		}
//		else if(x==0){ 
//			push(stack,ex[i])
//		}else{
//			if(x<=UuTien(stack->pHead.data))
//			{
//				strcat(kq,stack.pHead.data);
//				deleteAtFirst(stack);
//			}
//			
	}
	//for(int i=0;i<strlen(kq);i++){
	
		gets(kq);
//	}
	}

