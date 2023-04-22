#include <stdio.h>
#include <stdlib.h>

typedef struct dataQueue
{
    int id;
    float num;
} Data;
typedef struct no
{
    Data info;
    struct no *next;
} No;
typedef struct Queue
{
    No *head;
    No *tail;
} Queue;

No *createNo(Data);
Queue *queueCreate();
int isEmpty(Queue *);
void queueEnqueue(Queue *, Data);
No *queueDequeue(Queue *);
void print(Queue *);

int main()
{
    Queue *queue;
    Data info;
    int op;
    info.id = 0;

    queue = queueCreate(queue);
    while (op != 0)
    {
        puts("Menu------");
        puts("[1] inserir\n[2] remover [3] mostrar\n[0] encerrar programa");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            puts("Numero:");
            scanf("%f", &info.num);
            info.id += 1;
            queueEnqueue(queue, info);
            break;
        case 2:
            queueDequeue(queue);
            break;
        case 3:
            print(queue);
            break;
        default:;
        }
    }
}

No *createNo(Data info)
{
    No *newNode = (No *)calloc(1, sizeof(No));
    if (newNode != NULL)
    {
        newNode->info = info;
        newNode->next = NULL;
        return newNode;
    }
}
Queue *queueCreate()
{
    Queue *queue = (Queue *)calloc(1, sizeof(Queue));
    if (queue != NULL)
    {
        queue->head = queue->tail = NULL;
        return queue;
    }
}
void queueEnqueue(Queue *queue, Data info)
{
    No *node = createNo(info);
    if (isEmpty(queue))
    {
        queue->head = queue->tail = node;
    }
    else
    {
        queue->tail->next = node;
        queue->tail = queue->tail->next;
    }
}
No *queueDequeue(Queue *queue)
{
    if (!isEmpty(queue))
    {
        free(queue->head);
        queue->head = queue->head->next;
    }
    else
    {
        puts("ERRO: fila vazia!");
    }
}
void print(Queue *queue)
{
    if (!isEmpty(queue))
    {
        No *printNo = (No *)calloc(1, sizeof(No));
        printNo = queue->head;
        while (printNo != NULL)
        {
            printf("[id -> %d, num -> %0.1f]\n", printNo->info.id, printNo->info.num);
            printNo = printNo->next;
        }
    }
    else
    {
        puts("ERRO: fila vazia!");
    }
}

// AUXILIARES
int isEmpty(Queue *queue)
{
    return queue->tail == NULL;
}