#include <stdbool.h>
#include <stdio.h>

bool backtrack(int *palitos, int n, int lados[4], int lado_alvo, int idx) {
    if (idx == n) {
        return lados[0] == lado_alvo && lados[1] == lado_alvo && lados[2] == lado_alvo && lados[3] == lado_alvo;
    }

    for (int i = 0; i < 4; i++) {
        if (lados[i] + palitos[idx] > lado_alvo) continue;

        lados[i] += palitos[idx];
        if (backtrack(palitos, n, lados, lado_alvo, idx + 1)) return true;
        lados[i] -= palitos[idx];
    }

    return false;
}

bool pode_formar_quadrado(int *palitos, int n) {
    if (n < 4) return false;

    int soma = 0;
    for (int i = 0; i < n; i++) soma += palitos[i];

    if (soma % 4 != 0) return false;

    int lados[4] = {0, 0, 0, 0};
    return backtrack(palitos, n, lados, soma / 4, 0);
}

int main() {
    int palitos[] = {9, 8, 7, 6, 4, 3, 2, 1};
    int n = sizeof(palitos) / sizeof(palitos[0]);

    if (pode_formar_quadrado(palitos, n)) {
        printf("Pode formar um quadrado.\n");
    } else {
        printf("Não pode formar um quadrado.\n");
    }

    return 0;
}
