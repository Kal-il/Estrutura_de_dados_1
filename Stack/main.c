#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    Stack pilha;
    int option;
    createStack(&pilha, MAX);
    float removed, entrada, imput;
    while (option != -1)
    {
        puts("\n-----------------\nHOME\n[1] inserir item\n[2] remover item\n[3] mostrar pilha\n[4] procurar por item\n[-1] encerrar");
        scanf("%d", &option);
        if (option == 1)
        {
            if (!isFull(&pilha))
            {
                puts("\nDigite o item a ser inserido:\n\n");
                scanf("%f", &imput);
                push(&pilha, imput);
            }
            else
            {
                puts("ERRO: a pilha está cheia!");
            }
        }
        if (option == 2)
        {
            if (!isEmpty(&pilha))
            {
                removed = pop(&pilha);
                printf("\nO valor %0.1f foi removido com sucesso\n", removed);
            }
            else
            {
                puts("\nERRO: pilha está vazia!\n");
            }
        }
        if (option == 3)
        {
            if (!isEmpty(&pilha)) // por que não pode usar o &?
            {
                printStack(&pilha);
            }
            else
            {
                puts("\n\tPilha vazia!");
            }
        }
        if (option == 4)
        {
            puts("\nDigite o valor que deseja checar:\t");
            scanf("%f", &entrada);
            printf("\nO valor inserido foi encontrado %d vezes\n", stackSearch(&pilha, entrada));
        }
        else if (option == -1)
        {
            return 0;
        }
    }
}