#include<stdio.h>
#include<stdlib.h>
struct Node{
	int info;
	struct Node *next;
};
typedef struct Node *QueueNode;
typedef struct {
	QueueNode head;
	QueueNode tail;	
}Queue;
void QueueInitialize(Queue &q)
{
	q.head=NULL;
	q.tail=NULL;
}

void Add(Queue &q, int x){
	QueueNode ql = (QueueNode) malloc(sizeof(struct Node));
	ql->info=x;
	ql->next=NULL;
	if(q.head!=NULL) {
		q.head=q.tail=ql;
	}
	else{
		q.tail->next=ql;
		q.tail=ql;
	}	
}
void sapXep(Queue &first)
{	
	for(Node *temp1=first.head;temp1!=NULL;temp1=temp1->next)
	{
		for(Node *temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
		{
			if(temp1->info>temp2->info){
				int t=temp1->info;
				temp1->info=temp2->info;
				temp2->info=t;
			}
		}
	}
}
void printQueue(Queue q)
{
	Node *temp;
	temp=q.head;
	while(temp!=NULL)
	{
		printf("%d ",temp->info);
		temp=temp->next;
	}
}	
void RemoveValueSame(Queue &q)
{
	QueueNode ql = (QueueNode) malloc(sizeof(struct Node));
}
int main(){
	Queue q;
	QueueInitialize(q);
	FILE *file;
	int soPT;
	file=fopen("input.txt","r");
	fscanf(file,"%d",&soPT);
	printf("%d",soPT);
	int x[100];	
	for(int i=1;i<=soPT;i++){
        fscanf(file,"%d",&x[i]);
        Add(q,x[i]);
    }
//	for(int i=0;i<soPT;i++){
//		int value;
//		fscanf(file,"%d",&value);
//		Add(q,value);
//	}
	printQueue(q);
}	
