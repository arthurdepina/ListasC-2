/*
 *                 Lista de Exercícios do 2o Bimestre
 *
 *              Arthur de Pina Balduino Leitão  32207840
 *              João Victor Dallapé Madeira     32209592           
 *                                          
 * github.com/arthurdepina/ListasC-2/blob/main/Listas/ListaRevisao02.c   
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Exercício 14

int memo[100][100];

int scm_recursivo(const char *X, const char *Y, int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + scm_recursivo(X, Y, m - 1, n - 1);
    else
        return fmax(scm_recursivo(X, Y, m, n - 1), scm_recursivo(X, Y, m - 1, n));
}

int scm_top_down(const char *X, const char *Y, int m, int n) {
    if (m == 0 || n == 0)
        return 0;

    if (memo[m][n] != -1)
        return memo[m][n];

    if (X[m - 1] == Y[n - 1])
        memo[m][n] = 1 + scm_top_down(X, Y, m - 1, n - 1);
    else
        memo[m][n] = fmax(scm_top_down(X, Y, m, n - 1), scm_top_down(X, Y, m - 1, n));

    return memo[m][n];
}

int scm_bottom_up(const char *X, const char *Y) {
    int m = strlen(X), n = strlen(Y);
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

// Exercício 15

int max(int a, int b) { return (a > b) ? a : b; }

int cutRodRecursiva(int precos[], int n) {
    if (n <= 0)
        return 0;
    int max_val = -1;

    for (int i = 0; i < n; i++)
        max_val = max(max_val, precos[i] + cutRodRecursiva(precos, n - i - 1));

    return max_val;
}

int cutRodBottomUp(int precos[], int n) {
    int val[n + 1];
    val[0] = 0;

    for (int i = 1; i <= n; i++) {
        int max_val = -1;
        for (int j = 0; j < i; j++)
            max_val = max(max_val, precos[j] + val[i - j - 1]);
        val[i] = max_val;
    }

    return val[n];
}

int cutRodTopDown(int precos[], int n, int memo[]) {
    if (n <= 0)
        return 0;
    if (memo[n] >= 0)
        return memo[n];

    int max_val = -1;

    for (int i = 0; i < n; i++)
        max_val = max(max_val, precos[i] + cutRodTopDown(precos, n - i - 1, memo));

    memo[n] = max_val;
    return max_val;
}

int main ()
{
    printf("=====================14=====================\n");

    char X[] = "ATCTGAT";
    char Y[] = "TGCATTA";
    printf("Tamanho da SCM: %d\n", scm_bottom_up(X, Y));
    memset(memo, -1, sizeof(memo));
    printf("Tamanho da SCM: %d\n", scm_top_down(X, Y, strlen(X), strlen(Y)));
    printf("Tamanho da SCM: %d\n", scm_recursivo(X, Y, strlen(X), strlen(Y)));

    printf("=====================15=====================\n");

    int precos[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int tamanho = sizeof(precos)/sizeof(precos[0]);
    int memo[tamanho + 1];

    for (int i = 0; i <= tamanho; i++)
        memo[i] = -1;

    printf("Receita máxima: %d\n", cutRodRecursiva(precos, tamanho));
    printf("Receita máxima: %d\n", cutRodTopDown(precos, tamanho, memo));
    printf("Receita máxima: %d\n", cutRodBottomUp(precos, tamanho));
    
    printf("============================================\n");

    return 0;
}
