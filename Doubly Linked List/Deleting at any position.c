#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev; // Pointer to the previous node
    struct node *next; // Pointer to the next node
};

// Function to delete a node at a specified position in the doubly linked list
void del_at_pos(struct node **head, int pos)
{
    struct node *temp = *head;
    struct node *temp2 = *head;

    if (pos == 1) // If the position is 1 (delete the first node)
    {
        *head = (*head)->next; // Update the head to the next node
        if (*head != NULL)
        {
            (*head)->prev = NULL; // Update the previous pointer of the new head to NULL
        }
        free(temp); // Free the memory of the deleted node
    }
    else
    {
        while (pos != 1) // Traverse to the node just before the desired position
        {
            temp = temp2;
            temp2 = temp2->next;
            pos--;
        }
        temp->next = temp2->next; // Update the next pointer of the previous node
        if (temp2->next != NULL)
        {
            temp2->next->prev = temp; // Update the previous pointer of the next node
        }
        free(temp2); // Free the memory of the deleted node
    }
}

int main()
{
    int pos;
    printf("Enter the pos= ");
    scanf("%d", &pos);

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->prev = NULL;
    head->next = NULL;

    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    head2->data = 98;
    head2->prev = NULL;
    head2->next = NULL;

    struct node *head3 = (struct node *)malloc(sizeof(struct node));
    head3->data = 3;
    head3->prev = NULL;
    head3->next = NULL;

    head->next = head2;
    head2->prev = head;
    head2->next = head3;
    head3->prev = head2;
    head3->next = NULL;

    printf("Before Deleting node at a certain point\n");
    printf("%d<->%d<->%d<->NULL\n\n", head->data, head2->data, head3->data);

    del_at_pos(&head, pos);

    printf("After deleting in any position\n");
    while (head != NULL)
    {
        printf("%d<->", head->data);
        head = head->next;
    }
    printf("NULL");

    return 0;
}
