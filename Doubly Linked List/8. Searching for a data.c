#include<stdio.h>
#include<stdlib.h>

// Define a structure named 'node' with an integer 'data' and two pointers of the same structure type: 'prev' and 'next'.
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

// Function to search for a specific value in the doubly linked list and print its position(s).
void search_value(struct node *head, int data)
{
    struct node *temp = head; // Create a temporary pointer 'temp' and initialize it with 'head'.
    int position = 1; // Initialize a variable 'position' to keep track of the position of the value.

    // Traverse the doubly linked list forward.
    while (temp != NULL)
    {
        // If the 'data' of the current node matches the target 'data', print its position.
        if (temp->data == data)
        {
            printf("%d is found in pos %d\n", data, position);
        }

        temp = temp->next; // Move 'temp' to the next node in the doubly linked list.
        position++; // Increment the position.
    }
}

int main()
{
    // Create three nodes ('head', 'head2', and 'head3') and initialize their 'data', 'prev', and 'next' members.
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 45;
    head->prev = NULL;
    head->next = NULL;

    struct node *head2 = (struct node*)malloc(sizeof(struct node));
    head2->data = 98;
    head2->prev = NULL;
    head2->next = NULL;

    struct node *head3 = (struct node*)malloc(sizeof(struct node));
    head3->data = 45;
    head3->prev = NULL;
    head3->next = NULL;

    // Connect the nodes to create a doubly linked list.
    head->next = head2;
    head2->prev = head;
    head2->next = head3;
    head3->prev = head2;
    head3->next = NULL;

    printf("Before inserting node at the beginning\n");
    printf("%d<->%d<->%d<->NULL\n\n", head->data, head2->data, head3->data);

    printf("\n");
    int data;
    printf("Enter the data to search= ");
    scanf("%d", &data); // Input the data to search for.
    search_value(head, data); // Call the 'search_value' function to search for the data.

    return 0;
}
