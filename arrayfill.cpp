#include<iostream>
using namespace std;
int main(){
	int F[100][100];
	int n;
	cout<<"n= ";cin>>n;
	for(int i=1;i<n;i++)
	{
		F[0][i]=0;
	}
	F[0][0]=1;
	for(int m=0;m<n;m++){
		for(int v=0;v<n;v++){
			if(v<m) F[m][v]=F[m-1][v];
			else F[m][v]=F[m-1][v]+F[m][v-m];
		}
	}
	cout<<F[n-1][n-1];
return 0;
}
