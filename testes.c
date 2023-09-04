#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <math.h>

int converter_p_binario(int n){
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

int main () {
    printf("%d\n", converter_p_binario(1));
    return 0;
}
