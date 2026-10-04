#include <stdio.h>

long long countWays(int coins[], int n, int V) {
    long long dp[V + 1];

    for (int i = 0; i <= V; i++)
        dp[i] = 0;

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int amount = coins[i]; amount <= V; amount++) {
            dp[amount] += dp[amount - coins[i]];
        }
    }

    return dp[V];
}

int main() {
    int n, V;

    printf("Enter number of coin denominations: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter coin denominations: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    printf("Enter target amount: ");
    scanf("%d", &V);

    printf("Total number of ways = %lld\n",
           countWays(coins, n, V));

    return 0;
}