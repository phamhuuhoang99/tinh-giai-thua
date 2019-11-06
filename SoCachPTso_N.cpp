#include<iostream>
using namespace std;
int main(){
	int F[100][100];
	F[0][0]=1;
	int N;
	cout<<"Nhap so N: ";
	cin>>N;
	for(int i=1;i<=N;i++){
		F[0][i]=0;
	}
	for(int m=1;m<=N;m++){
		for(int v=0;v<=N;v++){
			if(m>v) F[m][v]= F[m-1][v];
			else F[m][v]=F[m-1][v]+F[m][v-m];
		}	
	}	
	cout<<F[N][N];
	return 0;
}	
