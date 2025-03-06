#include <stdio.h>

//define o tamanho do navio e tabuleiro caso queira alterar eles é so mudar aqui
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {

    //define que o TAMANHO_TABULEIRO = 1O // tabuleiro[10][10] = {0}
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    //cria vetores para armazenar as posições dos navios
    int navio_horizontal[TAMANHO_NAVIO];
    int navio_vertical[TAMANHO_NAVIO];

    printf("*** Jogo de Batalha Naval ***\n");
    char linha;
    int coluna;

    //escolher posição navio horizontal
    printf("Escolha a linha (A-J) e a coluna (1-8) para o navio horizontal (3 posições):\n");
    scanf(" %c %d", &linha, &coluna);
 
        //valor de 'A' 66
    int linha_index = linha - 'A';
    int coluna_index = coluna - 1;

        //verifica se o navio cabe no tabuleiro
    if (linha_index < 0 || linha_index >= TAMANHO_TABULEIRO || coluna_index < 0 || coluna_index > 7) {
        printf("Posição inválida!\n");
        return 1; //finaliza o programa com codigo de erro
    }
            //for para percorrer 3 posições
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_index][coluna_index + i] = 3;
    }    //marca as celulas ocupadas pelo navio = 3

    //navio vertical
    printf("Escolha a linha (A-H) e a coluna (1-10) para o navio vertical (3 posições):\n");
    scanf(" %c %d", &linha, &coluna);

    linha_index = linha - 'A';
    coluna_index = coluna - 1;

    if (linha_index < 0 || linha_index > 7 || coluna_index < 0 || coluna_index >= TAMANHO_TABULEIRO) {
        printf("Posição inválida! O navio deve caber no tabuleiro.\n");
        return 1;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_index + i][coluna_index] = 3;
    }

    //exibição do tabuleiro
    printf("\n   ");
    for (int i = 1; i <= TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); 
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%c  ", 'A' + i); 
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); //valor de cada casa (0 ou 3)
        }
        printf("\n"); 
    }

    return 0;
}