#include <stdio.h>
#include <stdbool.h>

bool verifica_se_menor(int *r, int *s, int len_a, int len_b){
        for (int i = 0; i < len_a; i++){
                if (r[i] > s[i]) return false;
                if (r[i] < s[i]) return  true;
        if (len_a > len_b) return false;
        if (len_a < len_b) return  true;
	}
}

int compara_sequencias(int *r, int *s, int len_r, int len_s){
        /* Garantindo que o loop irá
          parar ao fim do menor vetor*/
        int controlador_loop;
        if (len_r > len_s) controlador_loop = len_s;
        else controlador_loop = len_r;
        /* Comparando todos os elementos */
        for (int i = 0; i < controlador_loop; i++) {
                if (r[i] < s[i]) return 1;
                if (r[i] > s[i]) return -1;
        }
        /* Comparando tamanhos */
        if (len_r < len_s) return -1;
        if (len_r > len_s) return -1;
        return 0;                     // Se forem iguais
}

bool se_subsequencia(int *s, int *a, int len_s, int len_a) {
        bool output;
        int j = 0;
        for (int i = 0; i < len_s; i++) {
                while (j < len_a) {
                       if (s[i] == a[j]) {
                        output = true;  //  encontrou
                        break;          // um equivalente
                       } else output = false; j++;
                }                            // nao encontrou
                if (!output) return output;  //  equivalente
        }
        return true;
}

bool se_segmento(int *s, int *a, int len_s, int len_a) {
        /*
         * Procura um equivalente ao primeiro item. Se não encontra
         * retorna false. Se encontra itera por len_s elementos em
         * len_a para ver se todos os elementos seguintes condizem
        */
        int j = 0;
        while (j < len_a) {
                if (a[j] == s[0]){
                        int k = 0;
                        for (int i = j; i < len_s + j; i++) {
                                if (s[k] != a[i]) return false;
                                k++;
                        }
                        return true;
                }
                j++;
        }
        return false;
}

int conta_sub_seq(int *s, int len_s){
        int current = s[0]; // 5
        int count = 1;
        for (int i = 1; i < len_s; i++)
                if (s[i] != current) { current = s[i]; count++; }
        return count;
}

int main(){

        printf("==== 01 ====\n");
        int a[] = {4, 1, 2, 5, 6, 9, 10, 11};
        int b[] = {4, 1, 2, 5, 6, 9};
        int size_a = sizeof(a) / sizeof(a[0]);
        int size_b = sizeof(b) / sizeof(b[0]);
        printf("01: %s\n",
        verifica_se_menor(a, b, size_a, size_b) ? "V: R < S" : "F: R > S");
        
        printf("==== 02 ====\n");
        int c[] = {3, 1, 4, 1, 5, 9, 3};
        int d[] = {3, 1, 4, 1, 5, 9, 3};
        int size_c = sizeof(c) / sizeof(c[0]);
        int size_d = sizeof(d) / sizeof(d[0]);
        printf("02: %d\n", compara_sequencias(c, d, size_c, size_d));

        printf("==== 03 ====\n");
        int e[] = {2, 5, 6, 8};
        int f[] = {1, 2, 3, 4, 5, 6, 7, 8};
        int size_e = sizeof(e) / sizeof(e[0]);
        int size_f = sizeof(f) / sizeof(f[0]);
        printf("03: %s\n", 
        se_subsequencia(e, f, size_e, size_f) ? "Subsequencia" : "Nao subsequencia");

        printf("==== 04 ====\n");
        int g[] = {4, 5, 6};
        int h[] = {1, 2, 3, 4, 5, 6, 7, 8};
        int size_g = sizeof(g) / sizeof(g[0]);
        int size_h = sizeof(h) / sizeof(h[0]);
        printf("04: %s\n", 
        se_segmento(g, h, size_g, size_h) ? "Segmento" : "Nao segmento");

        printf("==== 05 ====\n");
        int m[] = {5, 2, 2, 3, 4, 4, 4, 4, 4, 1, 1};
        int size_m = sizeof(m) / sizeof(m[0]);
        printf("05: %d\n", conta_sub_seq(m, size_m));
        int n[] = {3, 3, -1, -1, -1, 12, 12, 12, 3, 3};
        int size_n = sizeof(n) / sizeof(n[0]);
        printf("05: %d\n", conta_sub_seq(n, size_n));

        return 0;
}
