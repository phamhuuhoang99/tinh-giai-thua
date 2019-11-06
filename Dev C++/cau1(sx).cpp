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
void SapXepChen(int arr[],int n){
	for(int i=1;i<n;i++){
		int tmp=arr[i],j=i-1;
		while(j>=0&&tmp<arr[j]){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=tmp;
	}	
}
void SapXepNoiBot(int arr[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i+1;j--){
			if(arr[j]<arr[j-1]){
				swap(arr[j],arr[j-1]);
			}
		}
	}
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
void docFile(int arr[],int &n){
	FILE *fin;
	fin=fopen("sapxep.inp.txt","r");
	fscanf(fin,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(fin,"%d",&arr[i]);
	}
	fclose(fin);
}
void ghiFile(int arr[],int n){
	FILE *fout;
	fout=fopen("sapxep.out.txt","wt");
	for(int i=0;i<n;i++){
		fprintf(fout,"%3d",arr[i]);
	}
	fclose(fout);
}
void XuatMang(int arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
int main(){
	int arr[100],n;
	docFile(arr,n);
	//SapXepChon(arr,n);
	//SapXepChon(arr,n);
	SapXepNoiBot(arr,n);
	XuatMang(arr,n);
	ghiFile(arr,n);
	return 0;
}	
