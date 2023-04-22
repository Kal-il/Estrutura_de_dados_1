#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <stdbool.h>
#include <time.h>

// DEFINIÇÕES DE TIPO DA LISTA DUPLAMENTE ENCADEADA (JOGO)
typedef struct node_data
{
    char infoHouse;
    int index;
} Data;
typedef struct double_node
{
    Data nodeData;
    struct double_node *next;
    struct double_node *previous;
} No;
typedef struct double_list
{
    int size;
    No *begin;
    No *end;
} double_List;

// DEFINIÇÕES DE TIPO DA LISTA SIMPLISMENTE ENCADEADA (RANKING)
typedef struct conteudo
{
    char jogador[50]; 
    int contJogadas;
    int pontos;
} Jogador;
typedef struct no
{
    Jogador info;
    struct no *prox;
} simpleNo;
typedef struct lista
{
    simpleNo *primeiro;
    simpleNo *ultimo;
} Lista;

// STRUCT DE INSEÇÃO DE JOGADOR




// FUNÇÕES BÁSICAS DA LISTA DUPLAMENTE ENCADEADA (JOGO)
double_List *createList();
No *createNo(Data);
void list_add_last(double_List *, Data);
No *deleteNo(double_List *, char);
void print_double_list(double_List *);
bool isEmpty(double_List *);
bool isFull(double_List *);

// FUNÇÕES DO JOGO
int mover(double_List *, int); // Função de movimentação do player
int sorteia_casas(double_List *, int);
void insereBomba(double_List *, int);
void inserePonto(double_List *, int);
void inserePlayer(double_List *, int);
int Atual(double_List *list);
int buscaMapa(double_List *, char);

// FUNÇÕES DA LISTA SIMPLISMENTE ENCADEADA(RANKING)
Lista *criarListaSimples();
simpleNo *criarNo(Jogador);
void adicionarRecord(Lista *, Jogador);
void mostrarRecords(Lista *);
int estaVazia(Lista *);

#endif