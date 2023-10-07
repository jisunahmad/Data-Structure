#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void del_last(struct node **head)
{
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct node *temp = *head; //initializing temp pointer with head pointer
    struct node *temp2 = *head; //also initializing temp2 pointer with head pointer
    while(temp2->link!=NULL) // temp2 will traverse to the end
    {
        temp=temp2;         //first whatever is in temp2 will be in temp
        temp2=temp2->link;  //then temp2 will move to the next node
    }

        // temp2 will be always be one node ahead of temp
    temp->link=NULL;    //temp will be the previous node of the last node after the loop, so temp will be unlinked with temp2
    free(temp2);        // now free the temp2 (the last node)
    temp=NULL;
}
int main()
{
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

    printf("Before deleting last node\n");
    printf("%d->%d->%d->NULL\n\n", head->data, second->data, third->data);

    del_last(&head);
    printf("After deleting last node\n");
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->link;
    }
    printf("NULL");

    return 0;
}
