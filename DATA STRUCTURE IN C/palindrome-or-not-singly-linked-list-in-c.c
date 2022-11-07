#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void compare();
struct node
{
    char data;
    struct node *next;
};


struct node *head1,*head2;


void main()
{
    int i,j;
    char s[20];
    printf("Enter the string : ");
    scanf("%s",s);
    for(i=0,j=strlen(s)-1;i<strlen(s),j>=0;i++,j--)
        {
        struct node *n,*m;
        m=(struct node*)malloc(sizeof(struct node));
        n=(struct node*)malloc(sizeof(struct node));
        if(n==NULL || m==NULL)
        {
            printf("No sufficient memory");
        }
        m->data=s[i];
        n->data=s[j];
        m->next=NULL;
        n->next=NULL;
        if(head1==NULL || head2==NULL)
        {
            head1=m;
            head2=n;
        }    
        else
        {
            struct node *temp1,*temp2;
            temp1=head1;
            temp2=head2;
        while(temp1->next!=NULL || temp2->next!=NULL)
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
            temp1->next=m;
            temp2->next=n;
        }
    }
    compare();
}    
void compare()
{
    int k=0;
    struct node *p,*q;
    p=head1;
    q=head2;
    while(p!=NULL || q!=NULL)
    {
        if(p->data!=q->data)
        {
            k=1;
        }
        p=p->next;
        q=q->next;
    }
    if(k==0)
    {
    printf("String is palindrome");
    }
    else
    {
        printf("String is not palindrome");
    }
}
