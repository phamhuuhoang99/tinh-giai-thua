// Viet chu hoa dau thanh con lai chu thuong
// Khai bao cac ham thu vien neu co
#include<stdio.h>
#include<conio.h>
#include<string.h>// ham thu vien
#define SIZE 100
int main()
{
    char S[SIZE];
    gets(S);
    int n=strlen(S);
    if(S[0]>='A' && S[0]<='Z')// Chuyen ki tu dau thanh hoa
        printf("%c",S[0]);
    else
        printf("%c",S[0]-32);// neu thuong thi chuyen thanh hoa
    for(int i=1;i<n;i++)
    {
        if(S[i]!=' ')// ki tu tiep theo cach khac khoang trang
        {
            if(S[i]>='A' && S[i]<='Z')// chu hoa thanh thuong
                printf("%c",S[i]+32);
            else
                printf("%c",S[i]);// neu ko giu nguyen
        }
        else// neu ko gap khoang trang
        {
            printf("%c",S[i]);
            if(S[i+1]>='A' && S[i+1]<='Z') // tuong tu
            {
                printf("%c",S[i+1]);
                i++;
            }
            else
            {
                printf("%c",S[i+1]-32);
                i++;
            }
        }
    }
}
