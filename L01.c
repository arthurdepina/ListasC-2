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

//Exercício 06
int maiorEntreXY(int x, int y){
    if (x >= y){ return x; } else {return y; }
}

int encontraMaior(int *v, int n){
    if (n == 0) { return v[0]; }
    return maiorEntreXY(v[n], encontraMaior(v, n - 1));
}

// Exercício 07
int repeteNemX(int n, int x){
    if (x == 0) {
        return 0;
    }
    if (x%10 == n) return 1 + repeteNemX(n, x/10);
    return 0 + repeteNemX(n, x/10);
}

/*
Solução do professor:
int conta_ocorrencia(int n, int k){
  if (n == 0) return 0;
  return conta_ocorrencia(n/10, k) + (n%10 == k);
}
int main(void) {
  printf("número de ocorrencias: %d\n", conta_ocorrencia(201920267, 2));
  printf("número de ocorrencias: %d\n", conta_ocorrencia(55555054, 5));

  return 0;
}
*/

// Exercício 08
int polinomio(int x, int n, int c[]){
  if (n == 0) return c[0];
  return polinomio(x, n-1, c) * x + c[n];
}

int main(void) {
    printf("Fatorial: %.0f\n", fatorial(5));
    printf("Exercício 01: %d\n", produto(8, 12));
    printf("Exercício 02: %d\n", somaImpares(4));
    printf("Exercício 03: %.0f\n", xToTheNth(5, 4));
    printf("Exercício 04: %.4f\n", quartaQuestao(5, 4));

    int v[6] = {1, 5, 2, 7, 6, 4};
    int len = 6;
    inverteVetor(v, 0, len - 1);
    printf("Exercício 05: ");
    for(int i = 0; i < len; i++){
        if (i == len - 1){
            printf("%d", v[i]);
        } else {
            printf("%d, ", v[i]);
        }
    }
    printf("\n");

    printf("Exercício 06: %d\n", encontraMaior(v, len - 1));
    printf("Exercício 07: %d\n", repeteNemX(5, 554055));

    printf("Exercício 08:\n");
    int c[4] = {3, 5, 3, 2};
    int x = 10;
    int n = 3;
    printf("P(x = %d, n = %d) = %d\n", x, n, polinomio(x, n, c));
    printf("Coeficientes: [%d, %d, %d, %d]\n", c[0], c[1], c[2], c[3]);
    return 0;
}