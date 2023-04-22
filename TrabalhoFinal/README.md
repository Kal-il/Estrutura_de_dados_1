Para compilar o programa digite, no diretório dos arquivos:

    gcc biblioteca.h implementacao.c
Pare gerar uma saída no Ubuntu:
    
    ./a.out
Pare gerar uma saída no Windows:

    ./a.exe
    
Nota: O código refere-se ao meu ultimo trabalho na diciplina de Estrutura de dados 1, sendo que o enunciado era:

Pensem como deve ser a estrutura de dados para a implementação deste jogo (deve ser uma estrutura obrigatoriamente com alocação dinâmica). Tragam as anotações para o plantão de dúvidas na quarta feira.

**Jogo:** o jogador (|) deve coletar os pontos (.) e desviar das bombas (*). Se o jogador entrar em uma casa com bomba (*), ele perdeu. Se o jogador conseguir completar 10 casas, ele ganhou.

**Início do jogo:** Inicia-se com 5 casas (-), sendo o jogador posicionado no centro, 1 ponto e uma bomba, posicionados em casas aleatórias.

```
.     |  *
-  -  -  -  -
```

**Movimentos do jogador:**

Esquerda (jogador se move uma casa para a esquerda)

Direita (jogador se move uma casa para a direita)

Pulo Esquerda (jogador se move duas casas para a esquerda)

Pulo Direita (jogador se move duas casas para a direita)

Quando o jogador coleta um ponto (entra em uma casa com "."), aumenta-se uma casa em uma das extremidades e outro ponto aparece aleatoriamente em uma casa.

A cada 4 movimentos do jogador, a bomba explode (exclui-se a casa em que está a "*") e outra bomba aparece aleatoriamente em uma casa.

Cada casa tem apenas 1 elemento, jogador ou ponto ou bomba ou está vazia.

```c

```

**Registros dos records**: Deve ser mantida uma lista com histórico dos jogos contendo o número de movimentos das partidas que o jogador ganhou. Esta lista deve ser ordenada de forma decrescente.
    
