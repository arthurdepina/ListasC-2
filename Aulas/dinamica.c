#include <stdio.h>
#include <stdlib.h>

void initMemoization (long long int *memo, int n)
{
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
}

long long int fibonacci (int n, long long int *memo)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (memo[n] != -1) return memo[n];

    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main()
{
    int n;
    printf("Value of n: ");
    scanf("%d", &n);

    long long int *memo = (long long int *) malloc ((n + 1) * sizeof(long long int));
    initMemoization(memo, n);

    long long int result = fibonacci(n, memo);
    printf("Fibonacci number at %d: %lld\n", n, result);

    free(memo);
    return 0;
}
