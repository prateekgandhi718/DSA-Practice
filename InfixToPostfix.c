/*
Psuedo Code:
Moment we get an operand, we concatenate to postfix expression.

If we encounter an operator, move it to the stack along with its presendence number and check if the top most operator's presedence number is more or less. If it's less than push the incoming operator. If it's more then, keep poppiing operators untill the topmost operator becomes weaker in precedence relative to the incoming operator.

in the end just concatenate everything when you pop out of the stack


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char * arr;
};

int stackTop (struct stack * s) {
    return s->arr[s->top];
}

int isEmpty (struct stack * s) {
    if (s->top == -1) {
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
        printf("Stack overflow!\n");
    }
    else {
        s->top++;
        s->arr[s->top] = value;
    }
}

char pop (struct stack * s) {
    if(isEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    else {
        char value = s->arr[s->top];
        s->top--;
        return value;
    }
}

int precedence (char ch) {
    if (ch == '*' || ch == '/') {
        return 3;
    }
    else if (ch == '+' || ch == '-') {
        return 2;
    }
    else {
        return 0;
    }
}

int isOperator (char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return 1;
    }
    else {
        return 0;
    }
}

//Now our function will return a postfix expression therfore initiate it as char * name

char * infixToPostfix (char * infix) {
    struct stack * st = (struct stack *)malloc(sizeof(struct stack));
    st->size = 100;
    st->top = -1;
    st->arr = (char *)malloc(st->size * sizeof(char));

    char * postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; //for infix
    int j = 0; //for postfix

    while (infix[i] != '\0') {
        if (!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else {
            if (precedence(infix[i]) > precedence(stackTop(st))) {
                push(st, infix[i]);
                i++;
            }
            else {
                postfix[j] = pop(st);
                j++;
            }
        }
    }

    while (!isEmpty(st)) {
        postfix[j] = pop(st);
        j++;
    }

    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char * infix = "x-y/z-k*d";
    printf("%s", infixToPostfix(infix));
    return 0;
}
