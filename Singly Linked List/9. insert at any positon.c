#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link; //pointer of type node
};

void add_at_pos(struct node **head, int data, int pos)
{
    struct node *ptr = *head;  //to traverse through the list
    struct node *ptr2 = (struct node *)malloc(sizeof(struct node)); //allocating memory for new node
    ptr2->data = data; //put the new node data into ptr2
    ptr2->link = NULL; //no need to link it now

    if (pos == 1) //if the postion is one(insert at the begining)
    {
        ptr2->link = ptr; //new node linked to the head (ptr contains head)
        *head = ptr2; //now new node at beginnign will be considered as new head
    }
    else        //if the position is not one.
    {
        while (pos != 2)
        {
            ptr = ptr->link; //ptr starts traversing from head
            pos--; //if 2, then will go 2, if 3 then will go 3
        }
        ptr2->link = ptr->link; //ptr2 holds new node and ptr holds the current node after completing loop, so new node link will take the next node of current node
        ptr->link = ptr2; //current node link will hold the new node
    }
}

int main()
{
    int data, pos; //inputing data and the position
    printf("Enter the data & pos= ");
    scanf("%d %d", &data, &pos);

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *second = (struct node *)malloc(sizeof(struct node));
    second->data = 98;
    second->link = NULL;

    struct node *third = (struct node *)malloc(sizeof(struct node));
    third->data = 45;
    third->link = NULL;

    head->link = second;
    second->link = third;
    third->link = NULL;

    printf("Before inserting node at a certain point\n");
    printf("%d->%d->%d->NULL", head->data, second->data, third->data);

    printf("\n\n");

    add_at_pos(&head, data, pos); //address of the head , the new node data, position of the node

    printf("After inserting in any position\n");

    while (head != NULL) //traversing through the nodes
    {
        printf("%d->", head->data);
        head = head->link;
    }
    printf("NULL\n");

    return 0;
}
