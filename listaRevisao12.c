#include <stdio.h>
#include <stdbool.h>

int soma_vetor(int *vetor, int len)
{
    int soma = 0;
    for (int i = 0; i < len; i++) {
        soma = soma + vetor[i];
    }
    return soma;
}

bool quadrado_palito(int *palitos, int len_palitos)
{
    /* É necessário que haja um modo de dividir os
     *  palitos em quatro grupos de modo que
     * os quatro grupos tenham o mesmo tamanho*/
    
}

int main()
{
    int palitos[] = {3, 4, 5, 6, 7, 2, 9};
    int len_palitos = sizeof(palitos) / sizeof(palitos[0]);
    printf("%d\n", soma_vetor(palitos, len_palitos));
    return 0;
}
