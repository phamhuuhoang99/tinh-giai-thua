#include<stdio.h>
int main()
{
	int n,x;
	int arr[20];
	bool check=false;
	printf("nhap vao so phan tu trong mang:  ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nNhap vao x: ");
	scanf("%d",&x);
	
	for(int i=0;i<n;i++)
	{
		if(x==arr[i])
		{
			check=true;
			break;
	 	}
	}
	if(check==true)
		{
		printf("\nx co trong mang!! ");
		
		}
		else printf("\nx khong co trong mang!! ");
	return 0;
}
