#include<iostream>
using namespace std;
int Tong=0;
int TongChuSo(int x)
{
	if(x>0)
	{
		int sodu=x%10;
		x/=10;
		Tong+=sodu;
		TongChuSo(x);	
	}
	return Tong;
}
int main()
{
	int x;
	cin>>x;
	cout<<TongChuSo(x);

}
