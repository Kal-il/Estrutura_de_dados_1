#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#define MAXTAM 10
#include <time.h>

double_List *createList()
{
    double_List *list = (double_List *)calloc(1, sizeof(double_List));
    if (list != NULL)
    {
        list->begin = NULL;
        list->end = NULL;
        list->size = 0;
        return list;
    }
}
No *createNo(Data info)
{
    No *node = (No *)calloc(1, sizeof(No));
    if (node != NULL)
    {
        node->previous = NULL;
        node->next = NULL;
        node->nodeData.infoHouse = info.infoHouse;
        return node;
    }
}
void list_add_last(double_List *list, Data info)
{
    info.infoHouse = ' ';
    No *n = createNo(info);
    if (n != NULL)
    {
        if (isEmpty(list))
        {
            n->nodeData.index = list->size;
            list->begin = list->end = n;
            n->previous = list->end;
            list->size++;
        }
        else
        {
            if (!isFull(list))
            {
                n->nodeData.index = list->size;
                list->end->next = n;
                n->previous = list->end;
                list->end = n;
                list->size++;
            }
            else
            {
                puts("\n10 casas atingidas!");
            }
        }
    }
}
void print_double_list(double_List *list)
{
    No *n = list->begin;
    while (n != list->end->next)
    {
        printf("[%c]", n->nodeData);
        n = n->next;
    }
}
No *deleteNo(double_List *list, char info)
{
    if (!isEmpty(list))
    {
        // caso 1 -- elemento está no inicio
        if (list->begin->nodeData.infoHouse == info)
        {
            No *p = list->begin;

            // a lista só possui um elemento (remoção no inicio da lista)
            if (list->begin == list->end)
            {
                list->begin = list->end = NULL;
                free(p);
                list->size--;
            }
            else // a lista possui mais de um elemento
            {
                list->begin = p->next;
                list->begin->previous = NULL;
                free(p);
                list->size--;
            }
        }
        // caso 2 -- elemento está no meio da lista
        // caso 3 -- elemento está no final da lista
        else
        {
            No *p = list->begin->next;
            while (p != NULL)
            {
                if (p->nodeData.infoHouse == info)
                {
                    if (list->end == p)
                    {
                        // caso 3.
                        list->end = p->previous;
                        list->end->next = NULL;
                    }
                    else
                    {
                        // caso 2.
                        p->previous->next = p->next;
                        p->next->previous = p->previous;
                    }
                    free(p);
                    p = NULL;
                    list->size--;
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
int sorteia_casas(double_List *list, int evitar)
{
    int sorteio;
    int indiceAtl;
    indiceAtl = Atual(list);
    srand(time(NULL));
    do
    {
        sorteio = rand() % 9;
    } while (sorteio == indiceAtl || sorteio >= list->size || sorteio == evitar);
    return sorteio;
}

void insereBomba(double_List *list, int index)
{
    No *n = list->begin;
    while (n != NULL)
    {
        if (n->nodeData.index == index)
        {
            n->nodeData.infoHouse = '*';
        }
        n = n->next;
    }
}
void inserePonto(double_List *list, int index)
{
    No *n = list->begin;
    while (n != NULL)
    {
        if (n->nodeData.index == index)
        {
            n->nodeData.infoHouse = '.';
        }
        n = n->next;
    }
}
void inserePlayer(double_List *list, int index)
{
    No *n = list->begin;
    while (n != NULL)
    {
        if (n->nodeData.index == index)
        {
            n->nodeData.infoHouse = '|';
        }
        n = n->next;
    }
}
int Atual(double_List *list) // erro as vezes retorna zero
{
    No *auxNo = list->begin;
    int indiceAtual;
    char temp;
    temp = '|';
    while (auxNo != list->end->next)
    {
        if (auxNo->nodeData.infoHouse == temp)
        {
            indiceAtual = auxNo->nodeData.index;
            return indiceAtual;
        }
        auxNo = auxNo->next;
    }
}
int mover(double_List *list, int info)
{
    char bomba = '*';
    char ponto = '.';
    char space = ' ';
    int flag = -1;
    No *n = list->begin;
    while (n != NULL)
    {
        if (n->nodeData.index == info)
        {
            if (n->nodeData.infoHouse == bomba)
            {
                puts("\nCABUM!");
                deleteNo(list, n->nodeData.infoHouse); // função pra deletar nó
                // sortear valor para adicionar a nova bomba e o player
                return 3;
            }
            else if (n->nodeData.infoHouse == ponto)
            {
                puts("\nPARABENS, GANHOU UM PONTO!\n");
                n->nodeData.infoHouse = '|';
                Data data;
                list_add_last(list, data);
                // sortear novo local para adicionar o ponto

                flag = 2;
            }
            else if (n->nodeData.infoHouse == space)
            {
                n->nodeData.infoHouse = '|';
            }
        }

        n = n->next;
    }
    No *n2 = list->begin;
    while (n2 != NULL)
    {
        if (n2->nodeData.index != info)
        {
            if (n2->nodeData.infoHouse == '|')
            {
                n2->nodeData.infoHouse = ' '; //"remove o '|' que ficou pra trás.
            }
        };
        n2 = n2->next;
    }
    if (flag == 2)
    {
        return 1;
    }
    return 0;
}
int buscaMapa(double_List *list, char item)
{
    No *aux = list->begin;
    while (aux)
    {
        if (aux->nodeData.infoHouse == item)
        {
            return aux->nodeData.index;
        }
        else
        {
            aux = aux->next;
        }
    }
}

// FUNÇÕES DA SIMPLISMENTE ENCADEADA -->

Lista *criarListaSimples()
{
    Lista *l = (Lista *)calloc(1, sizeof(Lista));
    if (l != NULL)
    {
        l->primeiro = l->ultimo = NULL;
        return l;
    }
    else
    {
        puts("ERRO AO ALOCAR");
    }
}
simpleNo *criarNo(Jogador info)
{
    simpleNo *n = (simpleNo *)calloc(1, sizeof(simpleNo));
    if (n != NULL)
    {
        n->info = info;
        n->prox = NULL;
        return n;
    }
    else
    {
        puts("ERRO AO ALOCAR");
    }
}
void adicionarRecord(Lista *lista, Jogador info)
{
    simpleNo *node = criarNo(info);
    if (estaVazia(lista))
    {
        lista->primeiro = node;
        lista->ultimo = node;
    }
    else if (info.pontos >= lista->primeiro->info.pontos)
    {
        node->prox = lista->primeiro;
        lista->primeiro = node;
    }
    else if (info.pontos < lista->ultimo->info.pontos)
    {
        lista->ultimo->prox = node;
        lista->ultimo = lista->ultimo->prox;
    }
    else
    {
        simpleNo *proximo = lista->primeiro;
        simpleNo *anterior;
        int flag = 0;
        while (flag != 1)
        {
            if (info.pontos >= proximo->info.pontos)
            {
                node->prox = proximo;
                anterior->prox = node;
                flag = 1;
            }
            else
            {
                anterior = proximo;
                proximo = proximo->prox;
            }
        }
    }
}
int estaVazia(Lista *list)
{
    return (list->primeiro == NULL);
}
void mostrarRecords(Lista *lista)
{
    simpleNo *n = lista->primeiro;
    while (n != lista->ultimo->prox)
    {
        printf("\nJogador: %s\nPontos: %d \nNumero de jogadas : %d \n", n->info.jogador, n->info.pontos, n->info.contJogadas);
        n = n->prox;
    }
}

// AUXILIARES
bool isEmpty(double_List *list)
{
    return (list->size == 0 && list->begin == NULL && list->end == NULL);
}
bool isFull(double_List *list)
{
    return (list->size == MAXTAM);
}