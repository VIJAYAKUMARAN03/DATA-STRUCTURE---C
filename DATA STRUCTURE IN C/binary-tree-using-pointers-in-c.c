#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
struct node *root;
struct node *create()
{
    int x;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data or enter -1 to null : ");
    scanf("%d",&x);
    if(x==-1)
    return 0;
    newnode->data=x;
    printf("Enter the left child of data %d : \n",newnode->data);
    newnode->left=create();
    printf("Enter the right chlid of %d : \n",newnode->data);
    newnode->right=create();
    return newnode;
}
void display()
{
    struct node *t1,*t2;
    t1=root;
    t2=root->right;
    while(t1->left!=NULL && t2->right!=NULL)
    {
        printf("child of data %d :\nLeft : %d  Right : %d\n",t1->data,t1->left->data,t1->right->data);
        t1=t1->left;
    }
    while(t2->right!=NULL && t2->left!=NULL)
    {
        printf("child of data %d :\nLeft : %d  Right : %d\n",t2->data,t2->left->data,t2->right->data);
        t2=t2->right;
    }
}
int main()
{
    root=create();
    display();
}