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
	return 0;
}

