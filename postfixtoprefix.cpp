#include<stdio.h>
#include<string.h>
char stack[20];
char num[10]={'0','1','2','3','4','5','6','7','8','9'};
int top = -1;
void push(char x)
{
    top=top+1;
	stack[top] = x;
}
 
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

bool TestNum(char c){
     int i = 0;
     while ((i < 10)&&(c != num[i])) ++i;
     if (i < 10) return true;
     else return false;
}
 
int pri(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

int pow(int x, int y)
{
	int p=1;
	for(int i=0;i<y;i++)
	{
		p=p*x;
	}
	return p;
}

int Tinh(char a[], int n)
{
	int m = 0;
    for (int i = 0; i <= n;i++){
        int j = 0;    
        while ((j < 10)&&(a[i] != num[j])) j++;
        m += j*pow(10,n-i);
    }
    return m;
}

 
main()
{
    char exp[20];
    char x;
    char cnum[20];
    printf("Nhap bieu thuc : ");
    scanf("%s",exp);
    int i=0;
    while(exp[i] != '\0')
    {
        if(TestNum(exp[i]))
        {
        	int m=-1;
        	while((i<strlen(exp)) && (TestNum(exp[i])))
        	{
        		cnum[++m]=exp[i++];
			}
			m=Tinh(cnum,m);
			printf("%d ",m);
		}
        if(exp[i] == '(')
            push(exp[i]);
        if(exp[i] == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(pri(stack[top]) >= pri(exp[i]))
            {
				    x=pop();
					printf("%c ",x);
            }
			push(exp[i]);
        }
        i++;
    }
    while(top != -1)
    {
        printf("%c",pop());
        top--;
    }
    
}
