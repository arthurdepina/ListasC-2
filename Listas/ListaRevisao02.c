/*
*                                 Lista de Exercícios do 2o Bimestre
*                
*                              Arthur de Pina Balduino Leitão  32207840
*                              João Victor Dallapé Madeira     32209592           
*                                                          
*                 github.com/arthurdepina/ListasC-2/blob/main/Listas/ListaRevisao02.c
*                            replit.com/@arthurdepina/ListaRevisao02#main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MAX 100

/* 
*                 Os exercícios 1 - 10 estão no Github e Replit disponibilizados acima.
*                          replit.com/@arthurdepina/ListaRevisao02#main.c              
*/

int max(int a, int b) { return (a > b) ? a : b; }

// Exercício 03

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int find_max_files_to_copy(int sizes[], int n, int c) {
    qsort(sizes, n, sizeof(int), compare);
    
    int count = 0;
    int total_size = 0;
    
    for (int i = 0; i < n; i++) {
        if (total_size + sizes[i] <= c) {
            total_size += sizes[i];
            count++;
        } else {
            break;
        }
    }
    
    return count;
}

// Exercício 04

int minStops(int d[], int n, int m) {
    int numStops = 0, currentPos = 0, lastStop = 0, i;

    while (currentPos < n - 1) {
        lastStop = currentPos;

        // Procura pelo posto mais distante dentro do alcance
        while (currentPos < n - 1 && d[currentPos + 1] - d[lastStop] <= m) {
            currentPos++;
        }

        // Se não foi possível avançar, não é possível completar a viagem
        if (currentPos == lastStop) {
            return -1;
        }

        // Se ainda não estamos no destino, conta mais uma parada
        if (currentPos < n - 1) {
            numStops++;
        }
    }

    return numStops;
}

// Exercício 05

typedef struct {
    int value;
    int weight;
} Item;

int cmp(const void *a, const void *b) {
    double r1 = (double)((Item *)a)->value / ((Item *)a)->weight;
    double r2 = (double)((Item *)b)->value / ((Item *)b)->weight;
    return r1 < r2 ? 1 : -1;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    qsort(arr, n, sizeof(Item), cmp);
    
    int curWeight = 0;
    double finalvalue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        } else {
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }
    
    return finalvalue;
}

// Exercício 06

typedef struct {
    int calorias;
    int proteinas;
} Alimento;

