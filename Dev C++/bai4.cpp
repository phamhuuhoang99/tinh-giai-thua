#include<stdio.h>
int GiaiThua(int x){
    int s=1;
    for(int i=1;i<=x;i++)
    {
        s*=i;
    }
return s;
}
int main()
{
    int k,n,tohop;
    printf("\nNhap k: ");
    scanf("%d",&k);
    printf("\nNhap n: ");
    scanf("%d",&n);
    tohop=GiaiThua(n)/(GiaiThua(k)*GiaiThua(n-k));
    printf("\nTo hop chap k cua n phan tu la: %d ", tohop);
    return 0;
}
