#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];
    int dp[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for (int i = 0; i < n; i++)
        dp[i] = A[i];

    int maxSum = A[0];

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (A[j] < A[i] &&
                dp[j] + A[i] > dp[i]) {

                dp[i] = dp[j] + A[i];
            }
        }

        if (dp[i] > maxSum)
            maxSum = dp[i];
    }

    printf("Maximum Sum Increasing Subsequence = %d\n", maxSum);

    return 0;
}