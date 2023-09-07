#include <stdio.h>

void n_binario(char *bin, int n, int atual){
    if (atual == n) {
        bin[atual] = '\0';
        printf("%s\n", bin);
        return;
    }
    
    bin[atual] = '0';
    n_binario(bin, n, atual+1);

    bin[atual] = '1';
    n_binario(bin, n, atual+1);
}

int main() {
    printf("====== 01 ======\n");
    printf("Exemplo, n = 3:\n");
    int tam_str = 4;
    char str[tam_str + 1];
    n_binario(str, tam_str, 0);

    printf("====== 02 ======\n");
    

    return 0;
}
