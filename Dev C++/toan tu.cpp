#include<stdio.h>
int main() {
	char o;
	float A, B, kq;
	printf("\nNhap so A: ");
	scanf("%f", &A);
	printf("\nNhap so B: ");
	scanf("%f", &B);
	fflush(stdin);	
	printf("\nNhap vao toan tu: ");
scanf("%c",&o);
	switch (o)
	{
	case '+':
	{
		kq = A + B;
		printf("\nA + B = %f ", kq);
		break;
	}
	case '-':
	{
		kq = A - B;
		printf("\nA - B = %f ", kq);
		break;
	}
	case '*':
	{
		kq = A*B;
		printf("\nA * B = %f ", kq);
		break;
	}
	case '/':
	{   kq = A / B;
	printf("\nA / B = %f ", kq);
	break;
	}
	case '%':
	{
		kq = int(A) % int(B);
		printf("A % B = %d ", kq);
		break;
	}
	default:
		printf("\nToan tu khong hop le: ");
	}
}
