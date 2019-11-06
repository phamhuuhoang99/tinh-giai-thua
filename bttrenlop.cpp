#include<stdio.h>
#include<stdlib.h>
typedef struct node *NODE;
struct node{
	int data;
	*node Lpointer;
	*node Rpointer;
};
NODE* createNode(int x){
	NODE *Temp=(NODE*)malloc(sizeof(NODE));
	Temp->data=x;
	Temp->Lpointer=Temp->Rpointer=NULL;
}
void InsertNode(NODE* &root,int a[],int n){
	
	for(int i=0;i<n;i++){
		NODE *Ins=createNode(a[i]);
		NODE *temp=root;
		if(temp==NULL) temp =Ins;
		else{
			if(temp->Lpointer==NULL){
				
			}
			
		} 
	}
}	
