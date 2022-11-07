//INFIX TO POSTFIX USING STACK
#include<stdio.h>
char st[20],top=-1;
void push(char c)
{
    top++;
    st[top]=c;
}
void pop()
{
    printf("%c",st[top]);
    top--;
}
void fpop()
{
    while(st[top]!='(')
    {
        pop();
    }
    top--;
}
void display()
{
    int t;
    t=top;
    while(t!=-1)
    {
        printf("%c",st[t]);
        t--;
    }
}
void comp(char c)
{
    if(c=='(')
        {
            push(c);
        }
        else if(c==' ')
        {
            
        }
        else if(c=='+'||c=='-')
        {
            if(st[top]=='*'||st[top]=='/'||st[top]=='^')
            {
                pop();
                comp(c);
            }
            else if(st[top]=='+'||st[top]=='-')
            {
                pop();
                push(c);
            }
            else
            push(c);
        }
        else if(c=='*'||c=='/')
        {
            if(top==-1||st[top]=='(')
            push(c);
            else if(st[top]=='^')
            {
                pop();
                comp(c);
            }
            else if(st[top]=='*'||st[top]=='/')
            {
                pop();
                push(c);
            }
            else if(st[top]=='+'||st[top]=='-')
            push(c);
            else
            {
                pop();
                comp(c);
            }
        }
        else if(c=='^')
        {
            if(st[top]=='*'||st[top]=='/'||st[top]=='+'||st[top]=='-')
            {
                push(c);
            }
            else if(st[top]=='^')
            {
                pop();
                comp(c);
            }
            else
            push(c);
        }
        else if(c==')')
        {
            fpop();
        }
        else
        printf("%c",c);
}
int main()
{
    char s[30];
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++)
    {
        comp(s[i]);
    }    
    display();
}
//c,u-2,d-3,c-4

