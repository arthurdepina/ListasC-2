#include <stdio.h>
#include <stdbool.h>

void seg_consec(int *a, int len_a){
    bool iguais = false;
    int tamanho = 0;
    int dist = 0;
    for (int current = 0; current < len_a; current++){
        for (int i = current + 1; i < len_a; i++){
            if (a[i] == a[current]) {
                dist = i - current;
                for (int j = current; j < i; j++){
                    if (a[j] != a[dist + j]) { iguais = false; break; }
                    else iguais = true; tamanho++;
                }
                if (!iguais) continue;
                if (iguais)
                    printf("i = %d | m = %d\n", current + 1, tamanho); break;
            }
            if (iguais) break;
        }
        if (iguais) break;
    }
    if (!iguais) printf("Sem segmentos consecutivos.\n");
}

int main () {
    printf("====== 01 ======\n");
    printf("a) ");
    int a[] = {7, 9, 5, 4, 5, 4, 8, 6};
    int size_a = sizeof(a) /  sizeof(a[0]);
    seg_consec(a, size_a);
    printf("b) ");
    int b[] = {7, 9, 5, 4, 8, 5, 4, 8, 6};
    int size_b = sizeof(b) /  sizeof(b[0]);
    seg_consec(b, size_b);
    printf("c) ");
    int c[] = {0, 1, 2, 0, 1, 2, 6};
    int size_c = sizeof(c) / sizeof(c[0]);
    seg_consec(c, size_c);
    printf("d) ");
    int d[] = {2, 2, 3, 5, 6};
    int size_d = sizeof(d) / sizeof(d[0]);
    seg_consec(d, size_d);
    printf("e) ");
    int e[] = {2, 3, 5, 2, 3, 6};
    int size_e = sizeof(e) / sizeof(e[0]);
    seg_consec(e, size_e);
    return 0;
}
