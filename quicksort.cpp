#include<iostream>
using namespace std;
void hoanvi(int &a,int &b)
{
	int t=b;
	b=a;
	a=t;
}
void quicksort(int a[],int l,int r)
{
	int i,j,chot;
	if(l<r)
	{
		i=l+1;
		j=r;
		chot=a[l];
		while(i<j)
		{
			while(a[i]<chot)i++;
			while(a[j]>chot)j--;
			if(i<j) hoanvi(a[i],a[j]);
		}
		hoanvi(a[j],a[l]);
		quicksort(a,l,j-1);
		quicksort(a,j+1,r);
	}	
}
void NhapMang(int a[],int n)
{
	cout<<"\nNhap mang:";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];	
	}
}
void XuatMang(int a[],int n)
{
	cout<<"Xuat mang: ";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}
int main()
{
	int arr[100],n;
	cout<<"\nNhap so phan tu trong mang: ";
	cin>>n;
	NhapMang(arr,n);
	quicksort(arr,0,n-1);
	XuatMang(arr,n);
}
