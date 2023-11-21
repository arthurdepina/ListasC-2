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
#include <math.h>

// Exercício 14


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
    int precos[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int tamanho = sizeof(precos)/sizeof(precos[0]);
    int memo[tamanho + 1];

    for (int i = 0; i <= tamanho; i++)
        memo[i] = -1;

    printf("Receita máxima: %d\n", cutRodRecursiva(precos, tamanho));
    printf("Receita máxima: %d\n", cutRodTopDown(precos, tamanho, memo));
    printf("Receita máxima: %d\n", cutRodBottomUp(precos, tamanho));

    return 0;
}