void calcularDieta(int K, Alimento alimentos[], int n) {
    int i, j;
    // Criar e inicializar a matriz de programação dinâmica
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((K + 1) * sizeof(int));
        for (j = 0; j <= K; j++) {
            dp[i][j] = 0;
        }
    }

    // Preencher a matriz dp
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= K; j++) {
            if (alimentos[i - 1].calorias <= j) {
                dp[i][j] = dp[i - 1][j] > dp[i - 1][j - alimentos[i - 1].calorias] + alimentos[i - 1].proteinas
                           ? dp[i - 1][j]
                           : dp[i - 1][j - alimentos[i - 1].calorias] + alimentos[i - 1].proteinas;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Exibir o resultado
    printf("Quantidade máxima de proteínas: %d\n", dp[n][K]);

    // Liberar a memória
    for (i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
}

// Exercício 07

typedef struct {
    int inicio;
    int fim;
} Atividade;

int comparaAtividades(const void *a, const void *b) {
    Atividade *atividadeA = (Atividade *)a;
    Atividade *atividadeB = (Atividade *)b;
    return atividadeA->fim - atividadeB->fim;
}

void seleciona_atividades_guloso(Atividade atividades[], int n) {
    // Ordena as atividades por tempo de término
    qsort(atividades, n, sizeof(Atividade), comparaAtividades);

    printf("Atividades selecionadas: \n");

    // A primeira atividade sempre é selecionada
    int i = 0;
    printf("(%d, %d)\n", atividades[i].inicio, atividades[i].fim);

    // Percorre as atividades restantes
    for (int j = 1; j < n; j++) {
        if (atividades[j].inicio >= atividades[i].fim) {
            printf("(%d, %d)\n", atividades[j].inicio, atividades[j].fim);
            i = j;
        }
    }
}

// Exercício 08

int countWays(int n) {
    // Se n for 0 ou 1, existe apenas uma maneira de subir
    if (n == 0 || n == 1) return 1;
    
    // Se n for 2, existem duas maneiras: (1, 1) ou (2)
    if (n == 2) return 2;

    // Inicializa os dois primeiros valores
    int one_step_before = 2; // maneiras de subir (n-1) degraus
    int two_steps_before = 1; // maneiras de subir (n-2) degraus
    int all_ways = 0;

    // Calcula o número de maneiras para os degraus restantes
    for (int i = 3; i <= n; i++) {
        all_ways = one_step_before + two_steps_before;
        two_steps_before = one_step_before;
        one_step_before = all_ways;
    }

    return all_ways;
}

// Exercício 09

int minQuadrados(int n) {
    // Se n for 0, não precisamos de nenhum número
    if (n <= 0) {
        return 0;
    }

    // Cria um vetor para armazenar o mínimo de quadrados para cada número até n
    int dp[n + 1];

    // Inicializa o vetor com o máximo valor possível
    for (int i = 0; i <= n; i++) {
        dp[i] = INT_MAX;
    }

    // Base case: 0 pode ser representado por 0 quadrados
    dp[0] = 0;

    // Preenche o vetor com a quantidade mínima de quadrados para cada número até n
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = (dp[i] > dp[i - j * j] + 1) ? dp[i - j * j] + 1 : dp[i];
        }
    }

    // Retorna a quantidade mínima de quadrados para n
    return dp[n];
}

// Exercício 10

                    // Subsequencia crescente mais longa - recursiva
int lis_backtracking(int arr[], int n, int prev, int curr) {
    if (curr == n) {
        return 0;
    }

    int taken = 0;
    if (arr[curr] > prev) {
        taken = 1 + lis_backtracking(arr, n, arr[curr], curr + 1);
    }

    int not_taken = lis_backtracking(arr, n, prev, curr + 1);

    return max(taken, not_taken);
}

                    // Subsequencia crescente mais longa - top-down
int lis_top_down(int arr[], int n, int prev_index, int curr, int dp[MAX][MAX]) {
    if (curr == n) {
        return 0;
    }

    if (dp[prev_index + 1][curr] >= 0) {
        return dp[prev_index + 1][curr];
    }

    int taken = 0;
    if (prev_index < 0 || arr[curr] > arr[prev_index]) {
        taken = 1 + lis_top_down(arr, n, curr, curr + 1, dp);
    }

    int not_taken = lis_top_down(arr, n, prev_index, curr + 1, dp);

    dp[prev_index + 1][curr] = max(taken, not_taken);
    return dp[prev_index + 1][curr];
}

                    // Subsequencia crescente mais longa - bottom-up
int lis_bottom_up(int arr[], int n) {
    int dp[MAX], i, j, maxLIS = 0;

    for (i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    for (i = 0; i < n; i++) {
        maxLIS = max(maxLIS, dp[i]);
    }

    return maxLIS;
}

// Exercício 11

                    // Versão backtracking
int minCoinsRec(int coins[], int n, int V) {
    if (V == 0) return 0;

    int res = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (coins[i] <= V) {
            int sub_res = minCoinsRec(coins, n, V - coins[i]);

            if (sub_res != INT_MAX && sub_res + 1 < res)
                res = sub_res + 1;
        }
    }
    return res;
}

                    // Versão top-down
int minCoinsTopDown(int coins[], int n, int V, int dp[]) {
    if (V == 0) return 0;

    if (dp[V] != -1) return dp[V];

    int res = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (coins[i] <= V) {
            int sub_res = minCoinsTopDown(coins, n, V - coins[i], dp);

            if (sub_res != INT_MAX && sub_res + 1 < res)
                res = sub_res + 1;
        }
    }

    dp[V] = res;
    return res;
}

                    // Versão bottom-up
