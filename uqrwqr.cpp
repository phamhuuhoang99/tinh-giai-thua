#include<stdio.h>
#include<conio.h>
#include<string.h>
struct ngaythangnamsinh
{
	int ngay;
	int thang;
	int nam;
};
struct sinhvien
{
	char mssv[100];
	char hoten[100];
	struct ngaythangnamsinh ngaysinh;
};
void Xuat(sinhvien sv)
{
	
	printf("%s           %s             %d/%d/%d\n",sv.mssv,sv.hoten,sv.ngaysinh.ngay,sv.ngaysinh.thang,sv.ngaysinh.nam);
}
int main()
{
	int n,i;
	struct sinhvien sv;
	printf("Nhap so luong sinh vien: ");
	scanf("%d",&n);
	struct sinhvien mta[100];
	for(i=0;i<n;i++)
	{
		printf("Nhap du lieu sinh vien thu %d: ",i+1);
		printf("Ma so SV: ");fflush(stdin);
		gets(sv.mssv);
		printf("Ho va ten: ");fflush(stdin);
		gets(sv.hoten);
		printf("Ngay sinh: ");
		scanf("%d", &sv.ngaysinh.ngay);
		printf("\nThang sinh: ");
		scanf("%d",&sv.ngaysinh.thang);
		printf("\nNam sinh: ");
		scanf("%d",&sv.ngaysinh.nam);
		mta[i]=sv;	
	}
	printf("\n --------- Thong tin sinh vien -----\n");
	//printf("%s          %s             %s\n", sv.mssv,sv.hoten,sv.ngaythangnamsinh);
	for(int i=0;i<n;i++)
	{
		Xuat(mta[i]);		
	}
	getch();
	return 0;
}
