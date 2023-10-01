#include <stdio.h>
#include <stdbool.h>
#include "useful.c"

bool existe_subconjunto(int *conjunto, int len, int soma, int c, int count)
{
    if (soma == c) return true;
    if (count == len || soma > c) return false;

    // Incluindo elemento atual
    int nova_soma = soma + conjunto[count];
    if (existe_subconjunto(conjunto, len, nova_soma, c, count + 1))
        return true;
    
    // Não inlcuindo elemento atual
    if (existe_subconjunto(conjunto, len, soma, c, count + 1))
        return true;

    return false;
}

int main()
{
    int cheques[] = {30, 40, 10, 15, 11, 60, 54};
    int len_cheques = sizeof(cheques) / sizeof(cheques[0]);
    int valor_debitado = 55;
    bool existe = existe_subconjunto(cheques, len_cheques, 0, valor_debitado, 0);
    if (existe) printf("Há cheques correspondentes");
    else printf("Não há cheques correspondentes");
    return 0;
}