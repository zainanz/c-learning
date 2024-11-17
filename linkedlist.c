#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

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

    printf("Deleting\n deleting 10\n");
    deleteNode(&head, 10);
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