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
bool isEmptyList(SingleList list){
	Node *temp=list.Head;
	if(temp==NULL) return true;
	return false;
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
	if(isEmptyList(list)){
		inseartAtFist(list,x);
		return;
	}
	if(pos<0||pos>sizeList(list)){
		printf("Could not found position do insert ");
		return;
	}
	if(pos==0){
		inseartAtFist(list,x);
		return;
	}
	if(pos==sizeList(list)){
		inseartAtLast(list,x);
		return;
	}
	Node *temp=CreateNode(x);
	Node *Ins=list.Head;
	Node *Pre=NULL;
	int i=0;
	while(Ins!=NULL&&i<pos){
		i++;
		Pre=Ins;
		Ins=Ins->next;
	}
	Pre->next=temp;
	temp->next=Ins;	
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
void deleteAtPos(SingleList &list,int pos){
	if(isEmptyList(list)){
		printf("List empty");
		return;
	}
	if(pos<0||pos>sizeList(list)){
		printf("Could not found position do delete ");
		return;
	}
	if(pos==0){
		deleteAtFist(list);
		return;
	}
	Node *Del=list.Head;
	Node *Pre=NULL;
	int i=0;
	while(Del!=NULL&&i<pos){
		i++;
		Pre=Del;
		Del=Del->next;
	}
	Pre->next=Del->next;
	Del->next=NULL;
	free(Del);	
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
Node *seachNode(SingleList list,int x){
	Node *temp=list.Head;
	if(temp==NULL){
		printf("List empty");
		return NULL;
	}	
	while(temp!=NULL&&temp->data!=x){
		temp=temp->next;
	}
	if(temp==NULL){
		printf("Counld not found number\n");
		return NULL;
	}	
	return temp;	
}	

void makeEmptyList(SingleList &list)
{
	while(!isEmptyList(list)){
		deleteAtFist(list);
	}
}
void addNewNodeWithSort(SingleList &list,int x){
	SortList(list);
	if(x<list.Head->data){
		inseartAtFist(list,x);
		return;
	}
	Node *temp=list.Head;
	while(temp->next!=NULL){
		temp=temp->next;
	}	
	if(x>temp->data){
		inseartAtLast(list,x);
		return;
	}
	Node *temp1=list.Head;
	int pos=0;
	while(temp1!=NULL&&x>temp1->data){
		pos++;
		temp1=temp1->next;
	}
	inseartAtPos(list,pos,x);
}
void deleteNodeSameWithListSort(SingleList &list){
	SortList(list);
	Node *temp=list.Head;	
	while(temp->next!=NULL){
		Node *Next=temp->next;
		if(temp->data==Next->data){
			temp->next=Next->next;
			Next->next=NULL;
			free(Next);	
		}else{
			temp=temp->next;
		}
	}
		
}
int main(){
	SingleList list;
	CreatList(list);
	//CreateListFromFile(list); 
	inseartAtLast(list,1);
	inseartAtLast(list,1);
	inseartAtLast(list,1);
	inseartAtLast(list,2);
	inseartAtLast(list,2);
	inseartAtLast(list,3);
	inseartAtLast(list,3);
	inseartAtLast(list,3);
	inseartAtLast(list,5);
	//deleteAtLast(list);
	//RemoveNode(list,0);
	//Node *temp=seachNode(list,1);
	makeEmptyList(list);
	//SortList(list);
	//inseartAtPos(list,2,9);
	//int x=sizeList(list);
	//printf("%d",x);
	//addNewNodeWithSort(list,7);
	//deleteAtPos(list,2);
	//deleteNodeSameWithListSort(list);
	//deleteAtPos(list,6);
	printList(list);
	
	return 0;
}	
	
