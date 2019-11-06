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
		int a=A;
		int b=B;
		int du;
		if(A==a&&B==b){
		du=a%b;
		printf("A %% B = %d ", du);
		}else{
		printf("toan tu nay chi thuc hien cho so nguyen");
		}
		break;
	}
	default:
		printf("\nToan tu khong hop le: ");
	}
return 0;
}
