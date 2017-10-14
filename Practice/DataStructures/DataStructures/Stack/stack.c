#include "stack.h"


struct stack *create_stack(int size)
{ 
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    if(s == NULL)
    {
        fprintf(stderr, "ERROR: Not Enough Memory.\n");
        exit(-1);
    }
    s->data = (int *)malloc(sizeof(int) * size);
    if(s->data == NULL)
    {
        fprintf(stderr, "ERROR: Not Enough Memory.\n");
        exit(-1);
    }
    printf("All the data was allocated\n");
    s->top = s->data[0] = 0;
    s->size = size;
    printf("Stack Created with %d items.\n", size);
    return s;
}

bool isempty(struct stack *s)
{
    
    if(s == NULL)
    {
        fprintf(stderr, "Error: isempty checked on NULL stack.\n");
        return true; //Technically it is empty if it doesn't exist...
    }
    printf("Stack is not null\n");
    if(s->top == 0)
    {
        printf("Stack Is Empty\n");
        return true;
    }
    else
    {
        printf("Stack is not empty!\n");
        return false;
    }
}

void push(struct stack *s, int val)
{
    if(s == NULL)
    {
        fprintf(stderr, "Error: push called on a null stack!\n");
        return;
    }
    if(s->top == s->size)
    {
        fprintf(stderr, "Error: Stack full! Stack overflow will occur if item pushed.\n");
        return;
    }
    s->data[(++s->top)] = val;
    printf("Push: %d was pushed onto the stack. The Top is now %d.\n", val, s->top);
}


int pop(struct stack *s)
{
    if(s == NULL)
    {
        fprintf(stderr, "ERROR: Null stack passed\n");
        return -1;
    }
    if(s->top == 0)
    {
        fprintf(stderr, "ERROR: Stack is empty. Stack Underflow error would occur if popped.\n");
        return -1;
    }

    int temp = s->data[s->top];
    s->data[s->top] = -1;
    s->top -= 1;
    return temp;
}


void clean_stack(struct stack *s)
{
    if(s == NULL)
    {
        fprintf(stderr, "ERROR: Can not clean something that does not exist.\n");
        return;
    }
    free(s->data);
    free(s);
    printf("All data used for stack has been cleaned.\n");
}


