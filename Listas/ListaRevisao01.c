#include <stdio.h>

void exibir_vetor(int *v, int len){
	for (int i = 0; i < len; i++){
		if (i == 0) printf("[");
		if (i == len - 1) printf("%d]", v[i]);
		else printf("%d, ", v[i]);
	}
}

// ex 01
int mdc_2(int x, int y)
{
	if (x == y) return x;
	if (x%2 == 0 && y%2 == 0)          return 2*(mdc_2(x/2, y/2));
	if (x%2 == 0 && y%2 != 0)          return mdc_2(x/2, y);
	if (x%2 != 0 && y%2 == 0)          return mdc_2(x, y/2);
	if (x%2 != 0 && y%2 != 0 && x > y) return mdc_2((x-y)/2, y);
	if (x%2 != 0 && y%2 != 0 && x < y) return mdc_2(x, (y-x)/2);
	return 0;
}