int minCoinsBottomUp(int coins[], int n, int V) {
    int dp[V+1];

    dp[0] = 0;

    for (int i = 1; i <= V; i++)
        dp[i] = INT_MAX;

    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < n; j++)
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i])
                    dp[i] = sub_res + 1;
            }
    }

    return dp[V];
}

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
    printf("=====================02=====================\n");



    printf("=====================03=====================\n");

    int files_sizes[] = {4, 2, 3, 1, 5};
    int n_03 = sizeof(files_sizes)/sizeof(files_sizes[0]);
    int pendrive_capacity = 10;
    
    int max_files = find_max_files_to_copy(files_sizes, n_03, pendrive_capacity);
    printf("Max: %d\n", max_files);

    printf("=====================04=====================\n");

    int m_04 = 200; // Distância máxima que o carro pode percorrer com um tanque
    int d_04[] = {0, 100, 200, 300, 400, 500, 600}; // Distâncias dos postos de combustível
    int n_04 = sizeof(d_04) / sizeof(d_04[0]); // Número de postos

    int result = minStops(d_04, n_04, m_04);

    if (result >= 0) {
        printf("Número mínimo de paradas: %d\n", result);
    } else {
        printf("Não é possível completar a viagem com as paradas disponíveis.\n");
    }

    printf("=====================05=====================\n");

    Item arr_05[] = {{120, 10}, {100, 20}, {60, 30}};
    
    // Knapsack capacity
    int W_05 = 50;
    int n_05 = sizeof(arr_05) / sizeof(arr_05[0]);
    
    // Function call
    printf("Max = %.2f\n", 
                        fractionalKnapsack(W_05, arr_05, n_05));

    printf("=====================06=====================\n");

    int K_06, n_06, i_06;

    K_06 = 500;
    n_06 = 4;

    Alimento alimentos[4] = {
                             {100, 20},
                             {200, 40},
                             {150, 30},
                             {50, 10}
    };

    calcularDieta(K_06, alimentos, n_06);

    printf("=====================07=====================\n");

    Atividade atividades[] = {
                              {5, 9}, 
                              {1, 2}, 
                              {3, 4}, 
                              {0, 6}, 
                              {5, 7}, 
                              {8, 9}
    };
    int n_07 = sizeof(atividades) / sizeof(atividades[0]);
    seleciona_atividades_guloso(atividades, n_07);

    printf("=====================08=====================\n");

    int n_08 = 2;
    printf("Número de maneiras de subir a escada: %d\n", countWays(n_08));

    printf("=====================09=====================\n");

    int n_09 = 12;
    printf("Menor quantidade de números quadrados perfeitos que somam %d: %d\n", n_09, minQuadrados(n_09));

    printf("=====================10=====================\n");

    int arr_10[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n_10 = sizeof(arr_10)/sizeof(arr_10[0]);
    int dp_10[MAX][MAX];
    memset(dp_10, -1, sizeof(dp_10));
    printf("Comprimento: %d\n", lis_backtracking(arr_10, n_10, -1, 0));
    printf("Comprimento: %d\n", lis_top_down(arr_10, n_10, -1, 0, dp_10));
    printf("Comprimento: %d\n", lis_bottom_up(arr_10, n_10));

    printf("=====================11=====================\n");

    int coins[] = {1, 5, 10, 25};  // Exemplo de conjunto de moedas
    int m_11 = sizeof(coins) / sizeof(coins[0]);
    int V = 30;  // Exemplo de valor do troco
    int dp[V+1];
    printf("Mínimo de moedas necessárias: %d\n", minCoinsRec(coins, m_11, V));
    memset(dp, -1, sizeof(dp));
    printf("Mínimo de moedas necessárias: %d\n", minCoinsTopDown(coins, m_11, V, dp));
    printf("Mínimo de moedas necessárias: %d\n", minCoinsBottomUp(coins, m_11, V));

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
