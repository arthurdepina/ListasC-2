#include <stdio.h>
#include <stdlib.h>
#include "useful.c"

int main(){
	int vetor_a[] = {1, 3, 5, 13, 12, 11, 9, 8, 4, 2};
	int current = 4;
	int c = vetor_a[current];
	printf("%d\n", c);
	return 0;
}
