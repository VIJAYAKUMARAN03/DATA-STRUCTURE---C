/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <time.h>
int gcd(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    float t1;
    int a,b,g;
    scanf("%d%d",&a,&b);
    clock_t s=clock();
    g=gcd(a,b);
    printf("%d\n",g);
    clock_t e=clock();
    t1=e-s;
    t1=t1/CLOCKS_PER_SEC;
    printf("%f",t1);
    return 0;
}
