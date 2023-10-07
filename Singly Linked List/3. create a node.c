//Create a note and print it;
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};      //created a node ;
int main()
{
    //take the first node name head and assign null to it;
    struct node *head= NULL;

    //taking memory for struct node and allocating it to head pointer;
    head=(struct node*)malloc(sizeof (struct node));

    head->data=90;      //intialize data;
    head->link=NULL;

    printf("%d",head->data);//print it;

    free(head);//free the node;
    return 0;

}
