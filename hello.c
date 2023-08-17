#include <stdio.h>

void swap(int *v, int a, int totalLen) {
    int temp;
    temp = v[a];
    v[a] = v[totalLen - a - 1];
    v[totalLen - a - 1] = temp;
}

int* inverteVetor(int *v, int len, int totalLen) {
    if (len <= totalLen / 2) { 
        return v;
    } else {
        swap(v, totalLen - len, totalLen);
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
