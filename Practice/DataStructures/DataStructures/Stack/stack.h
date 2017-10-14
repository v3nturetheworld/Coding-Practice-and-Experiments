//Stack.h
//An implementation of a fixed sized stack data structure
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct stack 
{
    int *data;
    int size, top;
};

struct stack *create_stack(int size);
bool isempty(struct stack *s);
void push(struct stack *s, int val);
int pop(struct stack *s);
void clean_stack(struct stack *s);
