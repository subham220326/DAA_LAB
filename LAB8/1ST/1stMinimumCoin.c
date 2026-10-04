#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int n, int V) {
    int dp[V + 1];
    dp[0] = 0;
    for (int i = 1; i <= V; i++)
        dp[i] = INT_MAX;
    for (int amount = 1; amount <= V; amount++) {
        for (int i = 0; i < n; i++) {
            if (coins[i] <= amount && dp[amount - coins[i]] != INT_MAX) {
                int result = dp[amount - coins[i]] + 1;

                if (result < dp[amount])
                    dp[amount] = result;
            }
        }
    }

    return dp[V] == INT_MAX ? -1 : dp[V];
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
    int result = minCoins(coins, n, V);
    if (result == -1)
        printf("Amount cannot be made.\n");
    else
        printf("Minimum number of coins = %d\n", result);

    return 0;
}