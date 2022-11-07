#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front,*rear;

struct node *create()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    scanf("%d",&newnode->data);
    return(newnode);
}

void enqueue()
{
    struct node *newnode;
    newnode=create();
    if(rear==NULL&&front==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue()
{
    struct node *t;
    t=front;
    front=front->next;
    free(t);
}

void display()
{
    struct node *t;
    t=front;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    enqueue();
    
    display();
}
