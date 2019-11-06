#include<stdio.h>
void swap(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}
void SelectedSort(int arr[],int n){
    int min;
	for(int i=0;i<n-1;i++){
	    min=i;
		for(int j=i+1;j<n;j++){
			if(arr[min]>arr[j]){
			    min=j;
			}
			swap(arr[i],arr[min]);
		}	
	}	

}	
int main(void) {
	
	return 0;
}

