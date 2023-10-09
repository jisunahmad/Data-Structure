#include<stdio.h>
#include<stdlib.h>

// Define a structure named 'node' with an integer 'data' and a pointer to the same structure type 'link'.
struct node
{
    int data;
    struct node *link;
};

int main()
{
    // Declare a pointer to a 'struct node' named 'head' and initialize it to NULL.
    struct node *head = NULL;

    // Allocate memory for a 'struct node' and assign its address to the 'head' pointer.
    head = (struct node*)malloc(sizeof(struct node));

    // Set the 'data' member of the 'head' node to 90.
    head->data = 90;

    // Set the 'link' member of the 'head' node to NULL.
    head->link = NULL;

    // Print the 'data' member of the 'head' node.
    printf("%d", head->data);

    // Free the memory allocated for the 'head' node.
    free(head);

    return 0;
}
