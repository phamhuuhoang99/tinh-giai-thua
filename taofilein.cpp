#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fout;
	fout=fopen("inputmax.txt","w+");
	int a[100000];
	for(int i=0;i<100000;i++){
		a[i]=rand()%100000;
	}
	for(int i=0;i<100000;i++){
		fprintf(fout,"%d ",a[i]);
	}
}	
