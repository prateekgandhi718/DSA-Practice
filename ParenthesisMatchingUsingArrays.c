#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    char * arr;
};

//Functions to be made: isEmpty, isFull, push, pop, parenthesisMatch

int isEmpty (struct stack * s) {
    if (s ->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull (struct stack * s) {
    if (s->top == s->size-1) {
        return 1;
    }
    else {
        return 0;
    }
}

void push (struct stack * s, char value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
    }
    else {
        s->top++;
        s->arr[s->top] = value;
    }
}

char pop (struct stack * s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    else {
        char value = s->arr[s->top];
        s->top--;
        return value;
    }
}

int parenthesisMatch (char * exp) {
    struct stack * st = (struct stack *)malloc(sizeof(struct stack));
    st->size = 100;
    st->top = -1;
    st->arr = (char *)malloc(st->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(') {
            push(st, '(');
        }
        else if (exp[i] == ')') {
            if (isEmpty(st)) {
                return 0;
            }
            pop(st);
        }
    }

    //finally
    if (isEmpty(st)) {
        return 1;
    }
    else {
        return 0;
    }
    
}

int main()
{
    char * exp = "((1)(*asasasafaf))";
    if (parenthesisMatch(exp)) {
        printf("YES!\n");
    }
    else {
        printf("NO!\n");
    }
    
    return 0;
}
