#include <stdio.h>
#include <time.h>

int SelectionSort(int *a,int n)
{
    int i,j,min,t;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(*(a+j)< *(a+min))
            min=j;
        }
        t=*(a+min);
        *(a+min)=*(a+i);
        *(a+i)=t;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
}


int main()
{
    float t1=0,t2=0;
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    clock_t start=clock();
    SelectionSort(a,n);
    clock_t end=clock();
    t1=end-start;
    t1=t1/CLOCKS_PER_SEC;
    printf("\nEXECUTION TIME : %f",t1);
    return 0;
}
