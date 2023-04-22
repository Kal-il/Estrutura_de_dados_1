#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{

    int opcao = -1, op = -1;
    int index, evitar;
    Jogador gamer;
    Lista *simpleList;
    simpleList = criarListaSimples();

    // MENU PRINCIPAL
    while (opcao != 3)
    {
        puts("\n--- MENU PRINCIPAL ---\n");
        puts("[1] JOGAR.\n[2] MOSTRAR RANKING\n[3] ENCERRAR PROGRAMA");
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            puts("INICIANDO JOGO...");
            double_List *list = createList();
            Data info;
            int index;
            int mov;
            // inicializa lista com player posicionado no meio

            for (int i = 0; i < 5; i++)
            {
                list_add_last(list, info);
            }
            inserePlayer(list, 2);
            // insere bomba e ponto

            index = sorteia_casas(list, -1);
            int evitar = index;
            insereBomba(list, index);
            index = sorteia_casas(list, evitar);
            inserePonto(list, index);
            int indexy = 2; // seto player no meio do campo;

            // INSIRA INFORMAÇÕES SOBRE O JOGADOR AQUI -->
            printf("Insira o seu nickname:\t");
            scanf("%s", &gamer.jogador);
            gamer.pontos = 0;
            gamer.contJogadas = 0;

            print_double_list(list);
            puts("\n__________________________________________\n");
            do
            {
                char bomba = '*', ponto = '.';
                puts("\nCONTROLES");
                puts("[<-] mover para esquerda\n[->] mover para direita");
                puts("[<<-] salto para esquerda\n[->>] salto para direita");
                puts("[-1] encerrar programa");
                scanf("%d", &op);
                switch (op)
                {
                case 4:
                    if (indexy >= list->begin->nodeData.index)
                    {
                        indexy--;
                        mov = mover(list, indexy);

                        if (mov == 3)
                        {
                            puts("\nGAME OVER!");
                            op = -1;
                        }
                        else if (mov)
                        {
                            gamer.pontos++;
                            evitar = buscaMapa(list, bomba);
                            index = sorteia_casas(list, evitar);
                            inserePonto(list, index);
                        }
                        gamer.contJogadas++;
                        if (gamer.contJogadas % 4 == 0)
                        {
                            deleteNo(list, bomba);
                            evitar = buscaMapa(list, ponto);
                            index = sorteia_casas(list, evitar);
                            inserePonto(list, index);
                        }
                    }
                    else
                    {
                        indexy++;
                        puts("\nquebra de limite!");
                    }
                    print_double_list(list);
                    break;
                case 6:
                    indexy++;
                    if (indexy <= list->end->nodeData.index)
                    {
                        mov = mover(list, indexy);

                        if (mov == 3)
                        {
                            puts("\nGAME OVER!");
                            op = -1;
                        }
                        else if (mov)
                        {
                            gamer.pontos++;
                            char bomba = '*';
                            evitar = buscaMapa(list, bomba);
                            index = sorteia_casas(list, evitar);
                            inserePonto(list, index);
                        }
                        gamer.contJogadas++;
                        if (gamer.contJogadas % 4 == 0)
                        {
                            deleteNo(list, bomba);
                            evitar = buscaMapa(list, ponto);
                            index = sorteia_casas(list, evitar);
                            inserePonto(list, index);
                        } 
                    } else
                    {
                        indexy--;
                        puts("\nquebra de limite!");
                    }
                    print_double_list(list);
                    break;
                case 44:
                    indexy -= 2;
                    if (indexy >= list->begin->nodeData.index)
                    {
                        mov = mover(list, indexy);

                        if (mov == 3)
                        {
                            puts("\nGAME OVER!");
                            op = -1;
                        }
                        else if (mov)
                        {
                            gamer.pontos++;
                            char bomba = '*';
                            evitar = buscaMapa(list, bomba);
                            index = sorteia_casas(list, evitar);
                            inserePonto(list, index);
                        }
                        gamer.contJogadas++;
                        if (gamer.contJogadas % 4 == 0)
                        {
                            deleteNo(list, bomba);
                            evitar = buscaMapa(list, ponto);
                            index = sorteia_casas(list, evitar);
                            inserePonto(list, index);
                        }
                    }
                    else
                    {
                        puts("Pulo não permitido: quebra de limite");
                        index += 2;
                    }
                    print_double_list(list);
                    break;
                case 66:
                    indexy += 2;
                    if (indexy <= list->end->nodeData.index)
                    {
                        mov = mover(list, indexy);

                        if (mov == 3)
                        {
                            puts("\nGAME OVER!");
                            op = -1;
                        }
                        else if (mov)
                        {
                            gamer.pontos++;
                            char bomba = '*';
                            evitar = buscaMapa(list, bomba);
                            index = sorteia_casas(list, evitar);
                            inserePonto(list, index);
                        }
                        gamer.contJogadas++;
                        if (gamer.contJogadas % 4 == 0)
                        {
                            deleteNo(list, bomba);
                            evitar = buscaMapa(list, ponto);
                            index = sorteia_casas(list, evitar);
                            inserePonto(list, index);
                        }
                    }
                    else
                    {
                        puts("Pulo nao perfitido: quebra de limite");
                        index -= 2;
                    }
                    print_double_list(list);
                default:
                    break;
                }

            } while (op != -1);
            adicionarRecord(simpleList, gamer);
        }
        else if (opcao == 2)
        {
            mostrarRecords(simpleList);
        }
        else if (opcao == 3)
        {
            return 0;
        }
        else
        {
            return 0;
        }
    }
}