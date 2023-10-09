#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, n;

    // Prompt the user to enter the number of integers.
    printf("Enter the number of integers: ");
    scanf("%d", &n); // Read the input for the number of integers.

    // Allocate memory dynamically for an array of integers based on the user's input.
    int *ptr = (int*)malloc(n * sizeof(int));

    // Check if memory allocation was successful.
    if(ptr == NULL)
    {
        // If memory allocation failed, print an error message and exit the program.
        printf("No memory available for allocation.\n");
        exit(1);
    }

    // Loop to input integer values from the user.
    for(i = 0; i < n; i++)
    {
        printf("Enter an integer: ");
        scanf("%d", ptr + i); // Read and store the integer value in the dynamically allocated array.
    }

    // Loop to print the entered integer values.
    for(i = 0; i < n; i++)
    {
        printf("%d\t", *(ptr + i)); // Print the integer values from the dynamically allocated array.
    }

    // Free the dynamically allocated memory.
    free(ptr);

    return 0;
}
