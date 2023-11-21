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
#include <limits.h>

int max(int a, int b) { return (a > b) ? a : b; }

// Exercício 12

                        // Função recursiva para o problema da mochila
int knapsack(int W, int wt[], int val[], int n) {
    // Caso base
    if (n == 0 || W == 0) return 0;

    // Se o peso do último item for mais do que a capacidade da mochila, ele não pode ser incluído
    if (wt[n-1] > W)
        return knapsack(W, wt, val, n-1);

    // Retorna o máximo de dois casos:
    // (1) último item incluído
    // (2) não incluído
    else return max(val[n-1] + knapsack(W-wt[n-1], wt, val, n-1), knapsack(W, wt, val, n-1));
}

                        // Função top-down para o problema da mochila
int knapSackUtil(int W, int wt[], int val[], int n, int **dp) {
    if (n == 0 || W == 0) return 0;

    if (dp[n][W] != -1) return dp[n][W];

    if (wt[n-1] > W)
        return dp[n][W] = knapSackUtil(W, wt, val, n-1, dp);
    else
        return dp[n][W] = max(val[n-1] + knapSackUtil(W-wt[n-1], wt, val, n-1, dp), 
                              knapSackUtil(W, wt, val, n-1, dp));
}

int knapsack_top_down(int W, int wt[], int val[], int n) {
    int **dp;
    dp = (int **)malloc((n+1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((W+1) * sizeof(int));
        memset(dp[i], -1, (W+1) * sizeof(int));
    }
    return knapSackUtil(W, wt, val, n, dp);
}

                        // Função bottom-up para o problema da mochila
int knapsack_bottom_up(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n+1][W+1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    return K[n][W];
}                  

// Exercício 13

int m[100][100];
int s[100][100];

void matrix_chain_order (int p[], int n) 
{
    int i, j, k, L, q;

    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_optimal_parens (int i, int j) 
{
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        print_optimal_parens(i, s[i][j]);
        print_optimal_parens(s[i][j] + 1, j);
        printf(")");
    }
}

int MatrixChainOrderRecursive (int p[], int i, int j) 
{
    if (i == j)
        return 0;

    int k;
    int min = INT_MAX;
    int count;

    // Coloca parênteses em diferentes lugares entre as matrizes,
    // recursivamente e verifica o número mínimo de multiplicações
    for (k = i; k < j; k++) {
        count = MatrixChainOrderRecursive(p, i, k) +
                MatrixChainOrderRecursive(p, k + 1, j) +
                p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }

    return min;
}

// Função auxiliar para inicializar a matriz de memorização
void initialize () 
{
    memset(m, -1, sizeof(m));
}

// Função de programação dinâmica top-down para calcular o número mínimo de multiplicações
int MatrixChainOrderTopDown (int p[], int i, int j) 
{
    if (i == j)
        return 0;

    if (m[i][j] != -1)
        return m[i][j];

    m[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        m[i][j] = fmin(m[i][j],
                       MatrixChainOrderTopDown(p, i, k) +
                       MatrixChainOrderTopDown(p, k + 1, j) +
                       p[i - 1] * p[k] * p[j]);
    }

    return m[i][j];
}

// Exercício 14

int memo[100][100];

int scm_recursivo (const char *X, const char *Y, int m, int n) 
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + scm_recursivo(X, Y, m - 1, n - 1);
    else
        return fmax(scm_recursivo(X, Y, m, n - 1), scm_recursivo(X, Y, m - 1, n));
}

int scm_top_down (const char *X, const char *Y, int m, int n) 
{
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

int scm_bottom_up (const char *X, const char *Y) 
{
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

int cutRodRecursiva (int precos[], int n) 
{
    if (n <= 0)
        return 0;
    int max_val = -1;

    for (int i = 0; i < n; i++)
        max_val = max(max_val, precos[i] + cutRodRecursiva(precos, n - i - 1));

    return max_val;
}

int cutRodBottomUp (int precos[], int n) 
{
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

int cutRodTopDown (int precos[], int n, int memo[]) 
{
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
    printf("=====================12=====================\n");

    // Definindo os valores e pesos dos itens
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50; // Capacidade da mochila
    int n_12 = sizeof(val) / sizeof(val[0]); // Número de itens

    // Testando a versão recursiva
    printf("Valor máximo (Recursiva): %d\n", knapsack(W, wt, val, n_12));

    // Testando a versão top-down de programação dinâmica
    printf("Valor máximo (Top-Down): %d\n", knapsack_top_down(W, wt, val, n_12));

    // Testando a versão bottom-up de programação dinâmica
    printf("Valor máximo (Bottom-Up): %d\n", knapsack_bottom_up(W, wt, val, n_12));
    

    printf("=====================13=====================\n");

    int p[] = {200, 2, 30, 20, 5};
    int n = sizeof(p)/sizeof(p[0]);

    matrix_chain_order(p, n);
    printf("Número mínimo de operações: %d\n", m[1][n - 1]);
    printf("Parentização ótima: ");
    print_optimal_parens(1, n - 1); printf("\n");

    int arr[] = {200, 2, 30, 20, 5};
    printf("Número mínimo de operações: %d\n",
           MatrixChainOrderRecursive(arr, 1, n - 1));
    printf("Parentização ótima: ");
    print_optimal_parens(1, n - 1); printf("\n");

    printf("Número mínimo de operações: %d\n",
           MatrixChainOrderTopDown(arr, 1, n - 1));
    printf("Parentização ótima: ");
    print_optimal_parens(1, n - 1); printf("\n");

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
