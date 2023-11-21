#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int cutRodRecursiva(int precos[], int n) {
    if (n <= 0)
        return 0;
    int max_val = -1;

    for (int i = 0; i < n; i++)
        max_val = max(max_val, precos[i] + cutRodRecursiva(precos, n - i - 1));

    return max_val;
}

int main() {
    int precos[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int tamanho = sizeof(precos)/sizeof(precos[0]);
    printf("Receita máxima: %d\n", cutRodRecursiva(precos, tamanho));
    return 0;
}
