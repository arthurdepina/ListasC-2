#include <stdio.h>
#include "useful.c"

int main(){
	int vetor_a[] = {1, 3, 5, 13, 12, 11, 9, 8, 4, 2};
	int vetor_b[] = {1, 5, 13, 17, 19, 20, 21, 22, 16, 14, 4, 2};
	int vetor_c[] = {2, 4, 5, 8, 11, 30};
	int vetor_d[] = {10, 9, 8, 7, 6, 4, 2};
	int len_a = sizeof(vetor_a)/sizeof(vetor_a[0]);
	int len_b = sizeof(vetor_b)/sizeof(vetor_b[0]);
	int len_c = sizeof(vetor_c)/sizeof(vetor_c[0]);
	int len_d = sizeof(vetor_d)/sizeof(vetor_d[0]);
	exibir_vetor(vetor_a, len_a); printf("\n");
	exibir_vetor(vetor_b, len_b); printf("\n");
	exibir_vetor(vetor_c, len_c); printf("\n");
	exibir_vetor(vetor_d, len_d); printf("\n");
	return 0;
}
