#include <stdio.h>

//tamanho tabuleiro e navio
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {

    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    printf("*** Jogo de Batalha Naval ***\n");
    char linha;
    int coluna;
    int linha_index, coluna_index;

    // NAVIO HORIZONTAL
    printf("Escolha a linha (A-J) e a coluna (1-8) para o navio horizontal (3 posições):\n");
    scanf(" %c %d", &linha, &coluna);
 
    linha_index = linha - 'A';
    coluna_index = coluna - 1;

    if (linha_index < 0 || linha_index >= TAMANHO_TABULEIRO || coluna_index < 0 || coluna_index > 7) {
        printf("Posição inválida!\n");
        return 1;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_index][coluna_index + i] = 3;
    }

    // NAVIO VERTICAL
    printf("Escolha a linha (A-H) e a coluna (1-10) para o navio vertical (3 posições):\n");
    scanf(" %c %d", &linha, &coluna);

    linha_index = linha - 'A';
    coluna_index = coluna - 1;

    if (linha_index < 0 || linha_index > 7 || coluna_index < 0 || coluna_index >= TAMANHO_TABULEIRO) {
        printf("Posição inválida!\n");
        return 1;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_index + i][coluna_index] = 3;
    }

    // NAVIO DIAGONAL SUPERIOR
    printf("Escolha a linha (C-J) e a coluna (1-8) para o navio diagonal superior (3 posições):\n");
    scanf(" %c %d", &linha, &coluna);
 
    linha_index = linha - 'A';
    coluna_index = coluna - 1;

    if (linha_index < 2 || linha_index >= TAMANHO_TABULEIRO || coluna_index < 0 || coluna_index > 7) {
        printf("Posição inválida!\n");
        return 1;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_index - i][coluna_index + i] = 3; // sobe na diagonal
    }

    // NAVIO DIAGONAL INFERIOR
    printf("Escolha a linha (A-H) e a coluna (1-8) para o navio diagonal inferior (3 posições):\n");
    scanf(" %c %d", &linha, &coluna);
 
    linha_index = linha - 'A';
    coluna_index = coluna - 1;

    if (linha_index < 0 || linha_index > 7 || coluna_index < 0 || coluna_index > 7) {
        printf("Posição inválida!\n");
        return 1;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_index + i][coluna_index + i] = 3; // desce na diagonal
    }

    // EXIBIR TABULEIRO
    printf("\n   ");
    for (int i = 1; i <= TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); 
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%c  ", 'A' + i); 
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}
