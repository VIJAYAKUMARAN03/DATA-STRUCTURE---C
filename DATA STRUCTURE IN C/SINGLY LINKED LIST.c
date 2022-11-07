#include<stdio.h>
#include<stdlib.h>

void insert();
void display();
void display1();
void addbegin();
void addmid();
void addend();
void length();
void delend();
void delmid();
void delbegin();
void choice();
int len();


struct node
{
    int data;
    struct node *next;
};


struct node *head;


int main()
{
    int n,i=0;
    printf("enter no. of elements : ");
    scanf("%d",&n);
    while(i<n)
    {
        insert();
        i++;
    }
    display();
}


void choice()
{
    printf("\nContinue with choice?\n1 - Yes (or) 2 - No\n");
    int h;
    scanf("%d",&h);
    if(h==1)
    {
    int a;
    printf("Enter:\n1-To display\n2-To insert a node in end\n3-To insert a node in middle\n4-To insert a node in begining\n");
    printf("5-Length \n6-To delete a node in end\n7-To delete a node in middle\n8-To delete a node in begining\n");
    printf("Enter here : ");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
        display1();
        break;
        case 2:
        addend();
        break;
        case 3:
        addmid();
        break;
        case 4:
        addbegin();
        break;
        case 5:
        length();
        break;
        case 6:
        delend();
        break;
        case 7:
        delmid();
        break;
        case 8:
        delbegin();
        break; 
    }
    }
    else
    printf("Program Finished");
} 


void insert()
    {
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        printf("No sufficient memory");
        else
        {
            printf("enter data \n");
            scanf("%d",&newnode->data);
            newnode->next=NULL;
        }
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            struct node *temp;
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    
    
void display()
{
    struct node *p;
    p=head;
    while(p!=NULL)
    {
        printf("%d->%p\n",p->data,p->next);
        p=p->next;
    }
}

void display1()
{
    display();
    choice();
}


void addbegin()
{
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&new->data);
    new->next=NULL;
    if(head==NULL)
    head=new;
    else
    {
        new->next=head;
        head=new;
    }
    display();
    choice();
}


void addmid()
{
    struct node *new;
    int po,l,i=1;
    new=(struct node*)malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d",&new->data);
    new->next=NULL;
    printf("Enter the position : ");
    scanf("%d",&po);
    l=len();
    if(po>l)
    {
        printf("Position is invalid");
    }
    else
    {
        struct node *p,*q;
        p=head->next;
        q=head;
        while(i<po-1)
        {
            i++;
            q=q->next;
            p=p->next;
        }
        new->next=p;
        q->next=new;
        display();
    }
    choice();
}


void addend()
{
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&new->data);
    new->next=NULL;
    struct node *t;
    t=head;
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=new;
    }
    display();
    choice();
}


void length()
{
    int l;
    l=len();
    printf("%d",l);
    choice();
}


void delend()
{
    struct node *x,*y;
    x=head->next;
    y=head;
    while(x->next!=NULL)
    {
        x=x->next;
        y=y->next;
    }
    y->next=NULL;
    free(x);
    display();
    choice();
}


void delmid()
{
    struct node *r,*s;
    int po,i=1,l;
    l=len();
    printf("Enter the position : ");
    scanf("%d",&po);
    r=head->next;
    s=head;
    while(i<po-1)
    {
        r=r->next;
        s=s->next;
    }
    s->next=r->next;
    r->next=NULL;
    free(r);
    display();
    choice();
}


void delbegin()
{
    struct node *t;
    t=head;
    head=t->next;
    t->next=NULL;
    free(t);
    display();
    choice();
}


int len()
{
    struct node *l;
    int c=0;
    l=head;
    while(l!=NULL)
    {
        c++;
        l=l->next;
    }
    return(c);
}



