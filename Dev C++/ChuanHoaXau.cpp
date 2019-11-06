#include<stdio.h>
#include<string.h>
int main()
{
	char HoTen[50];
	printf("\nNhap vao Ten: ");
	gets(HoTen);
	//Chuan Hoa Xau
	int l =strlen(HoTen);
	// Xoa khoang trang dau xau
	while(HoTen[0]==' ')
	{
		strcpy(HoTen,HoTen+1);
	}
	//xoa Khoang trang giua cac tu trong xau;
	for(int i=0;i<l-1;i++)
	{	
		while(HoTen[i]==' '&&HoTen[i+1]==' ')
		{
			strcpy(HoTen+i,HoTen+i+1);
		}
	}
	
	puts(HoTen);
}
