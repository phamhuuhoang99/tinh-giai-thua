#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node *left;
	Node *right;
};
typedef struct DoubleList{
	Node *Head;
	Node *Tail;
};
void CreteDoubleList(DoubleList &List){
	List.Head=NULL;
	List.Tail=NULL;
}
Node *CreateNode(int x){
	Node *temp=(Node *) malloc(sizeof(Node));
	temp->data=x;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}
int sizeList(DoubleList list){
	Node *temp=list.Head;
	int size=0;
	while(temp!=NULL){
		size++;
		temp=temp->right;
	}
	return size;
}
void printList(DoubleList list){
	if(list.Head==NULL){
		printf("List empty");
		return;
	}
	for(Node *temp=list.Head;temp!=NULL;temp=temp->right){
		printf("%d ",temp->data);
	}
}
void insertAtFirst(DoubleList &List,int x){
	Node *temp=CreateNode(x);
	if(List.Head==NULL){
		List.Head=temp;
		List.Tail=temp;
	}
	else{
		temp->right=List.Head;
		List.Head->left=temp;
		List.Head=temp;
	}	
}
void insertAtLast(DoubleList &List,int x){
	Node *temp=CreateNode(x);
	if(List.Head==NULL){
		List.Head=temp;
		List.Tail=temp;
	}
	else{
		List.Tail->right=temp;
		temp->left=List.Tail;
		List.Tail=temp;
	}
}
void insertAtPos(DoubleList &list,int pos,int x){
	Node *temp=CreateNode(x);
	if(list.Head==NULL){
		insertAtFirst(list,x);
		return;
	}
	if(pos<0||pos>sizeList(list)){
		printf("Could not found position do insert ");
		return;
	}
	if(pos==0){
		insertAtFirst(list,x);
		return;
	}
	Node *Curr=list.Head;
	int i=0;
	while(Curr!=NULL&&i<pos){
		i++;
		Curr=Curr->right;
	}
	Node *LeftCurr=Curr->left;
	LeftCurr->right=temp;
	temp->left=LeftCurr;
	temp->right=Curr;
	Curr->left=temp;
}
void deleteAtFirst(DoubleList &List){
	if(List.Head==NULL) return ;
	Node *temp=List.Head;
	List.Head=List.Head->right;
	List.Head->left=NULL;
	free(temp);
}
void deleteAtLast(DoubleList &List){
	Node *temp=List.Tail;
	List.Tail=List.Tail->left;
	List.Tail->right=NULL;
	free(temp);
}
void deleteAtPos(DoubleList &List,int pos){
	if(List.Head==NULL){
		printf("List empty");
		return;
	}
	if(pos<0||pos>=sizeList(List)){
		printf("Could not found position do delete ");
		return;
	}
	if(pos==0){
		deleteAtFirst(List);
		return;
	}
	if(pos==sizeList(List)-1){
		deleteAtLast(List);
		return;
	}
	Node *Del=List.Head;
	int i=0;
	while(Del!=NULL&&i<pos){
		i++;
		Del=Del->right;
	}
	Node *PreDel=Del->left;
	Node *NextDel=Del->right;
	PreDel->right=NextDel;
	NextDel->left=PreDel;
	free(Del);
}
void Swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
void SortList(DoubleList &list){
	for(Node *temp=list.Head;temp!=list.Tail;temp=temp->right){
		for(Node *temp1=temp->right;temp1!=NULL;temp1=temp1->right){
			if(temp->data>temp1->data){
				Swap(temp->data,temp1->data);
			}
		}
	}
}
void addNewNodeWithSort(DoubleList &list,int x){
	SortList(list);
	if(list.Head==NULL){
		insertAtFirst(list,x);
		return;
	}
	if(x<list.Head->data){
		insertAtFirst(list,x);
		return;
	}
	if(x>list.Tail->data){
		insertAtLast(list,x);
		return;
	}
	Node *temp=list.Head;
	int pos=0;
	while(temp!=NULL&&x>temp->data){
		pos++;
		temp=temp->right;
	}
	insertAtPos(list,pos,x);
	
}
void deleteNodeSameWithListSort(DoubleList &list){
//	SortList(list);
//	int i=0;
//	for(Node *temp=list.Head;temp->right!=NULL;temp=temp->right){
//		if(temp->data==temp->right->data){
//			deleteAtPos(list,i+1);
//			temp=temp->left;
//		}
//		else{
//			i++;
//		}
//	}	
	SortList(list);
	Node *temp=list.Head;	
	while(temp->right!=NULL){
		Node *Next=temp->right;
		if(temp->data==Next->data){
			temp->right=Next->right;
			Next->right=NULL;
			Next->left=NULL;
			free(Next);	
		}else{
			temp=temp->right;
		}
	}
}
void CreateListFromFile(DoubleList &list){
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
		insertAtLast(list,x);
	}	
}
int main(){
	DoubleList dou;
	CreteDoubleList(dou);
	CreateListFromFile(dou);
//	insertAtLast(dou,7);
//	insertAtFirst(dou,7);
//	insertAtLast(dou,7);
//	insertAtLast(dou,9);
//	insertAtLast(dou,9);
//	insertAtLast(dou,9);
//	insertAtLast(dou,10 );
//	insertAtLast(dou,11);
//	insertAtLast(dou,11);
//	insertAtLast(dou,11);
	//insertAtPos(dou,2,12);
	//addNewNodeWithSort(dou,8);
	//deleteAtPos(dou,1);
	//deleteNodeSameWithListSort(dou);
	printList(dou);
	return 0;
}

