#include <stdio.h>
#include <stdbool.h>

#define N 8

int solucao[N][N];
int movimentos_x[N] = {2, 1, -1, -2, -2, -1, 1, 2};
int movimentos_y[N] = {1, 2, 2, 1, -1, -2, -2, -1};

void exibir_solucao()
{
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            printf(" %2d ", solucao[x][y]);
        printf("\n");
    }
}

bool casa_possivel(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N && solucao[x][y] == -1);
}

bool soluciona_percurso(int x, int y, int count)
{
    if (count == N * N) return true;

    for (int i = 0; i < 8; i++){
        int proximo_x = x + movimentos_x[i];
        int proximo_y = y + movimentos_y[i];
        if (casa_possivel(proximo_x, proximo_y)) {
            solucao[proximo_x][proximo_y] = count;
            if(soluciona_percurso(proximo_x, proximo_y, count + 1))
                return true;
            solucao[proximo_x][proximo_y] = -1;
        }
    }
    return false;
}

bool percurso_cavalo(int inicio_x, int inicio_y)
{
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            solucao[x][y] = -1;
        }
    }

    solucao[inicio_x][inicio_y] = 0;

    if (!soluciona_percurso(inicio_x, inicio_y, 1)){
        printf("Sem solução.\n");
        return false;
    } else {
        printf("Existe solução:\n");
        exibir_solucao();
    }
}

int main()
{
    int inicio_x = 0;
    int inicio_y = 0;
    percurso_cavalo(inicio_x, inicio_y);
    return 0;
}
