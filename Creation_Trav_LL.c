#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTrav(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("%d\n", ptr ->data);
        ptr = ptr ->next;
    }
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //Allocate memory in the HEAP
    head = (struct Node *)malloc(1 * sizeof(struct Node)); //similar to arr = (int *)malloc(n*sizeof(int));
    second = (struct Node *)malloc(1 * sizeof(struct Node));
    third = (struct Node *)malloc(1 * sizeof(struct Node));
    fourth = (struct Node *)malloc(1 * sizeof(struct Node));

    head ->data = 7;
    head ->next = second;

    second ->data = 11;
    second ->next = third;

    third ->data = 24;
    third ->next = fourth;

    fourth ->data = 711;
    fourth ->next = NULL;

    linkedListTrav(head);


    return 0;
}
