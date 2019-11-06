#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
    int dem = 0;
    char arr[100];
    FILE *f;
    f = fopen("inputngoac.txt","r");
    fgets(arr, 100, f);
    puts(arr);
    printf("\nCHECK (ENTER):\n");
    getch();
    if(arr[0] == ')')
	    printf("\nSai vi mo dau khac (" );
    else{
	    for(int i=0; i<strlen(arr); i++){
		    if( arr[i] == '(' ) dem++;
			else dem--;
		}
		if(dem==0) printf("\nDung vi ( = ) ");
		else printf("\nSai vi ( khac )" );
	}
	getch();
}
