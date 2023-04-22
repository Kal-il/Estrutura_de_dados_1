#ifndef QUEUE_H
#define QUEUE_H

typedef struct no
{
    char nome[50];
    int idade;
    int codigo;
} No;

typedef struct queue
{
    int rear, front;
    No *data;
} Queue;

void queueCreate(Queue *);
void queueEnqueue(Queue *, No);
No queueDequeue(Queue *);
int isFull(Queue *);
int isEmpty(Queue *);
void queueDestroy(Queue *);
void queuePrint(Queue *);

#endif