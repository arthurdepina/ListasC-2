#include <stdio.h>
#include <stdlib.h>
#include "useful.c"

int maxElegantPermutedSum(int *arr, int n, int idx) {
    if (idx == n) {
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += abs(arr[i] - arr[i + 1]);
        }
        return sum;
    }

    int maxSum = 0;
    for (int i = idx; i < n; i++) {
        troca(&arr[i], &arr[idx]);

        int sum = maxElegantPermutedSum(arr, n, idx + 1);

        troca(&arr[i], &arr[idx]);

        if (sum > maxSum) {
            maxSum = sum;
        }
    }
    return maxSum;
}

int main() {
    int n = 4;
    int arr[] = {1, 5, 8, 4};

    int maxSum = maxElegantPermutedSum(arr, n, 0);
    printf("A soma permutada elegante é %d\n", maxSum);

    return 0;
}
