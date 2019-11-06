#include<iostream>
using namespace std;
int main(){
	int Current[100];
	int Next[100];
	Current[0]=1;
	int N;
	cout<<"Nhap N: ";
	cin>>N;
	for(int i=1;i<=N;i++){
		Current[i]=0;
	} 
	for(int m=1;m<=N;m++){
		for(int v=0;v<=N;v++){
			if(m>v) Next[v]=Current[v];
			else Next[v]=Current[v]+Next[v-m];
		}	
		for(int i=0;i<=N;i++){
			Current[i]=Next[i];
		}	
	}
	cout<<Current[N];
}	
