#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "useful.c"

void tres_digitos(int a, int b, int c) {
    int array [3] = {a, b, c};
    for (int i = 0; i < 3; i++) {
        printf("\n");
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                if (j == 0 && k == 0) {
                    printf("| %d %d %d |", array[i], array[j], array[k]);
                }
                printf(" %d %d %d |", array[i], array[j], array[k]);
            }
        }
    }
}

int main () {
    tres_digitos(1, 2, 3);
    return 0;
}
