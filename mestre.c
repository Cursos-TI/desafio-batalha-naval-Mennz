#include <stdio.h>
#define TAMANHO_TABULEIRO 5

// Função para inicializar o tabuleiro com zeros
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar a habilidade em cone
void habilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) return;
    
    tabuleiro[linha][coluna] = 1;
    if (linha + 1 < TAMANHO_TABULEIRO) {
        tabuleiro[linha + 1][coluna] = 1;
        if (coluna - 1 >= 0) tabuleiro[linha + 1][coluna - 1] = 1;
        if (coluna + 1 < TAMANHO_TABULEIRO) tabuleiro[linha + 1][coluna + 1] = 1;
    }
    if (linha + 2 < TAMANHO_TABULEIRO) {
        for (int i = coluna - 2; i <= coluna + 2; i++) {
            if (i >= 0 && i < TAMANHO_TABULEIRO) tabuleiro[linha + 2][i] = 1;
        }
    }
}

// Função para aplicar a habilidade em octaedro
void habilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) return;
    
    tabuleiro[linha][coluna] = 1;
    if (linha - 1 >= 0) tabuleiro[linha - 1][coluna] = 1;
    if (linha + 1 < TAMANHO_TABULEIRO) tabuleiro[linha + 1][coluna] = 1;
    if (coluna - 1 >= 0) tabuleiro[linha][coluna - 1] = 1;
    if (coluna + 1 < TAMANHO_TABULEIRO) tabuleiro[linha][coluna + 1] = 1;
}

// Função para aplicar a habilidade em cruz
void habilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) return;
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        tabuleiro[linha][i] = 1; // linha horizontal
        tabuleiro[i][coluna] = 1; // coluna vertical
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int escolha, linha, coluna;

    inicializarTabuleiro(tabuleiro);

    do {
        printf("\n*** Escolha a habilidade especial ***\n");
        printf("1. Cone\n");
        printf("2. Octaedro\n");
        printf("3. Cruz\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        if (escolha >= 1 && escolha <= 3) {
            printf("Digite a linha (0-4) e coluna (0-4): ");
            scanf("%d %d", &linha, &coluna);

            switch (escolha) {
                case 1: habilidadeCone(tabuleiro, linha, coluna); break;
                case 2: habilidadeOctaedro(tabuleiro, linha, coluna); break;
                case 3: habilidadeCruz(tabuleiro, linha, coluna); break;
            }
            exibirTabuleiro(tabuleiro);
        }
    } while (escolha != 4);

    printf("Saindo...\n");
    return 0;
}
