#include<iostream>
using namespace std;
void InsertionSort(int arr[],int n){
	int tmp,j;
	for(int i=1;i<n;i++){
		tmp=arr[i];
		j=i-1;
		while(j>=0&&tmp<arr[j]){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=tmp;
	}
}
int main(){
	int arr[]={5,3,15,8,7,30};
	InsertionSort(arr,6);
	for(int i=0;i<6;i++)
	{
		cout<<arr[i];
	}
}

