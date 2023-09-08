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

void abba(char *resultado, int m, int n){
    resultado++;
    
}

int main() {
    printf("====== 01 ======\n");
    int tam_str = 4;
    printf("Exemplo, n = %d:\n", tam_str - 1);
    char str[tam_str + 1];
    n_binario(str, tam_str, 0);

    printf("====== 02 ======\n");
    

    return 0;
}
