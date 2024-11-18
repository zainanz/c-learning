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

void enqueue(struct Queue *queue, int value) {

};

void dequeue() {
};

bool isFull() {
};

bool isEmpty() {

};

int peek() {

};

int main()
{
    struct Queue *queue = malloc(sizeof(struct Queue));
    return 0;
}
