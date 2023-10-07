#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void add_at_beginning(struct node **head,int data)
{
    struct node *ptr=*head; //put current head in the pointer ptr
    struct node *ptr2= (struct node*)malloc(sizeof(struct node));
    ptr2->data=data; //input data from the new node input
    ptr2->link=ptr; //connect with the ptr (ptr is holding current head)
    *head=ptr2; //assign ptr2 as head, the previous head is in pointer ptr now

}
int main()
{
    int data;
    printf("Enter the data= ");
    scanf("%d",&data); //input the data for the new node

    struct node *head=(struct node*)malloc(sizeof(struct node));
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

    printf("Before inserting node at a  beginning\n");
    printf("%d->%d->%d->NULL\n\n",head->data,second->data,third->data);

    add_at_beginning(&head,data);
    printf("After inserting at beginnig\n");
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->link;
    }
    printf("NULL");
}
