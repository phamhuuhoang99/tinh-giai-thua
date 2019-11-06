#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	char data;
	Node *pNext;
};
typedef struct Node* Stack;
typedef struct Node* QueueNode;
struct Queue{
	QueueNode tail;
	QueueNode head;
};
void QueueInitialize(Queue &q)// khoi tao queue rong
{
	q.head=NULL;
	q.tail=NULL;
}
void Put(Queue &q,char x){
	QueueNode ql=(QueueNode)malloc(sizeof(Node));
	ql->data=x;
	ql->pNext=NULL;
	if(q.head==NULL) {// neu queue rong
		q.head=q.tail=ql;
	}
	else{
		q.tail->pNext=ql;
		q.tail=ql;
	}
}
char Get(Queue &q){
	if(q.head!=NULL){
		QueueNode ql = (QueueNode) malloc(sizeof(struct Node));
		ql=q.head;
		q.head=q.head->pNext;
		char c=ql->data;	
		free(ql);
		return c;
	}
}
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
char TopStack(Stack first){
	return first->data;
}
void inFixtoPosfix(char infix[],char posfix[]){
	int i=0;
	int j=0;
	Stack s=NULL;
	push(&s,'$');
	while(infix[i]!='\0'){
		char x=infix[i];
		if(Pri(x)==-1){
			posfix[j]=x;
			j++;
		}else if(Pri(x)==2){
			push(&s,x);
		}else if(Pri(x)==4||Pri(x)==3){
			int Top=Pri(TopStack(s));
			while(Top>=Pri(x)){
				posfix[j]=pop(&s);
				j++;
				Top=Pri(TopStack(s));				
			}
			if(Top<Pri(x)) push(&s,x);
		}else if(x==')'){
			int m=Pri(TopStack(s));
			while(m!=-1||m!=0){
				if(m==2){
					pop(&s);
				} 
				else if(m==1){
					break;	
			} 
				else{
					posfix[j]=pop(&s);
					j++;
				}
				m=Pri(TopStack(s));
			}
		}
		i++;	
	}
		int k=Pri(TopStack(s));
			while(k!=1){
				posfix[j]=pop(&s);
				j++;
				k=Pri(TopStack(s));
			}
			posfix[j]='\0';
} 
void infixToPrefix(char infix[],char Prefix[]){
	Stack s=NULL;
	Stack skq=NULL;
	Queue q;
	QueueInitialize(q);
	int i=strlen(infix)-1;
	
	while(i>=0){
		char x=infix[i];	
		if(Pri(x)==-1){
			Put(q,x);
		}else if(Pri(x)==0){
			push(&s,x);
		}else if(Pri(x)==3||Pri(4)){
			if(s==NULL) push(&s,x);
			else{
				char y=TopStack(s);
				if(Pri(y)>=Pri(x)){
					while(q.head!=NULL){
						push(&skq,Get(q));	
					}
					push(&skq,pop(&s));
					push(&s,x);
				} else{
					push(&s,x);
				}
			}
		}else if(Pri(x)==2)	{
			while(q.head!=NULL){
				push(&skq,Get(q));
			}
			//char y bang dau stack
			//1.4.2
			char y;
			do{	
				y =TopStack(s);		
				if(Pri(y)==3||Pri(y)==4){
					pop(&s);
					push(&skq,y);	
				}
			}while(Pri(y)==3||Pri(y)==4);	
			if(Pri(y)==0) pop(&s);	
		}
		i--;
	}
	while(q.head!=NULL)	push(&skq,Get(q));
	while(s!=NULL)	push(&skq,pop(&s));
	int j=0;
	while(skq!=NULL){
		Prefix[j]=pop(&skq);
		j++;
	}
		Prefix[j]='\0';
}
int main(){
	char in[100],pre[100],post[100];
	printf("Nhap chuoi: ");
	gets(in);
	//TinhPosfix(in);	
//	char post[100];
	inFixtoPosfix(in,post);
//	puts(post);
//infixToPrefix(in,pre);
	puts(post);
	return 0;
}
