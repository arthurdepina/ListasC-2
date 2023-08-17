#include <stdio.h>

void swap(int *v, int len, int totalLen) {
    int temp, a;
    a = totalLen - len;
    temp = v[a];
    v[a] = v[totalLen - a - 1];
    v[len - 1] = temp;
}

int* inverteVetor(int *v, int len, int totalLen) {
    if (len <= 1) { 
        return v;
    } else {
        swap(v, len, totalLen);
        return inverteVetor(v, len - 1, totalLen);
    }
}

int main(void) {
    int v[6] = {1, 5, 2, 7, 6, 4};
    int len = 6;
    inverteVetor(v, len, len);
    for(int i = 0; i < len; i++){
        printf("%d, ", v[i]);
    }
    printf("\n");

    return 0;
}