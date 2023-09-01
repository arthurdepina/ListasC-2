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
        for (int i = 0; i < controlador_loop; i++){
                if (r[i] < s[i]) return 1;
                if (r[i] > s[i]) return -1;
        }
        /* Comparando tamanhos */
        if (len_r < len_s) return -1;
        if (len_r > len_s) return -1;
        return 0;                   // Se forem iguais
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
        return 0;
}
