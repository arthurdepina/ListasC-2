#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void tres_digitos(int a, int b, int c) {
    int array[3];
    int size = 0;

    if (a != b && b != c && c != a) {
        array[0] = a;
        array[1] = b;
        array[2] = c;
        size = 3;
    } else if (a == b && b == c) {
        printf("| %d %d %d |", a, a, a);
        return;
    } else if (a == b) {
        array[0] = a;
        array[1] = c;
        size = 2;
    } else if (b == c) {
        array[0] = a;
        array[1] = b;
        size = 2;
    } else if (a == c) {
        array[0] = a;
        array[1] = b;
        size = 2;
    }

    if (size == 3){
        for (int i = 0; i < 3; i++) {
            if (i != 0) printf("\n");
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
    if (size == 2){
        for (int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++){
                
            }
        }
    }
}

int main () {
    tres_digitos(1, 2, 3); printf("\n");
    tres_digitos(1, 2, 2); printf("\n");
    tres_digitos(1, 1, 2); printf("\n");
    tres_digitos(1, 2, 1); printf("\n");
    tres_digitos(1, 1, 1); printf("\n");

    return 0;
}
