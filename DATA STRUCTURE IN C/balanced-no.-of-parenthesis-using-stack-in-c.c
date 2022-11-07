#include<stdio.h>

char st[20],e[20];
int top=-1;

void push(char c)
{
    top=top+1;
    st[top]=c;
}

void pop()
{
    top=top-1;
}

int main()
{
    scanf("%s",e);
    for(int i=0;e[i]!='\0';i++)
    {
        if(e[i]=='(' || e[i]=='{' || e[i]=='[')
        {
           push(e[i]); 
        }
        if((e[i]==')' && st[top]=='(')||(e[i]=='}' && st[top]=='{')||(e[i]==']' && st[top]=='['))
        {
            pop();
            if(top==-2)
            break;
        }
        else if(e[i]==')' || e[i]=='}' || e[i]==']')
        {
            push(e[i]);
        }
    }
    printf("%s\n",e);
    if(top==-1)
    {
        printf("BALANCED");
    }
    else
    printf("NOT BALANCED");
}
//c,u-2,d-3,c-1
