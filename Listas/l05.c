#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void n_binario(char *bin, int n, int atual){
    if (atual == n) {
        bin[atual]  =  '\0';
        printf("%s\n", bin);
        return;
    }
    
    bin[atual] = '0';
    n_binario(bin, n, atual+1);

    bin[atual] = '1';
    n_binario(bin, n, atual+1);
}

void abba(char *resultado, int m, int n, int count_m, int count_n ){
    if (count_m == m && count_n == n) {
        resultado[count_m + count_n] = '\0';
        printf("%s\n", resultado);
        return;
    }
    
    if (count_m < m) {
        resultado[count_m + count_n] = 'A';
        abba(resultado, m, n, count_m + 1, count_n);
    }

    if (count_n <  n) {
        resultado[count_m + count_n] = 'B';
        abba(resultado, m, n, count_m, count_n + 1);
    }
}

void mostrar_tabuleiro(int **m, int linhas, int colunas){
    int i, j, k;
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int alocando_sudoku(int **tabuleiro, int linhas, int colunas){
    FILE *tab;
    tab = fopen("l05_sudoku.txt", "r");
    if (tab == NULL){
        printf("Erro na abertura do arquivo");
        return 1;
    }
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            fscanf(tab, "%d", &tabuleiro[i][j]);
        }
    }
    fclose(tab);
    return 0;
}

bool verifica_possibilidade(int **tabuleiro, int n, int x, int y){
    // Verificando na coluna y:
    for(int i = 0; i < 4; i++){
        if(tabuleiro[i][y] == n){
            return false;
        }
    }
    // Verificando na linha x:
    for(int j = 0; j < 4; j++){
        if(tabuleiro[x][j] == n){
            return false;
        }
    }

    return true;
}

int resolve_sudoku(int **tabuleiro, int linhas, int colunas){
    int n;
    for(int l = 0; l < 4; l++){
        for(int c = 0; c < 4; c++){
            if (tabuleiro[l][c] == 0){
                for(int n = 1; n <= 4; n++){
                    if(verifica_possibilidade(tabuleiro, n, l, c)){
                        tabuleiro[l][c] = n;
                        if(resolve_sudoku(tabuleiro, linhas, colunas)){
                            return 1; // Solucionado para n
                        }
                    tabuleiro[l][c] = 0;
                    }
                }
            return 0; // Sem solução
            }
        }
    }
    return 1; // Resolvido
}


int main() {
    printf("====== 01 ======\n");
    int tam_str = 4;
    printf("Exemplo, n = %d:\n", tam_str - 1);
    char str[tam_str + 1];
    n_binario(str, tam_str, 0);

    printf("====== 02 ======\n");
    int m = 3;                  // Gols de A
    int n = 3;                  // Gols de B
    int tam_placar = m + n;
    char placar[tam_placar + 1];
    abba(placar, m, n,  0, 0);

    printf("====== 03 ======\n");
    int linhas, colunas;
    linhas = 4;
    colunas = 4;
    int **tabuleiro = malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++){
        tabuleiro[i] = malloc(colunas * sizeof(int));
    }
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            tabuleiro[i][j] = 0;
        }
    }
    alocando_sudoku(tabuleiro, linhas, colunas);
    printf("TABULEIRO INICIAL: \n\n");
    mostrar_tabuleiro(tabuleiro, linhas, colunas);

    printf("\nTABULEIRO SOLUCIONADO: \n\n");
    resolve_sudoku(tabuleiro, linhas, colunas);
    mostrar_tabuleiro(tabuleiro, linhas, colunas);
    return 0;
}