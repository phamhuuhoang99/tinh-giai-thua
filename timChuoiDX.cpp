#include<string>
#include<iostream>
using namespace std;
string KTDX(string s)
{
	int len=s.length();
	for(int i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-1-i])
		{
			return "\nChuoi khong doi xung";
		}	
	}
	return "\nChuoi doi xung";
}
int main()
{
	string s;
	int LuaChon;
	cout<<"\nNhap chuoi: ";
			getline(cin,s);
			cout<<KTDX(s);

	do{
		cout<<"\n----------------Menu----------\n";
		cout<<"\n1.Nhap tiep ";
		cout<<"\n2.Thoat\n ";
		cout<<"\nNhap Lua chon: ";
		cin>>LuaChon;
		if(LuaChon==1)
		{
			cin.ignore() ;
			cout<<"\nNhap chuoi: ";
			getline(cin,s);
			cout<<KTDX(s);
		}
	}while(LuaChon!=2);
	return 0;	
}
