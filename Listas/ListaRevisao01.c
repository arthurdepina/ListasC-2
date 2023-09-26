#include <stdio.h>

void exibir_vetor(int *v, int len){
	for (int i = 0; i < len; i++){
		if (i == 0) printf("[");
		if (i == len - 1) printf("%d]", v[i]);
		else printf("%d, ", v[i]);
	}
}

// ex 01
int mdc_2(int x, int y)
{
	if (x == y) return x;
	if (x%2 == 0 && y%2 == 0)          return 2*(mdc_2(x/2, y/2));
	if (x%2 == 0 && y%2 != 0)          return mdc_2(x/2, y);
	if (x%2 != 0 && y%2 == 0)          return mdc_2(x, y/2);
	if (x%2 != 0 && y%2 != 0 && x > y) return mdc_2((x-y)/2, y);
	if (x%2 != 0 && y%2 != 0 && x < y) return mdc_2(x, (y-x)/2);
	return 0;
}

// ex 02
int max_bitonic(int *vetor, int menor, int maior)
{
	int meio = (menor + maior)/2;
	if(menor == maior) return vetor[meio];
	if(vetor[meio] > vetor[meio + 1] && vetor[meio] > vetor[meio-1]) return vetor[meio];
	else if(vetor[meio] > vetor[meio + 1] && vetor[meio] < vetor[meio-1])
		return max_bitonic(vetor, menor, meio-1);
	else return max_bitonic(vetor, meio+1, maior);
}

// ex 03
/* ainda nao fiz */

// ex 04
int conta_sub_seq(int *s, int len_s)		// Complexidade: O(n)
{
        int current = s[0];
        int count = 1;
        for (int i = 1; i < len_s; i++)
                if (s[i] != current) { current = s[i]; count++; }
        return count;
}

// ex 05
int max_seq_cres(int *s, int len_s)			// Complexidade: O(n)
{
        int max = 1;
        int count = 0;
        for (int i = 1; i < len_s; i++){
                if (s[i] > s[i - 1]){
                        count++;
                        if (count > max) max = count;
                } else count = 1;
        }
        return max;
}

// ex 06
void seg_consec(int *a, int len_a)
{
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

// ex 07
int max_soma_seg(int *s, int len_s)
{
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

// ex 08
int * junta_ordenadas(int *a, int *b, int len_a, int len_b)
{
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

int main()
{
	printf("=====================01=====================\n");
	printf("%d\n", mdc_2(270, 192));
	printf("%d\n",   mdc_2(35, 10));
	printf("%d\n",   mdc_2(10, 15));
	printf("%d\n",    mdc_2(31, 2));
	printf("=====================02=====================\n");
	int vetor_a[] = {1, 3, 5, 13, 12, 11, 9, 8, 4, 2};
	int vetor_b[] = {1, 5, 13, 17, 19, 20, 21, 22, 16, 14, 4, 2};
	int vetor_c[] = {2, 4, 5, 8, 11, 30};
	int vetor_d[] = {10, 9, 8, 7, 6, 4, 2};
	int len_a     = sizeof(vetor_a)/sizeof(vetor_a[0]);
	int len_b     = sizeof(vetor_b)/sizeof(vetor_b[0]);
	int len_c     = sizeof(vetor_c)/sizeof(vetor_c[0]);
	int len_d     = sizeof(vetor_d)/sizeof(vetor_d[0]);
	exibir_vetor(vetor_a, len_a); printf("\n");
	printf("Máximo elemento: %d\n", max_bitonic(vetor_a, 0, len_a-1));
	exibir_vetor(vetor_b, len_b); printf("\n");
	printf("Máximo elemento: %d\n", max_bitonic(vetor_b, 0, len_b-1));
	exibir_vetor(vetor_c, len_c); printf("\n");
	printf("Máximo elemento: %d\n", max_bitonic(vetor_c, 0, len_c-1));
	exibir_vetor(vetor_d, len_d); printf("\n");
	printf("Máximo elemento: %d\n", max_bitonic(vetor_d, 0, len_d-1));
	printf("=====================03=====================\n");
	//					  ainda nao fiz
	printf("=====================04=====================\n");
	int m[] = {5, 2, 2, 3, 4, 4, 4, 4, 4, 1, 1};
	int size_m = sizeof(m) / sizeof(m[0]);
	printf("04: %d\n", conta_sub_seq(m, size_m));
	int n[] = {3, 3, -1, -1, -1, 12, 12, 12, 3, 3};
	int size_n = sizeof(n) / sizeof(n[0]);
	printf("04: %d\n", conta_sub_seq(n, size_n));
	printf("=====================05=====================\n");
	int p[] = {5, 10, 3, 2, 4, 7, 9, 8, 5};
	int size_p = sizeof(p) / sizeof(p[0]);
	printf("05: %d\n", max_seq_cres(p, size_p));
	int q[] = {10, 8, 7, 5, 2};
	int size_q = sizeof(q) / sizeof(q[0]);
	printf("05: %d\n", max_seq_cres(q, size_q));
	printf("=====================06=====================\n");
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
	printf("=====================07=====================\n");
	int f[] = {5, 2, -2, -7, 3, 14, 10, -3, 9, -6, 4, 1};
	int size_f = sizeof(f) / sizeof(f[0]);
	printf("%d\n", max_soma_seg(f, size_f));
	printf("=====================07=====================\n");
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
}
