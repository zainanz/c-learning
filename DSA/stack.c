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

struct Node *pop(struct Node **head)
{
    struct Node *node_to_remove = *head;
    *head = (*head)->next;
    free(node_to_remove);
    return node_to_remove;
}

void traverse(struct Node **head)
{
    struct Node *cur = *head;
    if (cur == NULL)
    {
        printf("\n\nTraverse: Empty Stack.\n");
        return;
    }
    printf("\nHEAD | ");
    while (cur->next)
    {
        printf(" %i ->", cur->data);
        cur = cur->next;
    }
    printf(" %i | TAIL\n", cur->data);
}

int contains(struct Node **head, int value)
{
    int counter = 0;
    struct Node *cur = *head;
    while (cur)
    {
        if (cur->data == value)
            return counter;
        cur = cur->next;
        counter++;
    }
    return -1;
}
int main()
{
    struct Node *head = NULL;
    push(&head, 5);
    push(&head, 2);
    push(&head, 3);
    push(&head, 10);
    int where = contains(&head, 5);
    printf("\n\n5 is %i numbers away.", where);
    traverse(&head);
    pop(&head);

    where = contains(&head, 5);
    printf("\n\n5 is %i numbers away.", where);
    traverse(&head);

    pop(&head);

    where = contains(&head, 5);
    printf("\n\n5 is %i numbers away.", where);
    traverse(&head);

    pop(&head);

    where = contains(&head, 5);
    printf("\n\n5 is %i numbers away.", where);
    traverse(&head);

    pop(&head);
    traverse(&head);
    return 0;
}
