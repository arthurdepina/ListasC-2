#include <stdio.h>

// Fatorial recursivo:
float fatorial(int n){
    if (n >= 1) {
        return n * fatorial(n - 1);
    } else {
        return 1;
    }
}

int produto(int a, int b){
    if (b == 1){
        return a;
    }else{
        return produto(a, (b - 1)) + a;
    }
}

int somaImpares(int n){
    if(n == 1){
        return 1;
    }else{
        return (2 * n - 1) + somaImpares(n - 1);
    }
}

float xToTheNth(int x, int n){
    if (n == 0) {
        return 1;
    } else {
        return x * xToTheNth(x, n - 1);
    }
}

float quartaQuestao(float x, float n) {
    if (n == 0) {
        return 1;
    } else {
        return xToTheNth(x, n)/fatorial(n) + quartaQuestao(x, n - 1);
    }
}

int main(void) {
    printf("%.0f\n", fatorial(5));
    printf("%d\n", produto(8, 12));
    printf("%d\n", somaImpares(4));
    printf("%.0f\n", xToTheNth(5, 4));
    printf("%.4f\n", quartaQuestao(5, 4));
    return 0;
}