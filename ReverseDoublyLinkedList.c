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

    struct Node * prevNode = NULL;
    struct Node * currentNode = head;
    struct Node * nextNode = head;

    while (nextNode != NULL)
    {
        nextNode = nextNode ->next;
        currentNode ->next = prevNode;
        currentNode ->prev = nextNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;

    doublyLinkedListTrav(head);
    

    return 0;
}
