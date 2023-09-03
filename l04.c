#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void exibir_vetor(int *v, int len){
	for (int i = 0; i < len; i++){
		if (i == 0) printf("[");
		if (i == len - 1) printf("%d]", v[i]);
		else printf("%d, ", v[i]);
	}
}

void seg_consec(int *a, int len_a){
    /*
     * Procura dois números iguais e calcula a distância (d)
     * entre eles. Em seguida, itera entre os dois números e
     * a partir do segundo por d elementos. Se não encontra
     * nenhum número diferente, essas sequências são segmentos
     * consecutivos. Complexidade O(n^2) (?)
    */
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
                if (iguais) {
                    printf("i = %d | m = %d\n", current + 1, tamanho);
                    break;
                }
            }
            if (iguais) break;
        }
        if (iguais) break;
    }
    if (!iguais) printf("Sem segmentos consecutivos.\n");
}

int max_soma_seg(int *s, int len_s){
    int max = s[0];
    int current_sum = 0;
    for (int i = 0; i < len_s; i++){
        current_sum = s[i];
        if (current_sum > max) max = current_sum;
        for (int j = i + 1; j < len_s; j++){
            current_sum = current_sum + s[j];
            if (current_sum > max) max = current_sum;
        }
    }
    return max;
}

int * junta_ordenadas(int *a, int *b, int len_a, int len_b){
    int contador_a = 0, contador_b = 0;
    int len = len_a + len_b;
    int *seq = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        if ((a[contador_a] < b[contador_b] || contador_b == len_b) && contador_a != len_a) {
            seq[i] = a[contador_a]; contador_a++;
        } else {
            seq[i] = b[contador_b]; contador_b++;
        }
    }
    return seq;
}

void tres_digitos(int a, int b, int c) {
    int array [3] = {a, b, c};
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

int main () {
    printf("====== 01 ======\n");
    printf("a) ");
    int a[] = {7, 9, 5, 4, 5, 4, 8, 6};
    int size_a = sizeof(a) /  sizeof(a[0]);
    seg_consec(a, size_a);
    /* Alguns testes
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
    */
    
    printf("==== 02 ====\n");
    int f[] = {5, 2, -2, -7, 3, 14, 10, -3, 9, -6, 4, 1};
    int size_f = sizeof(f) / sizeof(f[0]);
    printf("%d\n", max_soma_seg(f, size_f));
    
    printf("==== 03 ====\n");
    int g[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int h[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int m = sizeof(g) / sizeof(g[0]);
    int n = sizeof(h) / sizeof(h[0]);
    int *array; int len_array = m + n;
    array = junta_ordenadas(g, h, m, n);
    exibir_vetor(array, len_array); printf("\n");
    int p[] = {18, 19};
    int q[] = {3, 6, 7, 9, 11, 14, 15, 16};
    int len_p = sizeof(p) / sizeof(p[0]);
    int len_q = sizeof(q) / sizeof(q[0]);
    int *array2; int len_array2 = len_p + len_q;
    array2 = junta_ordenadas(p, q, len_p, len_q);
    exibir_vetor(array2, len_array2); printf("\n");

    printf("==== 04 ====\n");
    tres_digitos(1, 2, 3);

    return 0;
}
