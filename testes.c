#include <stdio.h>
#include <stdbool.h>

#define N 8 // Tamanho do tabuleiro

int sol[N][N]; // Matriz para armazenar a solução

// Movimentos possíveis para o cavalo
int moveX[N] = {2, 1, -1, -2, -2, -1, 1, 2};
int moveY[N] = {1, 2, 2, 1, -1, -2, -2, -1};

// Função para verificar se as coordenadas estão dentro dos limites do tabuleiro
bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

// Função para imprimir a solução
void printSolution() {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}

// Função recursiva para resolver o problema do passeio do cavalo
bool solveKTUtil(int x, int y, int movei) {
    if (movei == N * N)
        return true; // Todos os quadrados foram visitados

    // Tentar todos os próximos movimentos a partir da posição atual
    for (int k = 0; k < 8; k++) {
        int nextX = x + moveX[k];
        int nextY = y + moveY[k];
        if (isSafe(nextX, nextY)) {
            sol[nextX][nextY] = movei;
            if (solveKTUtil(nextX, nextY, movei + 1))
                return true;
            sol[nextX][nextY] = -1; // Backtracking
        }
    }
    return false;
}

bool solveKT(int startX, int startY) {
    // Inicializar a matriz de solução
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    sol[startX][startY] = 0; // Posição inicial

    if (!solveKTUtil(startX, startY, 1)) {
        printf("Solução não existe");
        return false;
    } else
        printSolution();

    return true;
}

int main() {
    int startX = 0; // Coordenada x inicial
    int startY = 0; // Coordenada y inicial

    solveKT(startX, startY);

    return 0;
}
