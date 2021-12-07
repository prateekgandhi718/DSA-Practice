#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedListTrav(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}




int main()
{
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *)malloc(sizeof(struct Node));

    head ->data = 4;
    head ->next = second;
    second ->data = 5;
    second ->next = third;
    third ->data = 6;
    third ->next = fourth;
    fourth ->data = 7;
    fourth ->next = NULL;

    linkedListTrav(head);

    struct Node * prevNode;
    struct Node * currentNode;
    struct Node * nextNode;

    prevNode = NULL;
    currentNode = head;
    nextNode = head;

    while(nextNode != NULL){
        nextNode = nextNode->next; //move
        currentNode ->next = prevNode; //reverse the link
        prevNode = currentNode; //move
        currentNode = nextNode; //move
    }

    head = prevNode; //making the last node as the head;

    linkedListTrav(head);




    return 0;
}
