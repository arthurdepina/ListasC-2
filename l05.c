#include <stdio.h>
#include <math.h>

int converte_p_binario(int n){
    int bin = 0;
    int i = 1;
    int resto;
    while (n != 0){
        resto = n % 2;
        printf("%d\n", resto);
        n /= 2;

    }
}

void n_binario(int n, int atual){
    int a = pow(n, 2);
    if (a == atual) { printf("0\n"); return; }
    if (atual != 1) printf("%d\n", a - atual);
    n_binario(n, atual+1);
}
    
int main() {
    n_binario(3, 1);
    printf("\n");
    // n_binario(4, 0);
    return 0;
}
