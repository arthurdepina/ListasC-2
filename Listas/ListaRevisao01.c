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
}
