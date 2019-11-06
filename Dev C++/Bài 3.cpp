#include <stdio.h>

int main()
{
    char Hoten[50];
    int ngay,thang,nam;
    char std[20];
    char email[50];
//Nh?p
    printf("\nNhap vao Ho va ten: ");
    gets(Hoten);
    printf("\nNhap ngay sinh: ");
    scanf("%d",&ngay);
    printf("\nNhap thang sinh: ");
    scanf("%d",&thang);
    printf("\nNhap nam sinh: ");
    scanf("%d",&nam);
    fflush(stdin);
    printf("\nNhap dia chi email: ");
    gets(email);
//xu?t
	printf("\nXuat: ");
    printf("\nHo ten la: ");
    puts(Hoten);
    printf("\nNgay Sinh: %d / %d /%d ",ngay,thang,nam);
    printf("\nDia chi email: ");
    puts(email);

    return 0;
}
