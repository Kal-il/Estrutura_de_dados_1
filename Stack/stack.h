#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    float *data;
    unsigned int size;
};

typedef struct stack Stack;

void createStack(Stack *, unsigned int size);
int isFull(Stack *);
int isEmpty(Stack *);
void push(Stack *, float);
float pop(Stack *);
int stackSize(Stack *);
int stackSearch(Stack *, float);
void printStack(Stack *);

#endif