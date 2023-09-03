#include <stdio.h>
#include <stdlib.h>
#include "useful.c"

int main () {
    int f[] = {5, 2, -2, -7, 3, 14, 10, -3, 9, -6, 4, 1};
    int size_f = sizeof(f) / sizeof(f[0]);
	int *p;
	p = teste_retorna_array(f, size_f);
	exibir_vetor(p, size_f);
    return 0;
}
