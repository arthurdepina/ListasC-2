#include <stdio.h>

void tres_digitos(int a, int b, int c) {
    int array[3];
    int size = 0;

    if (a != b && b != c && c != a) {
        array[0] = a;
        array[1] = b;
        array[2] = c;
        size = 3;
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

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                if (size == 3) {
                    printf("| %d %d %d |", array[i], array[j], array[k]);
                    if (k != size - 1) printf(" ");
                } else if (size == 2 && k == 0) {
                    printf("| %d %d |", array[i], array[j]);
                    if (j != size - 1) printf(" ");
                }
            }
            if (size == 3) printf("\n");
        }
        if (size == 2) printf("\n");
    }
}

int main() {
    tres_digitos(1, 2, 3);
    printf("\n");
    tres_digitos(1, 1, 3);
    return 0;
}
