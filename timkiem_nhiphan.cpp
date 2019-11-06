#include<stdio.h>
int timkiem_nhiphan(int a[], int n, int x)
{
	int t, p, g;
	t = 0; 
	p = n-1;
	while (t <= p)
	{
		g = (t+p)/2;
		if (x < a[g]) p = g - 1;
		else if (x > a[g]) t = g + 1;
		else return(g);
	}
	return(n);
} 
int main(){
	int n=7;
	int arr[] ={5,4,6,10,22,89,77};
	int index=timkiem_tuantu(arr,n,22);
	printf("vi tri trong mang la:  %d",index);
	return 0;
}	

