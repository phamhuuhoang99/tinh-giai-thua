#include<iostream> 
using namespace std;
struct Node
{
	int data;
	Node *pNext;
};
struct SingleList
{
	Node *pHead;
};
void Initialize(SingleList &list) {
	list.pHead = NULL;
}
Node *CreateNode(int d)
{
	Node *pNode = new Node;
	if (pNode != NULL) {
		pNode->data = d;
		pNode->pNext = NULL;
	}
	else
	{
		cout << "Error allocated memory";
	}
	return pNode;
}
void PrintList(SingleList list) 
{
	Node *pTemp = list.pHead;
	if (pTemp == NULL) {
		cout << "The list is empty";
		return;
	}
		while(pTemp!= NULL) {
			cout << pTemp->data << "\t";
			pTemp = pTemp->pNext;
		}
}
int SizeOfList(SingleList list) {
	Node *pTemp = list.pHead;
	int nSize = 0;
	while (pTemp!=NULL)
	{
		pTemp = pTemp->pNext;
		nSize++;
	}
	return nSize;
}
void InsertFirst(SingleList &list,int d) {
	Node *pNode =CreateNode(d);
	if (list.pHead = NULL) {
		list.pHead = pNode;
	}
	else {
		pNode->pNext = list.pHead;
		list.pHead = pNode;
	}
}
int main() {
	SingleList list;
	Initialize(list);
	InsertFirst(list, 10);
	InsertFirst(list, 5);
	InsertFirst(list, 7);
	InsertFirst(list, 3);
	PrintList(list);
	system("pause");
//	return 0;
}
