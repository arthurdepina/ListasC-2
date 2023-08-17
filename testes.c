#include <stdio.h>

// Fatorial recursivo:
float fatorial(int n){
    if (n >= 1) {
        return n * fatorial(n - 1);
    } else {
        return 1;
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
    } else if (n == 1) {
        return x + quartaQuestao(x, n - 1);
    } else {
        return xToTheNth(x, n)/fatorial(n) + quartaQuestao(x, n - 1);
    }
}

int main(void) {
    printf("%f\n", quartaQuestao(5, 4));
    return 0;
}