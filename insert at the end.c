#include<stdio.h>
#include<stdlib.h>
struct node //creating a node
{
    int data; //node's data
    struct node *link; //declaring a "struct node type" pointer that will point to the next node
};
void add_at_end(struct node **head,int data)
{
    struct node *ptr=*head; //ptr pointer is for storing the head pointer
    struct node *ptr2= (struct node*)malloc(sizeof(struct node)); //ptr2 pointer is for storing the new node
    ptr2->data=data;
    ptr2->link=NULL;
    while(ptr->link!=NULL) //start from ptr(which holds head), keep traversing the nodes untill null
    {
        ptr=ptr->link;
    }
    ptr->link=ptr2; //latest node in ptr was the last node, store the link of ptr2(new node) with the last node

}
int main()
{
    int data;
    printf("Enter the data= ");
    scanf("%d",&data); //inputting new node data

    struct node *head=(struct node*)malloc(sizeof(struct node)); //allocating memory for the "pointer of node" because the pointer needs an address
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

    add_at_end(&head,data);
    printf("After inserting at end\n");
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->link;
    }
    printf("NULL");
}
