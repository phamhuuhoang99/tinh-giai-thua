#include<iostream>
using namespace std;
void thapHN(int n,int x,int y)
{
	if(n==1) cout<<"\nChuyen 1 dia tu "<<x<< " sang "<<y;
	else{
		thapHN(n-1,x,6-x-y);
		thapHN(1,x,y);
		thapHN(n-1,6-x-y,y);	
	}
}
int main()
{
	thapHN(3,1,2);
}	
