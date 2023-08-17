#include <stdio.h>

// Fatorial recursivo:
float fatorial(int n){
    if (n >= 1) {
        return n * fatorial(n - 1);
    } else {
        return 1;
    }
}

// Exercício 01
int produto(int a, int b){
    if (b == 1){
        return a;
    }else{
        return produto(a, (b - 1)) + a;
    }
}

// Exercício 02
int somaImpares(int n){
    if(n == 1){
        return 1;
    }else{
        return (2 * n - 1) + somaImpares(n - 1);
    }
}

// Exercício 03
float xToTheNth(int x, int n){
    if (n == 0) {
        return 1;
    } else {
        return x * xToTheNth(x, n - 1);
    }
}

// Exercício 04
float quartaQuestao(float x, float n) {
    if (n == 0) {
        return 1;
    } else {
        return xToTheNth(x, n)/fatorial(n) + quartaQuestao(x, n - 1);
    }
}

// Exercícios 05

void swap(int *v, int start, int end) {
    int temp;
    temp = v[start];
    v[start] = v[end];
    v[end] = temp;
}

void inverteVetor(int *v, int start, int end) {
    if (start >= end){
        return;
    } else {
        swap(v, start, end);
        inverteVetor(v, start + 1, end - 1);
    }
}

int main(void) {
    printf("%.0f\n", fatorial(5));
    printf("%d\n", produto(8, 12));
    printf("%d\n", somaImpares(4));
    printf("%.0f\n", xToTheNth(5, 4));
    printf("%.4f\n", quartaQuestao(5, 4));

    int v[6] = {1, 5, 2, 7, 6, 4};
    int len = 6;
    inverteVetor(v, 0, len - 1);
    for(int i = 0; i < len; i++){
        printf("%d, ", v[i]);
    }
    printf("\n");

    return 0;
}