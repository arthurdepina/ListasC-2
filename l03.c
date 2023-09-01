#include <stdio.h>
#include <stdbool.h>

bool verifica_se_menor(int *r, int *s, int len_a, int len_b){
        for (int i = 0; i < len_a; i++){
                if (r[i] > s[i]) return false;
                if (r[i] < s[i]) return true;
        if (len_a > len_b) return false;
        if (len_a < len_b) return true;
	}
}



int main(){
        int a[] = {4, 1, 2, 5, 6, 9, 10, 11};
        int size_a = sizeof(a) /  sizeof(a[0]);
        int b[] = {4, 1, 2, 5, 6, 9};
        int size_b = sizeof(b) / sizeof(b[0]);
        printf("01: %s\n", verifica_se_menor(a, b, size_a, size_b) ? "V: A < B" : "F: A > B");
        
        return 0;
}
