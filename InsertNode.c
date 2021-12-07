#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedListTrav(struct Node *ptr){
    while (ptr != NULL){
        printf("%d\n", ptr ->data);
        ptr = ptr ->next;
    }
};

//Now we have to write a function which will return a struct Node basically so

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr ->data = data;
    ptr ->next = head;

    return ptr;
}

struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr ->data = data;


    struct Node * q = head;
    int i = 0;
    while (i != index -1)
    {
        q = q->next;
        i++;
    }

    ptr ->next = q->next;
    q->next = ptr;

    return head;
    
}

struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr ->data = data;

    struct Node * p = head;
    while (p ->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;

    return head;
    
}

struct Node * insertAfterNode(struct Node *head, int data, struct Node *prevNode){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr ->data = data;

    ptr ->next = prevNode ->next;
    prevNode ->next = ptr;

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    
    head ->data = 7;
    head ->next = second;

    second ->data = 11;
    second ->next = third;

    third ->data = 24;
    third ->next = fourth;

    fourth ->data = 711;
    fourth ->next = NULL;


    // head = insertAtFirst(head, 1);
    // linkedListTrav(head);

    // head = insertAtEnd(head, 99);
    // linkedListTrav(head);

    // head = insertAtIndex(head, 69, 2);
    // linkedListTrav(head);

    // head = insertAfterNode(head, 68, second);
    // linkedListTrav(head);

    






    return 0;
}
