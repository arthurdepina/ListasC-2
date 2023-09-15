#include <stdio.h>

int usado[3] = {0, 0, 0};

void exibir_vetor(int *v, int len){
    for (int i = 0; i < len; i++){
        if (i == 0) printf("[");
        if (i == len - 1) printf("%d]", v[i]);
        else printf("%d, ", v[i]);
    }
}

void combinacao_tres(char* str, int atual){
    if (atual == 3){
        str[atual] = '\0';
        printf("%s\n", str);
        return;
    }

    str[atual] = '1';
    combinacao_tres(str, atual + 1);

    str[atual] = '2';
    combinacao_tres(str, atual + 1);

    str[atual] = '3';
    combinacao_tres(str, atual + 1);
}

void permutacao(int *v, int *s, int atual, int count){
    if (count == atual) {
        exibir_vetor(s, 3);
        return;
    }
    for(int i = 0; i < 3; i++){
        if (!usado[i]);
        s[count] = 
    }
}

int main(){
    char seq[4];
    combinacao_tres(seq, 0); 
    printf("\n");
    
    return 0;
}
