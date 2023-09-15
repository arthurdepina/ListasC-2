#include <stdio.h>

void exibir_vetor(int *v, int len){
	for (int i = 0; i < len; i++){
		if (i == 0) printf("[");
		if (i == len - 1) printf("%d]", v[i]);
		else printf("%d, ", v[i]);
	}
}

void combinacao_tres(int *v, int *novo_v, int len, int count){
    if (count == len) {
        exibir_vetor(novo_v, len);
        printf("\n");
    } else {
        for(int i = 0; i < len; i++){
        novo_v[count] = v[i];
        combinacao_tres(v, novo_v, len, count + 1);
        }
    }
}

int main(void) {
    int v[] = {1,2,3};
    int vazio[] = {0,0,0};
    combinacao_tres(v, vazio, 3, 0);
    printf("\n");
    return 0;
}
