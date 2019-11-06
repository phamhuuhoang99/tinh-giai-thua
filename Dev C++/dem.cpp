#include<stdio.h>
#include<string.h>
int main()
{
	int dem=0;
	char str1[20],str2[10];
	gets(str1);
	gets(str2);
	int l=strlen(str1);
	for(int i=0;i<l;i++)
	{
		if(str2[0]==str1[i])
		{
			dem++;
		}
	}
	printf("so ky tu %c trong xau la: %d ",str2[0],dem);
	
}
