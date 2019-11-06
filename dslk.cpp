#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
	int data;
	Node *next;
};
typedef Node *List;
void insertAtFirst(List *first,int infor){
	Node *temp;
	temp= (Node*)malloc(sizeof(Node));
	temp->data=infor;
	temp->next=*first;
	(*first)=temp;
}
void printList(List first)
{
	Node *temp;
    temp=first;
	while(temp!=NULL)
	{
		printf(" %d ",temp->data);
		temp = temp->next;
	}
}
/*void insertAtLast(List *first, int info){
	Node *temp;
	Node *temp1 = (*first);
	while(temp1->next !=  NULL)
	   temp1 = temp1->next;
	   
	temp = (Node*)malloc(sizeof(Node));
	temp->data = info;
	
	temp1->next = temp;
	temp->next = NULL;
}*/
int main()
{
	List first=NULL;
	int n,i,a[100];
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("a[%d]= ",i);
		scanf("%d",&a[i]);
		//insertAtLast(&first,a[i]);
	}
	for(i=0;i<n;i++)
	{
		insertAtFirst(&first,a[i]);
	}
    printList(first);
}
