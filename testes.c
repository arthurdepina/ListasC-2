#include <stdio.h>
#include <stdbool.h>

#define N 8

int sol[N][N];

int moveX[N] = {2, 1, -1, -2, -2, -1, 1, 2};
int moveY[N] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

void printSolution ()
{
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}

bool solveKTUtil (int x, int y, int movei)
{
    if (movei == N * N)
        return true;

    for (int k = 0; k < 8; k++) {
        int nextX = x + moveX[k];
        int nextY = y + moveY[k];
        if (isSafe(nextX, nextY)) {
            sol[nextX][nextY] = movei;
            if (solveKTUtil(nextX, nextY, movei + 1))
                return true;
            sol[nextX][nextY] = -1;
        }
    }
    return false;
}

bool solveKT(int startX, int startY)
{
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    sol[startX][startY] = 0;

    if (!solveKTUtil(startX, startY, 1)) {
        printf("Solução não existe");
        return false;
    } else
        printSolution();

    return true;
}

int main () 
{
    int startX = 0; // Coordenada x inicial
    int startY = 0; // Coordenada y inicial

    solveKT(startX, startY);

    return 0;
}
