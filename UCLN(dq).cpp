#include<iostream>
using namespace std;
int UCLN(int a,int b){
	if(a==b)return a;
	else{
		if(a>b) a-=b;
		else b-=a;
		UCLN(a,b);
	}
	
}
int main()
{
	 cout<<UCLN(10,15);
}
