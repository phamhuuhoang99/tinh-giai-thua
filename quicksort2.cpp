#include<iostream>
using namespace std;
void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
void QuickSort(int arr[],int left,int right){
	if(left>=right) return ;
	int i=left;
	int j=right;
	int pivot=arr[(left+right)/2];
	do{
		while(arr[i]<pivot) i++;
		while(arr[j]>pivot) j--;
		swap(arr[i],arr[j]);
		i++;
		j--;			
	}while(i<j);
	QuickSort(arr,left,j);
	QuickSort(arr,i,right);	
}

