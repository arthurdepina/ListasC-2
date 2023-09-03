#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "useful.c"

int * junta_ordenadas(int *a, int *b, int len_a, int len_b){
    int contador_a = 0, contador_b = 0;
    int len = len_a + len_b;
    int *seq = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++){
        if (a[contador_a] < b[contador_b]) {
            seq[i] = a[contador_a]; contador_a++;
        } else {
            seq[i] = b[contador_b]; contador_b++;
        }
    }
    return seq;
}

int main () {
    int g[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int h[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int m = sizeof(g) / sizeof(g[0]);
    int n = sizeof(h) / sizeof(h[0]);
    int *array; int len_array = m + n;
    array = junta_ordenadas(g, h, m, n);
    exibir_vetor(array, len_array);
    return 0;
}
