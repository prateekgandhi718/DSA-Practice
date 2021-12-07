#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
};


void doublyLinkedListTrav(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

//INSERT AT THE BEGINNING
struct Node * insertAtBeginning(struct Node * head, int value){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr ->data = value;

    ptr ->next = head;
    head ->prev = ptr;
    ptr ->prev = NULL;

    head = ptr;
    return head;
}

//INSERT AT A PARTICULAR INDEX
struct Node * insertAtIndex(struct Node * head, int value, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr ->data = value;

    struct Node * q = head;
    int i = 0;
    while(i != index-1){
        q = q->next;
        i++;
    }
    //now q is at 1 position behind where we want ptr to be inserted.
    ptr ->next = q ->next;
    q ->next = ptr;
    ptr ->prev = q;

    return head;
}

//INSERT AT END
struct Node * insertAtEnd(struct Node * head, int value){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr ->data = value;

    struct Node *q = head;
    while(q ->next != NULL){
        q = q->next;
    }
    //Now q is at the last position where we want to insert ptr
    ptr ->next = q->next;
    q ->next = ptr;
    ptr ->prev = q;

    return head;
}

//INSERT AFTER A NODE
struct Node * insertAfterNode(struct Node * head, int value, struct Node * nodeAfterWhichWeWillInsert){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr ->data = value;

    ptr ->next = nodeAfterWhichWeWillInsert ->next;
    nodeAfterWhichWeWillInsert ->next = ptr;
    ptr ->prev = nodeAfterWhichWeWillInsert;

    return head;
}

int main()
{
    struct Node * head;  
    struct Node * second;  
    struct Node * third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head ->data = 7;
    head ->prev = NULL;
    head ->next = second;

    second ->data = 8;
    second ->prev = head;
    second ->next = third;

    third ->data = 9;
    third ->prev = second;
    third ->next = NULL;

    doublyLinkedListTrav(head);

    // head = insertAtIndex(head, 6, 1);
    // head = insertAtEnd(head,10);
    // head = insertAfterNode(head, 69, second);

    doublyLinkedListTrav(head);

    return 0;
}
