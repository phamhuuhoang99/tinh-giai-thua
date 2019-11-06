#include<iostream>
using namespace std;
int main(){
	int F[100];
	F[0]=1;
	int N;
	cout<<"Nhap N:";
	cin>>N;
	for(int i=1;i<=N;i++){
		F[i]=0;
	}	
	for(int m=1;m<=N;m++){
		for(int v=m;v<=N;v++){
			F[v]=F[v]+F[v-m];
		}	
	}	
	cout<<F[N];
}	
