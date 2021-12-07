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
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue (int value) {
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Queue is full");
    }
    else {
        newNode->data = value;
        newNode->next = NULL;
        if(frontend == NULL){
            //means this is the first node which is coming.
            frontend = newNode;
            backend = newNode;
        }
        else{
            backend->next = newNode;
            backend = newNode;
        }
    }
}

int dequeue () {
    //delete from the frontend
    struct Node * ptr = frontend;
    if(frontend == NULL){
        printf("Queue is empty\n");
    }
    else {
        frontend = frontend->next;
        int value = ptr->data;
        free(ptr);
        return value;
    }
}

int main()
{
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);

    LinkedListTraversal(frontend);

    printf("popped element is %d\n", dequeue());
    printf("popped element is %d\n", dequeue());

    
    LinkedListTraversal(frontend);


    return 0;
}
