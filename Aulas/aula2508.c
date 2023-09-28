#include <stdio.h>

int ex2(int a, int b){
	if (b == 1) return a;
	if (b % 2 == 0) return ex2(a*a, b/2);
	return a * ex2(a - 1, b - 1);
}

int f(int n){ // Ex3
	if(n <= 1) return n;
	else return f(n-1) + f(n-2);
}

void hanoi(int n, char orig, char dest, char aux){
	if (n > 0) { 
		hanoi(n - 1, orig, aux, dest);
	}
	printf("mover %c para %c\n", orig, dest);
	hanoi(n-1, aux, dest, orig);
}

// Teorema mestre

void g(int n) {
	if(n > 1) {
		for (int i = 0; i < n; i++){
			printf("%d", n);
		}
		g(n/2); g(n/2); g(n/2); g(n/2);
	}
 } // theta(n^2)

void h(int n){
	if (n > 1) {
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				printf("%d\n");
			}
		}
		f(n/4); f(n/4); f(n/4);
	}
}


int main(){
	
	return 0;
}
