#ifndef WORDLE_H_INCLUDED
#define WORDLE_H_INCLUDED

#define TAMANHO_PALAVRA 5
#define TENTATIVAS 5
#define NUM_PALAVRAS 5

// Declaração da variável global palavra_secreta
extern char palavra_secreta[TAMANHO_PALAVRA + 1];

// Funções utilizadas no programa
void palavraDoJogo();

void desenharMatriz(char matriz[TENTATIVAS][TAMANHO_PALAVRA + 1], int rodada);

#endif // WORDLE_H_INCLUDED