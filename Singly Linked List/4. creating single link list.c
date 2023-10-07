#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
    };
int main()
{
    struct node *head= (struct node*)malloc(sizeof (struct node));
    head->data=45;
    head->link=NULL;
    struct node *node1= (struct node*)malloc(sizeof (struct node));
    node1->data=98;
    node1->link=NULL;
    struct node *node2= (struct node*)malloc(sizeof (struct node));
    node2->data=45;
    node2->link=NULL;

    head->link=node1;
    node1->link=node2;


    printf("%d %d %d \t",head->data,node1->data,node2->data);

}
