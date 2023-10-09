#include <stdio.h>

// Define a structure named 'code' with two members: an integer 'i' and a character 'c',
// along with a pointer to the same structure type 'ptr'.
struct code
{
    int i;
    char c;
    struct code *ptr;
};

int main()
{
    // Declare two variables of type 'struct code'.
    struct code var1;
    struct code var2;

    // Initialize the members of 'var1'.
    var1.i = 65;
    var1.c = 'A';
    var1.ptr = NULL;

    // Initialize the members of 'var2'.
    var2.i = 66;
    var2.c = 'B';
    var2.ptr = NULL;

    // Set the 'ptr' member of 'var1' to point to 'var2', creating a link between the two variables.
    var1.ptr = &var2;

    // Print the values of 'i' and 'c' for 'var1'.
    printf("%d %c\n", var1.i, var1.c);

    // Print the values of 'i' and 'c' for the variable pointed to by 'var1.ptr',
    // which is 'var2' in this case, using '->' notation.
    printf("%d %c\n", var1.ptr->i, var1.ptr->c);

    return 0;
}
