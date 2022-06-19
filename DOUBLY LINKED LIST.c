#include<stdio.h>
#include<stdlib.h>

void choice();
void insert();
void display();
void display1();
void addbegin();
void addend();
void addmid();
int len();
void length();
void delend();
void delbegin();
void delmid();
struct node 
{
    int data;
    struct node *next,*prev;
};

struct node* create();
struct node *head;

int main()
{
    int i=0,n;
    printf("Enter the no. of elements : ");
    scanf("%d",&n);
    while(i<n)
    {
        insert();
        i++;
    }
    display();
    choice();
}

struct node* create()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(newnode==NULL)
    printf("No sufficient memory");
    else
    {
        return (newnode);
    }
}

void insert()
{
    struct node *newnode;
    newnode=create();
    if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            struct node *p;
            p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=newnode;
            newnode->prev=p;
        }
}
void display()
{
    struct node *p;
    p=head;
    while(p!=NULL)
    {
        printf("%p <- %d -> %p\n",p->prev,p->data,p->next);
        p=p->next;
    }
}

void display1()
{
    display();
    choice();
}
void addend()
{
    insert();
    display();
    choice();
}

void addbegin()
{
    struct node *newnode;
    newnode=create();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
    display();
    choice();
    
}

void addmid()
{
    struct node *newnode;
    newnode=create();
    int i=1,l,po;
    printf("Enter the position : ");
    scanf("%d",&po);
    l=len();
    if(po>l)
    printf("Position is invalid");
    else
    {
        struct node *p;
        p=head;
        while(i<po)
        {
            p=p->next;
            i++;
        }
        newnode->prev=p->prev;
        p->prev->next=newnode;
        newnode->next=p;
    }
    display();
    choice();
}
int len()
{
    struct node *p;
    p=head;
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;
}

void length()
{
    printf("Length = %d",len());
    choice();
}

void delend()
{
    struct node *p;
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->prev->next=NULL;
    p->prev=NULL;
    free(p);
    display();
    choice();
}

void delmid()
{
    int i=1,po,l;
    printf("Enter the position : ");
    scanf("%d",&po);
    l=len();
    if(po>l)
    printf("Position is invalid");
    else
    {
        struct node *p;
        p=head;
        while(i<po)
        {
            p=p->next;
            i++;
        }
        p->prev->next=p->next;
        p->next->prev=p->prev;
        p->prev=NULL;
        p->next=NULL;
        free(p);
    }
    display();
    choice();
}
void delbegin()
{
    struct node *p;
    p=head;
    head=p->next;
    p->next->prev=NULL;
    p->next=NULL;
    free(p);
    display();
    choice();
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

