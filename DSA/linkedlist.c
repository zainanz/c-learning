#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct Node *createNode(int value)
{
    // The struct node* before is cast type. In c it isnt really needed
    // malloc by default returns void* but in C++ it doesnt.
    // this ensures compatibility with C++;
    struct Node *node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

struct Node *insertAtFirst(struct Node **head, int value)
{
    printf("%p\n", &((*head)->next));
    struct Node *new_node = createNode(value);
    new_node->next = *head;
    *head = new_node;
    return new_node;
}

struct Node *insertAtEnd(struct Node **head, int value)
{
    struct Node *current_node = *head;
    while (current_node->next)
    {
        current_node = current_node->next;
    }
    struct Node *last_node = createNode(value);
    current_node->next = last_node;
    return last_node;
}

struct Node *findNode(struct Node **head, int value)
{
    struct Node *cur = *head;
    while (cur)
    {
        if (cur->data == value)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
void deleteNode(struct Node **head, int value)
{
    struct Node *cur = *head;
    struct Node *prev = NULL;
    while (cur)
    {
        if (cur->data == value)
        {
            if (prev)
            {
                prev->next = cur->next;
            }
            else
            {
                *head = cur->next;
            }
            free(cur);
            break;
        }
        prev = cur;
        cur = cur->next;
    }
}

void traverse(struct Node **head)
{
    struct Node *current = *head;
    while (current->next)
    {
        printf(" %d ->", current->data);
        current = current->next;
    }
    printf(" %d\n\n", current->data);
}
int main()
{
    // NOTE:
    /*
    We passed "&head" always as a argument..
    we recieve it as: struct Node **head
    we assign it to temp node like: struct Node* tempNode = *head; (*head means what the head points to which is another pointer which has the value of a struct node);
    we are sending memory location of the header which has the value of a pointer > basically
    head is a pointer which points to a pointer which has the node struct;

    We could also just pass "head" as the argument and it would be recieved as
    struct Node *head because we are simply stating its a pointer that points to a value (in our case struct node);
    we assign it to temp node like: struct Node *tcur = thead;

    */

    // test create node
    struct Node *first_node = createNode(5);
    printf("Testing Create Node\n");

    printf("First Node Location: %p\n", first_node);
    printf("First Node's Value: %i\n", first_node->data);

    struct Node *head = first_node;
    printf("Head's Memory Location: %p\n", &head);
    printf("Head's Stored Memory Location: %p\n", head);
    printf("---------------------------\n\n");

    // test insert at first

    printf("Insert At First: \nInserting 10..\n");
    // returns 10 as head and 5 as the next of the head;
    struct Node *new_head = insertAtFirst(&head, 10);
    printf("First Node's Memory Address:%p", new_head);

    printf("\nTraversing: \n\n(START)\n %i -> %i\n(END) \n\n", head->data, head->next->data);
    printf("---------------------------\n\n");

    // test insert at the end;
    printf("Insert At the End\nInserting 15..\n");
    struct Node *last_node = insertAtEnd(&head, 15);
    printf("Last Node's Memory Address:%p", last_node);
    printf("\nTraversing: \n\n(START)\n%i -> %i -> %i\n(END)\n\n", head->data, head->next->data, head->next->next->data);
    printf("---------------------------\n\n");

    // TRAVERSE
    printf("Traversing the linked list\n");
    traverse(&head);
    printf("---------------------------\n\n");

    printf("Deleting\nDeleting node with value 10\n");
    deleteNode(&head, 10);
    traverse(&head);
    printf("---------------------------\n\n");

    printf("FindNode\n Finding node with value 5\n");
    struct Node *node_found = findNode(&head, 5);
    printf("Found node's memory location: %p\n", node_found);
    printf("Value: %i\n", node_found->data);
    printf("Next: %p\n\n", node_found->next);
    traverse(&head);
    printf("---------------------------\n\n");

    return 1;
}

void testFunction()
{
    struct Node *one;
    struct Node *two;
    one = malloc(sizeof(struct Node));
    two = malloc(sizeof(struct Node));
    struct Node *three;
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
}