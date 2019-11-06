#include<stdio.h>
void outPut(int n, int a[]) {
	int i;
	for (int i = 1; i <= 3; i++)
		a[i] = i;
	do {
		//xu?t m?ng
		for (int i = 1; i <= 3; i++) {
			printf("%d ", a[i]," , ");
			
		}
		printf("\n");
		i = 3;
		while (i > 0 && a[i] == n + i - 3)
		{
			i--;
		}
		if (i > 0) {
			a[i]++;
			for (int j = i + 1; j <= 3; j++) {
				a[j] = a[j - 1] + 1;
			}
		}
	} while (i != 0);

}
int main() {
	int n, a[100];
	printf("\nNhap n: ");
	scanf("%d", &n);
	outPut(n, a);

	return 0;
}

