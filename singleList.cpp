#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node *next;
};
typedef struct SingleList{
	Node *Head;
};
void CreatList(SingleList &list){
	list.Head=NULL;
}
Node *CreateNode(int x){
	Node *temp;
	temp=(Node*)malloc(sizeof(Node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
void printList(SingleList list){
	Node *temp=list.Head;
	if(temp==NULL){
		printf("List tempty");
		return;
	}
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}	
}
int  sizeList(SingleList list){
	Node *temp=list.Head;
	int size=0;
	while(temp!=NULL){
		size++;
		temp=temp->next;	
	}	
	return size;
}		
void inseartAtFist(SingleList &list,int x){
	Node *temp=CreateNode(x);
	if(list.Head==NULL){
		list.Head=temp;
	}else{
		temp->next=list.Head;
		list.Head=temp;
	}	
}	
void inseartAtLast(SingleList &list,int x){
	Node *temp=CreateNode(x);
	
	if(list.Head==NULL){
		list.Head=temp;
	}else{
		Node *temp1=list.Head;
		while(temp1->next!=NULL){
			temp1=temp1->next;
		}
		temp1->next=temp;
		temp->next=NULL;		
	}	
}
void inseartAtPos(SingleList &list,int pos,int x){
	
}
void deleteAtFist(SingleList &list){
	if(list.Head==NULL){
		return;
	}	
	Node *temp=list.Head;
	list.Head=list.Head->next;
	temp->next=NULL;
	free(temp);
}
void deleteAtLast(SingleList &list){
	Node *tempDel=list.Head;
	Node *tempPre=NULL;
	while(tempDel->next!=NULL){
		tempPre=tempDel;
		tempDel=tempDel->next;
	}	
	tempPre->next=NULL;
	free(tempDel);
}
void deleteAtPos(){
}
void RemoveNode(SingleList &list,int x){
	Node *tempDel=list.Head;
	if(tempDel==NULL){
		printf("List empty");
		return;
	}
	Node *tempPre=NULL;
	while(tempDel!=NULL&&tempDel->data!=x){
		tempPre=tempDel;
		tempDel=tempDel->next;
	}
	if(tempDel==NULL){
		printf("Could not found number\n");
		return;
	}
	if(tempDel==list.Head){
		deleteAtFist(list);
		return;
	}	
	tempPre->next=tempDel->next;
	tempDel->next==NULL;
	free(tempDel);
}	
void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
void SortList(SingleList &list){
	for(Node *temp=list.Head;temp!=NULL;temp=temp->next){
		for(Node *temp1=temp->next;temp1!=NULL;temp1=temp1->next){
			if(temp->data>temp1->data){
				swap(temp->data,temp1->data);
			}	
		}	
	}	
}
void CreateListFromFile(SingleList &list){
	FILE *fin;
	fin=fopen("input.txt","r");
	int n,x;
	if(fin==NULL){
		printf("Could not found file");
		return ;
	}	
	fscanf(fin,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(fin,"%d",&x);
		inseartAtLast(list,x);
	}	
}	
int main(){
	SingleList list;
	CreatList(list);
	CreateListFromFile(list); 
	//inseartAtFist(list,5);
	//inseartAtFist(list,6);
	//inseartAtLast(list,7);
	//deleteAtLast(list);
	//RemoveNode(list,0);
	printList(list);
	return 0;
}	
	
