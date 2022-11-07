#include <stdio.h>

int main()
{
    int i,j,n,a,c,a1,d;
    scanf("%d",&n);
    for(i=0;i<2*n-1;i++)
    {
        a=a1=i;
        if(i>n-1)
        {
            a=a1=n-(i-n)-2;
        }
        for(j=0;j<2*n-1;j++)
        {
            if(j<n)
            {
                while(a>=0)
                {
                    c=n-j;
                    printf("%d ",c);
                    j++;
                    a--;
                }
                if(j<n)
                printf("%d ",c);
            }
            else
            {
               d=a1;
                while(a1<n-1)
                {
                    printf("%d ",c);
                    j++;
                    a1++;
                }
                c++;
                if(c<=n)
                printf("%d ",c);
                if(d==n-1 && j==2*n-2  && c<n)
                {
                    c++;
                    printf("%d ",c);
                }
            }   
        }
        printf("\n");
    }
}