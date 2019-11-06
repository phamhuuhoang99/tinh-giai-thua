#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node *next;
};
typedef Node *List;
typedef Node *List1;
Node *CreateNode(int info)
{
	Node *temp;
	temp=(Node*)malloc(sizeof(Node));
	temp->data=info;
	temp->next=NULL;
	return temp;
}
void insertAtFirst(List *first,int info )
{
	Node *temp=CreateNode(info);
	temp->next=*first;
	(*first)=temp;
}

void printList(List first){
	Node *temp;
	temp=first;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
}

void insertAtLast(List *first, int info)
{
	
	Node *temp=CreateNode(info);
	if(*first==NULL)
	{
	 	temp->next=*first;
	 	(*first)=temp;
	}
	else{
		Node *temp1=*first;
		while(temp1->next!=NULL){
			temp1=temp1->next;
		}
		temp1->next=temp;
	}		
}
void insertAtPos(List *first, int info,int pos)
{
	Node *temp;
	Node *temp1=*first;
	int dem=0;
	while(temp1->next!=NULL&&dem<pos){
		*temp=*temp1; 
		temp1=temp1->next;
		dem++;
	}
	temp=(Node*)malloc(sizeof(Node));
	temp->data=info;
	//temp1->next=temp;
	//(*temp1)=temp;	
}
void deleteAtFirst(List *first){
	if(first==NULL)
	{
		return;
	}
	Node*temp=*first;
	(*first)=(*first)->next;
	free(temp);
}
void deleteAtLast(List *first){
	if(first==NULL){
		return;	
	}
	Node *temp1=(*first);
	Node *temp2=temp1;
	while(temp1->next!=NULL){
		temp2=temp1;
		
		temp1=temp1->next;
	}
	temp2->next=NULL;
	free(temp1);
}
int main()
{
	List first=NULL;
	List1 first1=NULL;
	insertAtFirst(&first,10);
	//insertAtFirst(&first,20);
	insertAtLast(&first1,-5);
	//insertAtLast(&first,60);
	//insertAtPos(&first,40,1);
	//deleteAtLast(&first);
	printf("List 1:");
	printList(first1);
	printf("List2 :");
	printList(first);
	return 0;
}
