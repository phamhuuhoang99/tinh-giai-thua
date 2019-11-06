#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	char data;
	Node *pNext;
};
typedef Node *List;
void push(List *first,char info)
{
	Node *top;
	top=(Node*)malloc(sizeof(Node));
	top->data=info;
	top->pNext=*first;
	(*first)=top;		
}
void pop(List first){
	Node *top;
	top=first;
	while(top!=NULL){
		printf("%c",top->data);
		top=top->pNext;
	}
}
	int main()
	{
		List first=NULL;
		int n;
		int cs;
		int a[100];
		char b[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
		printf("Nhap so n:");
		scanf("%d",&n);
		printf("\nNhap co so can chuyen doi");
		scanf("%d",&cs);
		int k=0;
		while(n>0){
			int r=n%cs;
			a[k]=r;
			push(&first,b[a[k]]);
			n/=cs;
			k++;
		}
		pop(first);
	}
