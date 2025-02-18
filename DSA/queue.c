#include <stdio.h>
#include <stdlib.h>

// We implemented Stack using Nodes this time we will use an array to make a queue;
// Which is better array or nodes? I'd say it depends.
// If you know a fixed amount of data you will be storing,
// go for arrays becaues node needs extra memory to store next node etc;
// Using nodes provides flexibility and isnt restricted to a certain range.

// For Learning purposes I will implement a queue using an array

// Here we are defining that we will have a type now which is bool (custom);
// C doesnt have a bool type;
typedef int bool;
#define MAX_SIZE 10

// When we say bool valid = true it will mean valid = 1 and valid = 0 if false;
#define true 1
#define false 0

// Creating Queue Structure

struct Queue
{
    int array[MAX_SIZE];

    //  We need them both because it follows a first in first out principal;
    // for enqueue we add in the head
    // for dequeue we remove from the tail
    int head;
    int tail;
};

// Queue Functionality

void initializeQueue(struct Queue *queue)
{
    queue->head = -1;
    queue->tail = 0;
}

bool isFull(struct Queue *queue)
{
    return queue->head == MAX_SIZE ? true : false;
};

bool isEmpty(struct Queue *queue)
{
    return queue->head < queue->tail;
};

void enqueue(struct Queue *queue, int value)
{
    if (isEmpty(queue))
    { // Meaning the queue is empty;

        queue->head = 0;
        queue->array[0] = value;
        return;
    }
    // check if is full;
    if (isFull(queue))
    {
        printf("\n Stack Overflow.");
        return;
    };
    queue->array[queue->head + 1] = value;
    queue->head++;
};

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return -1;

    return queue->array[(queue->tail)++];
};

int peek(struct Queue *queue)
{
    if (queue == NULL)
    {
        printf("Invalid Queue");
        return -1;
    }
    return queue->array[queue->head];
};

int main()
{
    struct Queue *queue = malloc(sizeof(struct Queue));
    initializeQueue(queue);
    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 15);
    enqueue(queue, 20);
    printf("Queue head should equal to 3 with value 20\n");
    printf("Head Index: %i\n", queue->head);
    printf("Head Value: %i\n", queue->array[queue->head]);
    printf("PEEK: %i\n", peek(queue));
    printf("DEQUEUE: EXPECTS 5 GOT %i\n", dequeue(queue));
    printf("DEQUEUE: EXPECTS 10 GOT %i\n", dequeue(queue));
    printf("DEQUEUE: EXPECTS 15 GOT %i\n", dequeue(queue));
    printf("DEQUEUE: EXPECTS 20 GOT %i\n", dequeue(queue));
    printf("DEQUEUE: EXPECTS -1 (EMPTY QUEUE) GOT %i\n", dequeue(queue));
    return 0;
}
