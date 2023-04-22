#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void createStack(Stack *stack, unsigned int size)
{
    stack->top = -1;
    stack->size = size;
    stack->data = (float *)calloc(stack->size, sizeof(float));
}
int isFull(Stack *stack)
{
    if (stack->top == stack->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(Stack *stack)
{
    if (stack->top == -1)
        return 1;
    else
        return 0;
}
void push(Stack *stack, float info)
{
    stack->top++;
    stack->data[stack->top] = info;
}
float pop(Stack *stack)
{
    float auxy;

    auxy = stack->data[stack->top];
    stack->data[stack->top] = 0;
    stack->top--;
    return auxy;
}
int stackSize(Stack *stack)
{
    printf("\nO tamanho da pilha eh: %d", stack->size);
}
int stackSearch(Stack *stack, float imput)
{
    int contOcorrence = 0;
    for (int i = 0; i < stack->size; i++)
    {
        if (imput == stack->data[i])
        {
            contOcorrence += 1;
        }
    }
    return contOcorrence;
}
void printStack(Stack *stack)
{
    puts("\t TOP");
    for (int i = stack->size - 1; i >= 0; i--)
    {
        if (stack->data[i] > 0.0)
        {
            printf("\t[%0.1f]\n", stack->data[i]);
        }
    }
    puts("\tBOTTON");
}