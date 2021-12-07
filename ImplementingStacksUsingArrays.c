//How would you implement a stack using an array data structure?
//For arrays we put the array anticlockwise in the container and use it as a stack.
//Implement isEmpty, isFull, push and pop operation in a stack using arrays.


#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack *ptr){
    if (ptr->top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if (ptr ->top == ptr ->size -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push (struct stack * ptr, int value){
    if (isFull){
        printf("Stack overflow! Cannot push.");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop (struct stack * ptr) {
    if (isEmpty){
        printf("Stack underflow. Cannot pop. \n");
        return -1;
    }
    else {
        int value = ptr ->arr[ptr->top];
        ptr ->top--;
        return value;
    }
}

//If you want to peek at i. i is from the top.
int peek (struct stack * ptr, int i) {
    int arrayIndex = ptr ->top -i + 1;
    if (arrayIndex < 0) {
        printf("Not valid");
        return -1;
    }
    else {
        return ptr ->arr[arrayIndex];
    }
}


int main()
{
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc((s->size) * sizeof(int));

    //do operation like push pop.
    return 0;
}
