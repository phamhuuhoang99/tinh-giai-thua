#include<stdio.h>
int timkiem_tuantu(int a[], int n, int x)
{
	int i;
	i = 0; 
	while ((i < n) && (a[i] != x)) i++;
	return(i);
}
int main(){
	int n=7;
	int arr[]={5,4,6,10,22,89,77};
	int index=timkiem_tuantu(arr,n,22);
	printf("vi tri trong mang la:  %d",index);
	return 0;
} 

