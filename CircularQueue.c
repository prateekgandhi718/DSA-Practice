#include <stdlib.h>
#include <stdio.h>

struct queue {
    int size;
    int frontend;
    int backend;
    int * arr;
};

int isEmpty (struct queue * q){
    if (q->frontend == q->backend) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull (struct queue * q) {
    if ((q->backend + 1) % q->size == q->frontend) {
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue (struct queue * q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
    }
    else {
        q->backend = (q->backend + 1) % q->size;
        q->arr[q->backend] = value;
    }
}

int dequeue (struct queue * q) {
    if (isEmpty(q)) {
        printf("the queue is empty!\n");
        return -1;
    }
    else {
        //have to remove from the frontside.
        q->frontend = (q->frontend+1)%(q->size);
        int value = q->arr[q->frontend];
        return value;
    }
}

int main()
{
    struct queue * qu = (struct queue *)malloc(sizeof(struct queue));
    qu->size = 4;
    qu->frontend = -1;
    qu->backend = -1;
    qu->arr = (int *)malloc(qu->size * sizeof(int));

    enqueue(qu, 67);
    enqueue(qu, 68);
    enqueue(qu, 69);
    enqueue(qu, 70);

    printf("popped element is %d\n", dequeue(qu));
    printf("popped element is %d\n", dequeue(qu));
    printf("popped element is %d\n", dequeue(qu));
    printf("popped element is %d\n", dequeue(qu));
    
    enqueue(qu, 70);
    enqueue(qu, 70);
    enqueue(qu, 70);


    if(isEmpty(qu)) {
        printf("empty!");
    }
    if(isFull(qu)) {
        printf("full");
    }
    return 0;
}
