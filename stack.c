#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct Node *createNode(int value)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void push(struct Node **head, int value)
{
    struct Node *cur = *head;
    struct Node *node = createNode(value);
    if (cur != NULL)
        node->next = *head;
    *head = node;
}

void pop(struct Node *head)
{
}

int main()
{
    struct Node *head = NULL;
    push(&head, 5);
    printf("%i", head->data);
    return 0;
}
