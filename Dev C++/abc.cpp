#include<stdio.h>

int main()
{
	int n,m,i,j;
	int a[100][100],b[100][100];
	printf("Nhap so hang : ");scanf("%d", &n);
	printf("Nhap so cot : ");scanf("%d", &m);
	for (i=0;i<n;i++){
	     for (j=0;j<m;j++)
		 {
		 	printf("\na[%d][%d] = ",i,j);scanf("%d",&a[i][j]);
		 }
	}
	for (j=0;j<n;j++){
	     for (i=0;i<m;i++)
	     {
	     	printf("\nb[%d][%d] = ",j,i);scanf("%d",&b[j][i]);
		 }
	}
    for (i=0;i<m;i++){
         for (j=0;j<n;j++)
         {
         	if(a[i][j]==b[i][j]) printf("\nHai ma tran la chuyen vi cua nhau. ");
         	else printf("\nHai ma tran ko la chuyen vi cua nhau. ");
		 }
	}
	return 0;
}
