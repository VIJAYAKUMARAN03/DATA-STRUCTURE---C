/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <time.h>
int min(int a,int b)
{
    if(a<b)
    return a;
    return b;
}
int gcd(int a,int b)
{
    int t;
    t=min(a,b);
    A:
    while(a%t!=0)
    t--;
    
    if(b%t==0)
    return t;

    t--;
    goto A;
}
int main()
{
    float t1=0,t2=0;
    int i,a,b,g;
    scanf("%d %d",&a,&b);
    clock_t start=clock();
    g=gcd(a,b);
    printf("%d\n",g);
    clock_t end=clock();
    t1=end-start;
    t1=t1/CLOCKS_PER_SEC;
    printf("%f",t1);
    
    return 0;
}

