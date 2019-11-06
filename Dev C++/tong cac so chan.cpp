#include<stdio.h>;
int main(){
int a[100],n,s;
printf("\nNhap vao so phan tu torng mang: ");
scanf("%d",&n);
//Nhap cac phan tu
printf("\nNhap mang: ");
for(int i=0;i<n;i++){
	scanf("%d",&a[i]);
}
for(int i=0;i<n;i++){
	if(a[i]%2==0){
		s+=a[i];
	}
}
printf("\nTong cac gia tri chan la: %d",s);
return 0;
}
