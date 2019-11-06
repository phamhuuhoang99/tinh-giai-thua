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
void SapXepNoiBot(int arr[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>=i+1;j--){
			if(arr[j]<arr[j-1]){
				swap(arr[j],arr[j-1]);
			}
		}
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
//-------------------------
//ham chia mang thanh 2 phan, dung chot pivot
int partition(int a[],int low, int high)
{
	int pivot=a[high];
	int left=low;
	int right=high-1;
	while (true)
	{
		while (left<= right && a[left]<pivot) left++;
		while (right >=left && a[right]>pivot) right--;
		if(left>=right) break;
		swap(a[left++],a[right--]);
	}
	swap(a[left],a[high]);
	return left;
}
void qiuck_sort(int a[],int low,int high)
{
	if(low<high)
	{
		int pivot=partition(a,low,high);
		qiuck_sort(a,low,pivot-1);
		qiuck_sort(a,pivot+1,high);
	}
}
int timkiem_nhiphan(int arr[], int n, int x)
{
	int mid;
	int left = 0; 
	int right = n-1;
	while (left <= right)
	{
		mid = (left+right)/2;
		if (x < arr[mid]) right = mid - 1;
		else if (x > arr[mid]) left= mid + 1;
		else return mid;
	}
	return -1;
}
int timkiem_tuantu(int arr[],int n,int x){
	int i=0;
	while(i!=n&&arr[i]!=x){	
		i++;
	}
	if(i==n){
		printf("Khong tim thay x");
		return -1;
	}
	return i;
	
} 
void docFile(int arr[],int &n){
	FILE *fin;
	fin=fopen("inputmax.txt","r");
	if(fin==NULL){
		printf("Khong tim thay file");
		return;
	}
	fscanf(fin,"%d",&n);
	for(int i=0;i<n;i++){
		fscanf(fin,"%d",&arr[i]);
	}
	fclose(fin);
}

void ghiFile(int arr[],int n){
	FILE *fout;
	fout=fopen("sapxep.out.txt","w+");
	for(int i=0;i<n;i++){
		fprintf(fout,"%d ",arr[i]);
	}
	fclose(fout);
}
void XuatMang(int arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
int main(){
	int arr[100000],n;
	docFile(arr,n);
	//SapXepChon(arr,n);25.43s
	SapXepNoiBot(arr,n);//55.03s
	//insertionSort(arr,n);
	//SapXepChen(arr,n);16.6s
	//qiuck_sort(arr,0,n-1);//7.8s
//	int timkiem=timkiem_nhiphan(arr,n,5);
//	if(timkiem==-1){
//		printf("ko tim thay x");
//	}
//	else {
//		printf("tim thay x %d ",timkiem);
//		
//	}
	XuatMang(arr,n);
	//ghiFile(arr,n);
	return 0;
}	
