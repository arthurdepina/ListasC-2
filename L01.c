#include <stdio.h>

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

int xToTheNth(int x, int n){
    if (n == 0) {
        return 1;
    } else {
        return x * xToTheNth(x, n - 1);
    }
}

int main(void) {
    int output = 0;
    printf("%d\n", produto(8, 12));
    printf("%d\n", somaImpares(4));
    printf("%d\n", xToTheNth(5, 4));
    return 0;
}