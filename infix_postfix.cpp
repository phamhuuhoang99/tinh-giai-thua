#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char stack[100];
int top=-1;

void push(char item)
{
	if(top>=99) printf("Stack Overflow");
	else{
		top=top+1;
		stack[top]=item;
	}
}		
char pop()
{
	char item;
	if(top<0)
	{
	 	printf("stack null");
	 	getchar();
		 exit(1);
	}
	else{
		item=stack[top];
		top=top-1;
		return item;
	}
}
int timkiemtoantu(char symbol)
{
	if(symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	return 0;
}
int UuTien(char symbol)
{
	if(symbol == '*' || symbol == '/')
	{
		return 2;
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return 1;
	}
	return 0;
}
void InfixtoPostfix(char infix[],char postfix[])
{
	push('(');//dua vào dau stack ký tu (
	strcat(infix,")");//nôi vào chuoi infix ')'
	int i,j;
	char item;
	char x;
	i=0,j=0;
	
	item=infix[i];
	while(item!='\0')
	{
		if(item=='('){
			push(item);
		}
		else if(isdigit(item)||isalpha(item))
		{
			postfix[j]=item;
			j++;
		}
		else if(timkiemtoantu(item)==1)
		{
			x=pop();
			while(timkiemtoantu(item)==1&&UuTien(x)>=UuTien(item)){
				postfix[j]=x;
				j++;
				x=pop();			
			}
			push(x);//thêm lai cai x=pop() trong while lay ra
			push(item);
		}
		else if(item==')'){
				x=pop();
				while(x!='(')
				{
					postfix[j]=x;
					j++;
					x=pop();
				}
		}
		else
		{
			printf("Invalid infix Expression");
			getchar();
			exit(0);
			}
		i++;
		item=infix[i];
		postfix[j]='\0';
	}
}
int main(){
	char infix[100],postfix[100];
	gets(infix);
	InfixtoPostfix(infix,postfix);
	printf("PostFix:");
	puts(postfix);
	return 0;
}
