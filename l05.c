#include <stdio.h>

void n_binario(char *bin, int n, int atual){
    if (atual == n) {
        bin[atual]  =  '\0';
        printf("%s\n", bin);
        return;
    }
    
    bin[atual] = '0';
    n_binario(bin, n, atual+1);

    bin[atual] = '1';
    n_binario(bin, n, atual+1);
}

void abba(char *resultado, int m, int n, int count_m, int count_n ){
    if (count_m == m && count_n == n) {
        resultado[count_m + count_n] = '\0';
        printf("%s\n", resultado);
        return;
    }
    
    if (count_m < m) {
        resultado[count_m + count_n] = 'A';
        abba(resultado, m, n, count_m + 1, count_n);
    }

    if (count_n <  n) {
        resultado[count_m + count_n] = 'B';
        abba(resultado, m, n, count_m, count_n + 1);
    }
}

int main() {
    printf("====== 01 ======\n");
    int tam_str = 4;
    printf("Exemplo, n = %d:\n", tam_str - 1);
    char str[tam_str + 1];
    n_binario(str, tam_str, 0);

    printf("====== 02 ======\n");
    int m = 3;                  // Gols de A
    int n = 3;                  // Gols de B
    int tam_placar = m + n;
    char placar[tam_placar + 1];
    abba(placar, m, n,  0, 0);

    printf("====== 03 ======\n");


    return 0;
}








