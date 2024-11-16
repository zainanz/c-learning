#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *one;
    struct node *two;
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    struct node *three;
    printf("First Node's Memory Location: %p\n", one);
    printf("Second Node's Memory Location: %p\n", two);
    one->data = 5;
    two->data = 3;
    one->next = two;
    printf("First Node: %i\n", one->data);
    printf("Next Node: %i\n", one->next->data);
    if (!(two->next == NULL))
    {
        printf("Next Node: %i\n", two->next->data);
    }
    return 1;
}