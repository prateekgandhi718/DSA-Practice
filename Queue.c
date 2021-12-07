/*
In stacks we used to maintain only 1 end which was head, since deletion and insertion happened from the head side only. But in queue insertion and deletion happens at different ends therefore we will have to maintain two ends here. 

Implementing Queues using Arrays data structure. 

Don't rotate the array here, keep it horizontal!

*/

#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int frontend;
    int backend;
    int * arr;
};

int isEmpty (struct queue * q) {
    if (q ->frontend == q ->backend) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull (struct queue * q) {
    if (q->backend == q->size-1) {
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue (struct queue * q, int value) {
    if (isFull(q)) {
        printf("This queue is full \n");
    }
    else {
        q->backend++;
        q->arr[q->backend] = value;
    }
}

int dequeue (struct queue * q) {
    if (isEmpty(q)) {
        printf("Queue is Empty! \n");
    }
    else {
        q->frontend++;
        int value = q->arr[q->frontend];
        return value;
    }
}

void printQueue (struct queue * q) {
    for (int i = 0; i < q->backend + 1; i++)
    {
        printf("%d\n", q->arr[i]);
    }
    
}

int main()
{
    struct queue * qu = (struct queue *)malloc(sizeof(struct queue));
    qu->size = 100;
    qu->frontend = -1;
    qu->backend = -1;
    qu->arr = (int *)malloc(qu->size * sizeof(int));

    enqueue(qu, 66);
    enqueue(qu, 67);
    enqueue(qu, 68);
    enqueue(qu, 69);

    printQueue(qu);

    int element = dequeue(qu);
    printf("popped is %d\n", element);

    printQueue(qu);
    return 0;
}
