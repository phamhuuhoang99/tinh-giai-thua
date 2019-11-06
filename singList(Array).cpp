#include<stdio.h>
#define MAXSIZE 100
typedef struct SingleList{
	int Elements[MAXSIZE];
	int size;
};
void makeEmptyList(SingleList &list){
	list.size=0;
}
bool isEmptyList(SingleList list){
	if(list.size==0) return true;
	return false;
}
bool isFullList(SingleList list){
	if(list.size==MAXSIZE-1) return true;
	return false;
}
int CreatItem(int x){
	int temp;
	scanf("%d",&temp);
	return temp;
}
void insertAtFist(SingleList &list,int x){
	if(isFullList(list)){
		printf("List full");
		return;
	}
	for(int i=list.size;i>0;i--){
		list.Elements[i]=list.Elements[i-1];
	}
	list.Elements[0]=x;
	list.size++;
}
void insertAtLast(SingleList &list,int x){
	if(isFullList(list)){
		printf("List full");
		return;
	}
	list.size++;
	list.Elements[list.size-1]=x;
	
}
void insertAtPos(SingleList &list,int pos,int x){
	if(isFullList(list)){
		printf("List full");
		return;
	}
	if(pos<1||pos>list.size){
		printf("Could not found position");
	}
	for(int i=list.size;i>=pos-1;i--){
		list.Elements[i]=list.Elements[i-1];
	}
	list.Elements[pos-1]=x;
	list.size++;	
}
void printList(SingleList list){
	for(int i=0;i<list.size;i++){
		printf("%d ",list.Elements[i]);
	}	
}
void deleteAtFirst(SingleList &list){
	if(isEmptyList(list)){
		printf("List empty");
		return;
	}
	for(int i=0;i<list.size;i++){
		list.Elements[i]=list.Elements[i+1];
	}
	list.size--;
}
void deleteAtLast(SingleList &list){
	if(isEmptyList(list)){
		printf("List empty");
		return;
	}
	//list.Elements[list.size-1]='\0';
	list.size--;
}
void deleteAtPos(SingleList &list,int pos){
	if(isEmptyList(list)){
		printf("List empty");
		return;
	}
	if(pos<1||pos>list.size){
		printf("Could not found position");
		return;
	}
	for(int i=pos-1;i<list.size;i++){
		list.Elements[i]=list.Elements[i+1];
	}
	list.size--;
}
void CreatListFromFile(SingleList &list){
	FILE *fin;
	fin=fopen("input.txt","r");
	if(fin==NULL){
		printf("Could not found file");
		return;
	}
	int n,x;
	fscanf(fin,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(fin,"%d",&x);
		insertAtLast(list,x);
	}
}
int main(){
	SingleList list;
	makeEmptyList(list);
	CreatListFromFile(list);
	//insertAtFist(list,5);
	//insertAtFist(list,6);
	//insertAtLast(list,10);
	//insertAtLast(list,10);
	//insertAtPos(list,2,9);
	//deleteAtFirst(list);
	//deleteAtLast(list);
	//deleteAtPos(list,2);
	printList(list);
	return 0;
}


	
