#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int max_elegante(int *vetor, int len, int count)
{
    if (count == len) {
        int soma = 0;
        for (int i = 0; i < len - 1; i++) {
            soma += abs(vetor[i] - vetor[i + 1]);
        }
        return soma;
    }

    int soma_maxima = 0;
    for (int i = count; i < len; i++) {
        troca(&vetor[i], &vetor[count]);

        int soma = max_elegante(vetor, len, count + 1);

        troca(&vetor[i], &vetor[count]);

        if (soma > soma_maxima) soma_maxima = soma;
    }
    return soma_maxima;
}

int main()
{
    int array_permut[] = {4, 2, 1, 5};
    int len_permut = sizeof(array_permut) / sizeof(array_permut[0]);
    int permut_maxima = max_elegante(array_permut, len_permut, 0);
    printf("Soma permutada elegante = %d\n", permut_maxima);

    return 0;
}
