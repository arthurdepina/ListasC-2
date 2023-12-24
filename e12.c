#include <stdio.h>
#include <stdbool.h>

int soma_vetor(int *vetor, int len)
{
    int soma = 0;
    for (int i = 0; i < len; i++) {
        soma = soma + vetor[i];
    }
    return soma;
}

bool testa_quadrados(int *palitos, int n, int lados[], int lado_quadrado, int count)
{
    if (count == n) {
        return lados[0] == lado_quadrado &&
               lados[1] == lado_quadrado &&
               lados[2] == lado_quadrado &&
               lados[3] == lado_quadrado;
    }

    for (int i = 0; i < 4; i++) {
       if (lados[i] + palitos[count] > lado_quadrado) continue;
        lados[i] += palitos[count];
        if (testa_quadrados(palitos, n, lados, lado_quadrado, count + 1)) return true;
        lados[i] -= palitos[count];
    }
    return false;
}

bool quadrado_palito(int *palitos, int len_palitos)
{
    int lados[4] = {0, 0, 0, 0};
    int soma_palitos = soma_vetor(palitos, len_palitos);
    if (soma_palitos % 4 != 0) return false;
    int lado_quadrado = soma_palitos / 4;
    return testa_quadrados(palitos, len_palitos, lados, lado_quadrado, 0);
}

int main()
{
    int palitos[] = {9, 8, 7, 6, 4, 3, 2, 1};
    int len_palitos = sizeof(palitos) / sizeof(palitos[0]);
    if (quadrado_palito(palitos, len_palitos)) printf("Possible");
    else printf("Impossible");
    return 0;
}
