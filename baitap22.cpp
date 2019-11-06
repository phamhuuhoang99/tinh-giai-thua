#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node *pNext;
};
typedef Node *List;
void insertAtFirst(List *first,int info )
{
	Node *temp;
	temp=(Node*)malloc(sizeof(Node));
	temp->data=info;
	temp->pNext=*first;
	(*first)=temp;
}

void printList(List first){
	Node *temp;
	temp=first;
	while(temp!=NULL)
	{
		printf(" %d ",temp->data);
		temp=temp->pNext;
	}
}
void sapXep(List *first)
{	
	for(Node *temp1=(*first);temp1!=NULL;temp1=temp1->pNext)
	{
		for(Node *temp2=temp1->pNext;temp2!=NULL;temp2=temp2->pNext)
		{
			if(temp1->data>temp2->data){
				int t=temp1->data;
				temp1->data=temp2->data;
				temp2->data=t;
			}
		}
	}
}
int main()
{
	List first=NULL;
	int soPT;
	printf("Nhap so phan tu: ");
	scanf("%d",&soPT);
	int x;
	printf("Nhap danh sach: ");
	for(int i=0;i<soPT;i++)
	{	
		scanf("%d",&x);
		insertAtFirst(&first,x);	
	}		
	sapXep(&first);
	printList(first);

}
