#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	printf("\nNhap chuoi: ");
	gets(str);
	int n=strlen(str);
	for(int i=0;i<n;i++)
	{
		if(str[i]==' ')
		{
			strcpy(str+i,str+i+1);
			i--;
		}
	}	
	puts(str);
	return 0;
}
	
