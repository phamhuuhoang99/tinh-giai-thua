#include<iostream>
using namespace std;
int main()
{
	int x=3,y=6;
	while(x!=y)
	{	
		if(x>y)
		{
			x-=y;
		}
		else
		{
			y-=x;
		}
	}
	cout<<y;
	return 0;
}
