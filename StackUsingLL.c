//Here we rotate clockwise to put it in the container.

#include <stdlib.h>
#include <stdio.h>


struct Node {
    int data;
    struct Node * next;
};

struct Node * head = NULL;

void linkedListTrav(struct Node * ptr) {
    while (ptr != NULL){
        printf("%d\n", ptr ->data);
        ptr = ptr ->next;
    }
}

int isEmpty (struct Node * head) {
    if (head == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull (struct Node * head) {
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL){
        return 1;
    }
    else {
        return 0;
    }
}


//Push operation : Since we are rotating clockwise, we will push and pop from the head side of the linked list.

struct Node * push (struct Node * hed, int value) {
    if(isFull(hed)) {
        printf("stack overflow!\n");
    }
    else {
        struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr ->data = value;

        ptr ->next = hed;
        hed = ptr;
        return hed;
    }
}

int pop (struct Node * hed) {
    if (isEmpty (hed)) {
        printf("Stack underflow \n");
    }
    else {
        struct Node * ptr = hed;
        int value = ptr->data;
        head = hed ->next;
        free(ptr);
        return value;
    }
}


int main()
{
    head = push(head, 6);
    head = push(head, 7);
    head = push(head, 8);

    linkedListTrav(head);

    int element = pop(head);
    printf("popped element is %d\n", element);

    linkedListTrav(head);
    
    return 0;
}
