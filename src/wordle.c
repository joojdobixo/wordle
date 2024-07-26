#include "wordle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
    incrementa em +1 devida a limitação de como
    Strings funcionam em C, pois sempre são finalizadas em \0
*/
extern char palavra_secreta[TAMANHO_PALAVRA + 1];

void palavraDoJogo()
{
    // Declara e inicializa a lista de palavras
    char palavras[NUM_PALAVRAS][TAMANHO_PALAVRA + 1] = {"carro", "folha", "museu", "livro", "bolsa"};

    // Copia uma das palavras e gera um índice aleatório para a variável global palavra_secreta
    strcpy(palavra_secreta, palavras[rand() % NUM_PALAVRAS]); //
}

// Função para desenhar a matriz de tentativas e comparar com a palavra secreta
void desenharMatriz(char matriz[TENTATIVAS][TAMANHO_PALAVRA + 1], int rodada)
{

    // Percorre por cada linha da matriz, sendo cada linha uma tentativa
    for (int i = 0; i < TENTATIVAS; i++)
    {
        // Loop através de cada caractere na linha atual
        for (int j = 0; j < TAMANHO_PALAVRA; j++)
        {
            // Verifica se a tentativa atual (linha i) foi feita (i < rodada)
            if (i < rodada)
            {
                // Se o caractere na tentativa está na posição correta
                if (matriz[i][j] == palavra_secreta[j])
                {
                    printf("\033[0;32m%c\033[0m ", matriz[i][j]); // Letra na Posição Correta ---> Verde
                }
                // Se o caractere está presente na palavra secreta, mas na posição errada
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