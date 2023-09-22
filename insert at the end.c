#include<stdio.h>
#include<stdlib.h>
struct node //creating a node
{
    int data; //node's data
    struct node *link; //declaring a "struct node type" pointer that will point to the next node
};
void add_at_end(struct node *head,int data)
{
    struct node *ptr=head;
    struct node *ptr2= (struct node*)malloc(sizeof(struct node));
    ptr2->data=data;
    ptr2->link=NULL;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=ptr2;

}
int main()
{
    int data;
    printf("Enter the data= ");
    scanf("%d",&data); //inputting new node data

    struct node *head=(struct node*)malloc(sizeof(struct node)); //allocating memory for the node
    head->data=45;
    head->link=NULL;

    struct node *second=(struct node*)malloc(sizeof(struct node));
    second->data=98;
    second->link=NULL;

    struct node *third=(struct node*)malloc(sizeof(struct node));
    third->data=45;
    third->link=NULL;

    head->link=second;
    second->link=third;
    third->link=NULL;

    printf("Before inserting node at a  end\n");
    printf("%d->%d->%d->NULL\n\n",head->data,second->data,third->data);

    add_at_end(head,data);
    printf("After inserting at end\n");
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->link;
    }
    printf("NULL");
}
