#include <stdio.h>

int mdc(int x, int y){
	if (y <= x && x%y == 0) return y;
	if (x < y) return mdc(y, x);
	return mdc(y, x%y);
}

int mdc_2(int x, int y){
	if (x == y) return x;
	if (x%2 == 0 && y%2 == 0) return 2*(mdc_2(x/2, y/2));
	if (x%2 == 0 && y%2 != 0) return mdc_2(x/2, y);
	if (x%2 != 0 && y%2 == 0) return mdc_2(x, y/2);
	if (x%2 != 0 && y%2 != 0 && x > y) return mdc_2((x-y)/2, y);
	if (x%2 != 0 && y%2 != 0 && x < y) return mdc_2(x, (y-x)/2);
	return 0;
}

int potencia(int x, int n){
	if(n == 0) return 1;
	if(n > 0 && n%2 == 0) return potencia(potencia(x, n/2), 2);
	if(n > 0 && n%2 != 0) return x*potencia(potencia(x, (n-1)/2), 2);
	return 0;
}

int main(){
	printf("%d\n", mdc(270, 192));
	printf("%d\n", mdc(35, 10));
	printf("%d\n", mdc(10, 15));
	printf("%d\n", mdc(31, 2));
	printf("==================\n");
	printf("%d\n", mdc_2(270, 192));
	printf("%d\n", mdc_2(35, 10));
	printf("%d\n", mdc_2(10, 15));
	printf("%d\n", mdc_2(31, 2));
	printf("==================\n");
	printf("%d\n", potencia(2, 3));
	printf("%d\n", potencia(3, 4));
	printf("%d\n", potencia(8, 0));
	printf("%d\n", potencia(9, 3));
	return 0;
}

