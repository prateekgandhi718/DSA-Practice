#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node * next;
};

void linkedListTrav(struct Node *ptr){
    while (ptr != NULL){
        printf("%d\n", ptr ->data);
        ptr = ptr ->next;
    }
};

struct Node * deleteFirst (struct Node * head){
    struct Node * ptr = head;
    head = head ->next;
    free(ptr);

    return head;
}

struct Node * deleteAtIndex (struct Node * head, int index)
{
    struct Node *p = head;
    struct Node *q = head ->next;
    int i = 0;
    while (i!=index-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    p ->next = q->next;
    free(q);
    return head;
    
};

struct Node * deleteLast(struct Node * head){
    struct Node *p = head;
    struct Node *q = head ->next;

    while (q ->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p ->next = NULL;
    free(q);

    return head;
}

struct Node * deleteValue(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head ->next;

    while (q->data != value && q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q ->data == value)
    {
        p ->next = q->next;
        free(q);
    }

    return(head);
    
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


    
    return 0;
}
