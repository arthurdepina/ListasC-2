#include <stdio.h>

int usado[] = {0, 0, 0};

void mostra_vetores(int *v, int len){
    for (int i = 0; i < len; i++){
        if (i == 0) printf("[");
        if (i == len - 1) printf("%d]", v[i]);
        else printf("%d, ", v[i]);
    }
}

void permutacao(int v[], int n, int s[], int i){
    if (i >= n){
        mostra_vetores(s, n);
        printf("\n");
    } else {
        for (int j = 0; j < n; j++) {
            if (!usado[j]) {
                usado[j] = 1;
                s[i] = v[j];
                permutacao(v, n, s, i + 1);
                usado[j] = 0;
            }
        }
    }
}


int main() {
    int v[3] = {1, 2, 3};
    int *p = v;
    int vazio[3] = {0, 0, 0};
    int *q = vazio;
    permutacao(p, 3, q, 0);
}

