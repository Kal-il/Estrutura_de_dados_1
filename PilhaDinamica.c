#include<stdio.h>
#include<stdlib.h>

typedef struct dataStack
{
    int id;
    float num;
}Data;
typedef struct no
{
    Data info;
    struct no *next;
}No;
typedef struct stack
{
    No *top;
}Stack;

No *createNo(Data);
Stack* stackCreate();
int isEmpty(Stack*);
void push(Stack*, Data);
No pop(Stack*);
void print(Stack*);

int main()
{
    Stack *stack;
    Data info;

    info.id = 1;
    info.num = 12.54;
    stack = stackCreate(stack);
    push(stack, info);
    print(stack);

}

No *createNo(Data info)
{
    No *newNode = (No*) calloc(1,sizeof(No));
    if(newNode!=NULL)
    {
        newNode->info = info;
        newNode->next = NULL;
        return newNode;
    }
}
Stack* stackCreate()
{
    Stack *stack = (Stack*) calloc(1,sizeof(Stack));
    if(stack!=NULL)
    {
        stack->top = NULL;
        return stack;
    }
}
void push(Stack* stack, Data info)
{
    No* node = createNo(info);
    if(!isEmpty(stack))
    {
        node->next = stack->top;
    }
    stack->top = node;
}
No pop(Stack* stack)
{
    if(!isEmpty(stack))
    {
        stack->top = stack->top->next;
    }
}
void print(Stack* stack)
{
    No *printNo = (No*) calloc(1,sizeof(No));
    printNo = stack->top;
    while(printNo != NULL)
    {
        printf("id -> %d, num -> %f", printNo->info.id, printNo->info.num);
        printNo = printNo->next;
    }
}

//AUXILIARES
int isEmpty(Stack* stack)
{
    return stack->top == NULL;
}