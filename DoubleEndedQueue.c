//Let's implement DE Queue using linked lists.

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node * next;
};

struct Node * frontend = NULL;
struct Node * backend = NULL;

void LinkedListTraversal (struct Node * ptr) {
    while (ptr != NULL) {
        printf("%d\n", ptr ->data);
        ptr = ptr->next;
    }
}

void enqueueRear (int value) {
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue is full!\n");
    }
    else {
        newNode ->data = value;
        newNode ->next = NULL;
        if (frontend == NULL) {
            //means first incoming node
            frontend = newNode;
            backend = newNode;
        }
        else {
            backend ->next = newNode;
            backend = newNode;
        }
    }
}

void enqueueFront (int value) {
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue is full!\n");
    }
    else {
        newNode ->data = value;
        newNode ->next = frontend;
        if (frontend == NULL) {
            //means first incoming node
            frontend = newNode;
            backend = newNode;
        }
        else {
            frontend = newNode;
        }
    }
}

int dequeueFront () {
    struct Node * ptr = frontend;
    if (frontend == NULL) {
        printf("Queue is empty! \n");
        return -1;
    }
    else {
        int value = ptr->data;
        frontend = frontend->next;
        free (ptr);
        return value;
    }
}

int dequeueRear () {
    struct Node * ptr = backend;
    if (frontend == NULL) {
        printf("Queue is empty! \n");
        return -1;
    }
    else {
        int value = ptr ->data;
        struct Node * backendMinusOne = frontend;
        while (backendMinusOne ->next != backend) {
            backendMinusOne = backendMinusOne->next;
        }
        backendMinusOne ->next = NULL;
        backend = backendMinusOne;
        free(ptr);
        return value;
    }
}

int main()
{
    enqueueRear(5);
    enqueueFront(6);
    enqueueFront(7);
    enqueueRear(4);

    LinkedListTraversal(frontend);

    printf("popped element is %d\n", dequeueRear());
    printf("popped element is %d\n", dequeueRear());
    LinkedListTraversal(frontend);

    return 0;
}
