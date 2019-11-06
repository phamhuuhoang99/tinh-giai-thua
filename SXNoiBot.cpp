#include<stdio.h>
void swap(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}
void BubbleSort(int A[], int n) {
  for(int i = n-1; i > 0; i--){
       for(int k = 0; k < i; k++) {
           if (A[k] > A[k+1]) {
               Swap(A[k], A[k+1]); //doi vi tri A[k] và A[k+1]
           }
       }
   }
}
int main(){
	int n=5;
	int arr[]={5,15,3,7,29};
	BubbleSort(arr,n);
	for(int i=0;i<5;i++){
		printf("%d",arr[i]);
	}	
	return 0;
}	
