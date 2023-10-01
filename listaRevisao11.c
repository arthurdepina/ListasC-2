#include <stdio.h>
#include <stdbool.h>

void exibir_vetor(int *v, int len)
{
	for (int i = 0; i < len; i++){
		if (i == 0) printf("[");
		if (i == len - 1) printf("%d]", v[i]);
		else printf("%d, ", v[i]);
	}
}

void troca(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

bool ordena_rec(int *vetor, int inicio, int n)
{
    if (inicio == n) {
        bool em_ordem = true;
        for (int i = 0; i < n - 1; i++){
            if (vetor[i] > vetor[i+1]) em_ordem = false;
        }
        return em_ordem;
    }
    for (int i = inicio; i < n; i++) {
        troca(&vetor[inicio], &vetor[i]);
        if (ordena_rec(vetor, inicio + 1, n)) return true;
        troca(&vetor[inicio], &vetor[i]);
    }
    return false;
}

int main()
{
    int array_sort[] = {3, 1, 4, 1, 5, 9, 2};
    int len_array_sort = sizeof(array_sort) / sizeof(array_sort[0]);
    printf("Vetor original: ");
    exibir_vetor(array_sort, len_array_sort); printf("\n");
    ordena_rec(array_sort, 0, len_array_sort);
    printf("Vetor ordenado: ");
    exibir_vetor(array_sort, len_array_sort); printf("\n");
    return 0;
}
