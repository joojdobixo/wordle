#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "wordle.h" //importação do cabeçalho


int main()
{
    void palavraDoJogo();
    void desenharMatriz(char matriz[TENTATIVAS][TAMANHO_PALAVRA + 1], int rodada);
    //void palavraDoJogo();
    //void desenharMatriz(char matriz[TENTATIVAS][TAMANHO_PALAVRA + 1], int rodada);
    /*
        Define a localidade para o Português-Brasil
        permitindo a utilização de acentos como ^, ç, é.
    */
    //setlocale(LC_ALL, "portuguese-brazilian");

    // Gera um número aleatório com base na hora do computador
    srand(time(NULL));

    int acertos = 0, erros = 0; // inicialização de varíaveis
    char Jogar_Novamente;

    /*
        Laço de repetição que é executado enquanto o jogador
        ao final de cada rodada escolha sim para jogar novamente
    */
    do
    {
        // Chama a função que seleciona uma palavra secreta para a rodada do jogo
        palavraDoJogo();

        char matriz[TENTATIVAS][TAMANHO_PALAVRA + 1] = {0}; //
        char tentativa[TAMANHO_PALAVRA + 1];
        int rodada;
        int acertou = 0;

        for (rodada = 0; rodada < TENTATIVAS; rodada++)
        {
            // Recebe e armazena o palpite do jogador, e faz a correção para considerar o final da string \0
            printf("Rodada %d: Digite uma palavra de %d letras: ", rodada + 1, TAMANHO_PALAVRA);
            scanf("%s", tentativa);

            while (strlen(tentativa) != TAMANHO_PALAVRA)
            {
                // Será executado toda vez que o tamanho da palavra/palpite do jogador for difetente de 5 caracteres
                printf("Palavra incorreta! Digite uma palavra de %d letras: ", TAMANHO_PALAVRA);
                scanf("%s", tentativa);
            }

            strcpy(matriz[rodada], tentativa); //

            desenharMatriz(matriz, rodada + 1); // Chama a função responsável por desenhar a matriz e incrementa o número da rodada

            if (strcmp(tentativa, palavra_secreta) == 0) //
            {
                printf("Parabéns! Você acertou a palavra!\n");
                acertos++;
                acertou = 1;
                break;
            }
        }

        if (!acertou)
        {
            printf("Que pena, voce nao conseguiu acertar a palavra. A palavra correta era: %s\n", palavra_secreta);
            erros++;
        }
        printf("Placar: %d Acertos, %d Erros\n", acertos, erros);
        printf("Tente novamente, deseja jogar mais uma vez? (s/n): ");
        scanf(" %c", &Jogar_Novamente);
    } while (Jogar_Novamente == 's');

    // imprime o placar
    printf("Obrigado por jogar! Placar final: %d acertos, %d erros\n", acertos, erros);
    return 0;
}
