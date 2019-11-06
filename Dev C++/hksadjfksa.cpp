#include<stdio.h>
int tinhGiaiThua(int x)
{
	int s=1;
	for (int i = 1; i <= x; i++) {
		s *= i;
	}
	return s;
}
int main() {
	int n, k, tohop;
	printf("\nNhap vao gia tri cua n: ");
	scanf("%d", &n);
	printf("\nNhap vao gia tri cua k: ");
	scanf("%d", &k);
	tohop = tinhGiaiThua(n) / (tinhGiaiThua(n - k) * tinhGiaiThua(k));
	printf("\nTo hop chap k cua n phan tu la: %d", tohop);
	return 0;
}
