#include <stdio.h>

void exibir_vetor(int *v, int len){
	for (int i = 0; i < len; i++){
		if (i == 0) printf("[");
		if (i == len - 1) printf("%d]", v[i]);
		else printf("%d, ", v[i]);
	}
}

int mdc(int x, int y){
	if (y <= x && x%y == 0) return y;
	if (x < y)              return mdc(y, x);
	return mdc(y, x%y);
}

int mdc_2(int x, int y){
	if (x == y) return x;
	if (x%2 == 0 && y%2 == 0)          return 2*(mdc_2(x/2, y/2));
	if (x%2 == 0 && y%2 != 0)          return mdc_2(x/2, y);
	if (x%2 != 0 && y%2 == 0)          return mdc_2(x, y/2);
	if (x%2 != 0 && y%2 != 0 && x > y) return mdc_2((x-y)/2, y);
	if (x%2 != 0 && y%2 != 0 && x < y) return mdc_2(x, (y-x)/2);
	return 0;
}

int potencia(int x, int n){
	if(n == 0)            return 1;
	if(n > 0 && n%2 == 0) return potencia(x, n/2) * potencia(x, n/2);
	if(n > 0 && n%2 != 0) return x * potencia(x, n/2) * potencia(x, n/2);
	return 0;
}

int coef_binomial(int n, int m){
	if(n == m || m == 0) return 1;
	return coef_binomial(n - 1, m) + coef_binomial(n - 1, m - 1);
}

int max_bitonic(int *vetor, int menor, int maior){
	int meio = (menor + maior)/2;
	if(menor == maior) return vetor[meio];
	if(vetor[meio] > vetor[meio + 1] && vetor[meio] > vetor[meio-1]) return vetor[meio];
	else if(vetor[meio] > vetor[meio + 1] && vetor[meio] < vetor[meio-1])
		return max_bitonic(vetor, menor, meio-1);
	else return max_bitonic(vetor, meio+1, maior);
}
  
int main(){
	printf("==01==\n");
	printf("%d\n",  mdc(270, 192));
	printf("%d\n",    mdc(35, 10));
	printf("%d\n",    mdc(10, 15));
	printf("%d\n",     mdc(31, 2));
	printf("==02==\n");
	printf("%d\n", mdc_2(270, 192));
	printf("%d\n",   mdc_2(35, 10));
	printf("%d\n",   mdc_2(10, 15));
	printf("%d\n",    mdc_2(31, 2));
	printf("==03==\n");
	printf("%d\n", potencia(2, 3));
	printf("%d\n", potencia(3, 4));
	printf("%d\n", potencia(8, 0));
	printf("%d\n", potencia(9, 3));
	printf("==04==\n");
	printf("%d\n",  coef_binomial(10, 8));
	printf("%d\n", coef_binomial(42, 40));
	printf("%d\n", coef_binomial(24, 20));
	printf("%d\n",   coef_binomial(4, 2));
	printf("=====================05=====================\n");
	int vetor_a[] = {1, 3, 5, 13, 12, 11, 9, 8, 4, 2};
	int vetor_b[] = {1, 5, 13, 17, 19, 20, 21, 22, 16, 14, 4, 2};
	int vetor_c[] = {2, 4, 5, 8, 11, 30};
	int vetor_d[] = {10, 9, 8, 7, 6, 4, 2};
	int len_a     = sizeof(vetor_a)/sizeof(vetor_a[0]);
	int len_b     = sizeof(vetor_b)/sizeof(vetor_b[0]);
	int len_c     = sizeof(vetor_c)/sizeof(vetor_c[0]);
	int len_d     = sizeof(vetor_d)/sizeof(vetor_d[0]);
	exibir_vetor(vetor_a, len_a); printf("\n");
	printf("Máximo elemento: %d\n", max_bitonic(vetor_a, 0, len_a-1));
	exibir_vetor(vetor_b, len_b); printf("\n");
	printf("Máximo elemento: %d\n", max_bitonic(vetor_b, 0, len_b-1));
	exibir_vetor(vetor_c, len_c); printf("\n");
	printf("Máximo elemento: %d\n", max_bitonic(vetor_c, 0, len_c-1));
	exibir_vetor(vetor_d, len_d); printf("\n");
	printf("Máximo elemento: %d\n", max_bitonic(vetor_d, 0, len_d-1));
	printf("=============================================\n");
	return 0;
}

