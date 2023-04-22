#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    Queue FILA;
    int option;
    No imput, removed;
    queueCreate(&FILA);
    while (option != 0)
    {
        puts("\n\tMENU");
        puts("[1] inserir\n[2] remover\n[3] imprimir\n[0] encerrar.");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            puts("Insira o nome:  ");
            scanf("%s", imput.nome);
            puts("Insira a idade:  ");
            scanf("%d", &imput.idade);
            puts("Insira o codigo:  ");
            scanf("%d", &imput.codigo);
            queueEnqueue(&FILA, imput);
            break;
        case 2:
            removed = queueDequeue(&FILA);
            printf("\n%s foi removido\n", removed.nome);
            break;
        case 3:
            queuePrint(&FILA);
            break;
        default:
            puts("\nInválido\n");
        }
    }
}