#include <stdio.h>
#include <string.h>

void printBinary(int n, char *str, int index) {
    // Caso base: se o índice for igual a n, imprima a string e retorne
    if (index == n) {
        str[index] = '\0';  // Finalize a string
        printf("%s\n", str);
        return;
    }

    // Adicione '0' na posição atual e faça uma chamada recursiva para o próximo índice
    str[index] = '0';
    printBinary(n, str, index + 1);

    // Adicione '1' na posição atual e faça uma chamada recursiva para o próximo índice
    str[index] = '1';
    printBinary(n, str, index + 1);
}

int main() {
    int n = 3;
    char str[n + 1];  // +1 para o caractere nulo no final

    printBinary(n, str, 0);

    return 0;
}
