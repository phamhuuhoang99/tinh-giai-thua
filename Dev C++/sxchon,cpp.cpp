#include<stdio.h>

void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}	
void SapXepChon(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(arr[min]>arr[j]){
				min=j;
			}	
		}
		swap(arr[i],arr[min]);	
	}	
}
void docFile(int arr[],int &n){
	FILE *fin;
	fin=fopen("sapxep.inp.txt","r");
	fscanf(fin,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(fin,"%d",&arr[i]);
	}
	fclose(fin);
}
void XuatMang(int arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
int main(){
	int arr[100],n;
	docFile(arr,n);
	SapXepChon(arr,n);
	XuatMang(arr,n);
	return 0;
}	
