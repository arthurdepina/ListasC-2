#include <stdio.h>
#include <stdlib.h>

void exibir_vetor (int *v, int len)
{
	for (int i = 0; i < len; i++){
		if (i == 0) printf("[");
		if (i == len - 1) printf("%d]", v[i]);
		else printf("%d, ", v[i]);
	}
}

void exibir_matriz (int **matriz, int n_linhas, int n_colunas)
{
    int i, j;
    for (i = 0; i < n_linhas; i++){
        for (j = 0; j < n_colunas; j++){
            printf("[%d][%d] = %d\n", i, j, matriz[i][j]);
        }
    }
}

int **alocar_matriz (int n_linhas, int n_colunas)
{
    int **matriz;
    matriz = (int**) calloc(n_linhas, sizeof(int*));
    for (int i = 0; i < n_linhas; i++){
        matriz[i] = (int *) calloc(n_colunas, sizeof(int));
    }
    return matriz;
}

int converter_p_binario (int n)
{
    int resto;
    int multi = 1;
    int bin = 0;
    while (n != 0) {
        resto = n % 2;
        resto = resto * multi;
        n = n / 2;
        multi *= 10;
        bin = bin + resto;
    }
    return bin;
}

int soma_vetor (int *vetor, int len)
{
    int soma = 0;
    for (int i = 0; i < len; i++) {
        soma = soma + vetor[i];
    }
    return soma;
}

void troca (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
            Apenas para referenciar
*/

int * teste_retorna_array(int *s, int len_s)
{
    s[len_s - 1] = 8888;
	return s;
}
