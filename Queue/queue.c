#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define MAX 100

void queueCreate(Queue *q)
{
    q->data = (No *)calloc(MAX, sizeof(No));
    q->front = 0;
    q->rear = -1;
}
int isEmpty(Queue *q)
{
    return q->rear == -1;
}
int isFull(Queue *q)
{
    return q->rear == MAX - 1;
}
void queueEnqueue(Queue *q, No imput)
{
    if (isFull(q))
    {
        puts("\nERRO: fila cheia!\n");
    }
    else
    {
        q->rear++;
        q->data[q->rear] = imput;
    }
}
No queueDequeue(Queue *q)
{
    if (isEmpty(q))
    {
        puts("\nERRO: fila vazia!\n");
        No retrn = {0};
        return retrn;
    }
    else
    {
        q->front++;
        return q->data[q->front - 1];
    }
}
void queueDestroy(Queue *q)
{
    free(q->data);
}
void queuePrint(Queue *q)
{
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("\n| Nome : %s | Idade : %d  | Codigo : %d |", q->data[i].nome, q->data[i].idade, q->data[i].codigo);
    }
}