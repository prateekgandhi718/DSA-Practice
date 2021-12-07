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


//DELETE FROM THE BEGINNING
struct Node * deleteFromBeginning (struct Node * head){
    struct Node * q = head;
    head = head ->next;
    free(q);
    return head;
}

//DELETE AT INDEX
struct Node * deleteAtIndex (struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = head ->next;
    int i = 0;
    while(i != index-1){
        p = p->next;
        q = q->next;
        i++;
    }
    //now p is 1 position behind node which needs to be deleted.  q is on top of it
    struct Node * ptr = q->next;
    p ->next = ptr;
    ptr->prev = p;

    free(q);

    return head;
}

//DELETE AT LAST
struct Node * deleteFromLast (struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}

//DELETE A PARTICULAR VALUE
struct Node * deleteAValue (struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = head ->next;
    while(q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    struct Node * ptr = q->next;
    p->next = ptr;
    ptr->prev = p;
    free(q);

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

    // head = deleteFromBeginning(head);
    // head = deleteAtIndex(head, 1);
    // head = deleteFromLast(head);
    head = deleteAValue(head, 8);

    doublyLinkedListTrav(head);

    return 0;
}
