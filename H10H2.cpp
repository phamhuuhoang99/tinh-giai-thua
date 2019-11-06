#include<iostream>
using namespace std;
void H10H2(int x)
{
	if(x>0)
	{
		int sodu=x%2;
		x/=2;
		H10H2(x);
		cout<<sodu;
	}
}
int main()
{
	H10H2(13);
}
	
