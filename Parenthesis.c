#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct stack{
    int size;
    int top;
    char *arr;
};

int isFull(struct stack *ptr){
    if (ptr ->top == ptr ->size -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct stack *ptr){
    if (ptr ->top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

void push(struct stack *ptr, char val){
    if (isFull(ptr))
    {
        printf("stack overflow.");
    }
    else{
        ptr ->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr){
    if (isEmpty(ptr))
    {
        printf("stack underflow");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
    
}

int paranthesisMatch(char *exp){
    //create and initialize the stack here.
    struct stack *sp;
    sp ->size = 100;
    sp ->top = -1;
    sp ->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if(exp[i] == ')'){
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }

    //Finally,

    if (isEmpty(sp))
    {
        return 1;
    }
    else{
        return 0;
    }
    
    

}

int main()
{
    
    char *exp = "((8)(*--$$9))";
    if (paranthesisMatch(exp))
    {
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
