#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dataOfNode
{
    char nomeDoAluno[50];
    int AlunoID;
    int TurmaDoAluno;
} NodeData;

typedef struct node
{
    struct node *next;
    struct node *previous;
    NodeData infoOfNode;
} No;
typedef struct queue
{
    No *begin;
    No *end;
    int size;
} Queue;

//   DFINIÇÃO DAS FUNÇÕES BÁSICAS-->
Queue *queueCreate();
No *nodeCreate(NodeData);
No *queueDequeue(Queue *, int);
void search(Queue *, int);
void queueEnqueue(Queue *, NodeData);
void print(Queue *);
bool isEmpty(Queue *);

//     MAIN -->

int main()
{
    Queue *queue;
    NodeData infoDoEstudante;
    int op;
    int id, turma;
    queue = queueCreate();
    do
    {
        puts("\n_____________________________");
        puts("\t   MENU");
        puts("| [1] inserir aluno \n| [2] buscar aluno por ID \n| [3] mostrar lista de alunos \n| [4] remover por sala \n| [5] encerrar programa |");
        scanf("%d", &op);
        puts("\n_____________________________");
        switch (op)
        {
        case 1:
            printf("\nNome do aluno:\t");
            scanf("%s", &infoDoEstudante.nomeDoAluno);
            printf("\nTurma do aluno:\t");
            scanf("%d", &infoDoEstudante.TurmaDoAluno);
            printf("\nDigite o ID:\t");
            scanf("%d", &infoDoEstudante.AlunoID);

            queueEnqueue(queue, infoDoEstudante);
            break;

        case 2:
            printf("\nInsira o ID:\t");
            scanf("%d", &id);

            search(queue, id);
            break;
        case 3:
            print(queue);
            break;
        case 4:
            printf("\nDigite o numero da turma a ser removida:\t");
            scanf("%d", &turma);
            queueDequeue(queue, turma);
            puts("\nAluno removido");
            break;
        case 5:
            puts("Aluno: Kalil Garcia Canuto.\n\nFIM DO PROGRAMA\n");
            op = -1;
            break;
        default: puts("\nvalor inválido");
        }
        system("pause");
        system("cls");
    } while (op != -1);
    return 0;
}

// IMPLEMENTAÇÃO DAS FUNÇÕES -->

Queue *queueCreate()
{
    Queue *queue = (Queue *)calloc(1, sizeof(Queue));
    if (queue)
    {
        queue->begin = queue->end = NULL;
        queue->size = 0;
        return queue;
    }
    else
    {
        puts("\nERRO: NÃO FOI POSSIVEL ALOCAR MEMÓRIA");
    }
}
No *nodeCreate(NodeData info)
{
    No *no = (No *)calloc(1, sizeof(No));
    if (no)
    {
        no->infoOfNode = info;
        no->next = no->previous = NULL;
        return no;
    }
    else
    {
        puts("\nERRO: NÃO FOI POSSIVEL ALOCAR MEMÓRIA");
    }
}
bool isEmpty(Queue *queue)
{
    return (queue->size == 0);
}

void queueEnqueue(Queue *queue, NodeData infoDoEstudante)
    {
        No *no = nodeCreate(infoDoEstudante);

            if (isEmpty(queue))
            {
                queue->begin = no;
                queue->end = no;
            }
            else if (infoDoEstudante.AlunoID <= queue->begin->infoOfNode.AlunoID) // checa se o id é >= ao primeiro, se sim insere no começo;
            {
                queue->begin->previous = no;
                no->next = queue->begin;
                queue->begin = queue->begin->previous;
            }
            else if (infoDoEstudante.AlunoID >= queue->end->infoOfNode.AlunoID) // checa se o id é <= ao ultimo da lista, se sim insere no final
            {
                no->previous = queue->end;
                queue->end->next = no;
                queue->end = queue->end->next;
            }
            else // se final< id < começo então insere no meio;
            {
                No *next = queue->begin;
                No *prev;
                int flag = 0;
                while (flag != 1)
                {
                    if (infoDoEstudante.AlunoID <= next->infoOfNode.AlunoID)
                    {
                        no->next = next;
                        next->previous = no;
                        prev->next = no;
                        no->previous = prev;
                        flag = 1;
                    }
                    else
                    {
                        prev = next;
                        next = next->next;
                    }
                }
            }
            queue->size++;
    }
No *queueDequeue(Queue *queue, int id)
{
    if (!isEmpty(queue))
    {
        // caso 1 -- elemento está no inicio
        if (queue->begin->infoOfNode.TurmaDoAluno == id)
        {
            No *p = queue->begin;

            // a lista só possui um elemento (remoção no inicio da lista)
            if (queue->begin == queue->end)
            {
                queue->begin = queue->end = NULL;
                free(p);
                queue->size--;
            }
            else // a lista possui mais de um elemento
            {
                queue->begin = p->next;
                queue->begin->previous = NULL;
                free(p);
                queue->size--;
            }
        }
        // caso 2 -- elemento está no meio da lista
        // caso 3 -- elemento está no final da lista
        else
        {
            No *p = queue->begin->next;
            while (p != NULL)
            {
                if (p->infoOfNode.TurmaDoAluno == id)
                {
                    if (queue->end == p)
                    {
                        // caso 3.
                        queue->end = p->previous;
                        queue->end->next = NULL;
                    }
                    else
                    {
                        // caso 2.
                        p->previous->next = p->next;
                        p->next->previous = p->previous;
                    }
                    free(p);
                    p = NULL;
                    queue->size--;
                }
                else
                {
                    p = p->next;
                }
            }
        }
    }
    else
    {
        puts("ERRO:lista vazia!");
    }
}
void print(Queue *queue)
{
    No *No_de_pesquisa = queue->begin;
    while (No_de_pesquisa != NULL)
    {
        puts("\n=======================");
        printf("Nome do aluno : %s\n", No_de_pesquisa->infoOfNode.nomeDoAluno);
        printf("ID do aluno : %d\n", No_de_pesquisa->infoOfNode.AlunoID);
        printf("Turma do aluno: %d\n", No_de_pesquisa->infoOfNode.TurmaDoAluno);
        puts("\n=======================");

        No_de_pesquisa = No_de_pesquisa->next;
    }
}
void search(Queue *queue, int id)
{
    No *No = queue->begin;
    while (No != NULL)
    {
        if (No->infoOfNode.AlunoID == id)
        {
            printf("\nAluno  %s.\nturma %d\n", No->infoOfNode.nomeDoAluno, No->infoOfNode.TurmaDoAluno);
        }
        No = No->next;
        
    }
}