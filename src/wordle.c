#include "wordle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
    incrementa em +1 devida a limitação de como
    Strings funcionam em C, pois sempre são finalizadas em \0
*/

char palavra_secreta[TAMANHO_PALAVRA + 1];

void palavraDoJogo()
{
    char palavras[NUM_PALAVRAS][TAMANHO_PALAVRA + 1] = {"carro", "folha", "museu", "livro", "bolsa"};
    strcpy(palavra_secreta, palavras[rand() % NUM_PALAVRAS]); //
}

void desenharMatriz(char matriz[TENTATIVAS][TAMANHO_PALAVRA + 1], int rodada)
{
    for (int i = 0; i < TENTATIVAS; i++)
    {
        for (int j = 0; j < TAMANHO_PALAVRA; j++)
        {
            if (i < rodada)
            {
                if (matriz[i][j] == palavra_secreta[j])
                {
                    printf("\033[0;32m%c\033[0m ", matriz[i][j]); // Letra na Posição Correta ---> Verde
                }
                else if (strchr(palavra_secreta, matriz[i][j]))
                {
                    printf("\033[0;33m%c\033[0m ", matriz[i][j]); // Letras corretas na posição errada ---> Amarelo
                }
                else
                {
                    printf("%c ", matriz[i][j]); // Letras não presente na Palavra ---> Branco
                }
            }
            else
            {
                printf("_ "); // Espaço vazio
            }
        }
        printf("\n");
    }
}
