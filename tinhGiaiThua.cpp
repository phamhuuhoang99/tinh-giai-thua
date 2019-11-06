#include<iostream>
using namespace std;
int tinhGiaiThua(int n)
{
	if(n==1) return 1;
	else return n*tinhGiaiThua(n-1);	
}
int main()
{
	int n; 
	cin>>n;
	cout<<tinhGiaiThua(n);
	return 0;
}
	
