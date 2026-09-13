#include <stdio.h>
#include <limits.h>
#define MAX_E 50
#define MAX_F 1000
int dp[MAX_E][MAX_F];
int super_egg_drop(int E, int F) {
    for (int i = 1; i <= E; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (int j = 1; j <= F; j++) {
        dp[1][j] = j;
    }
    for (int i = 2; i <= E; i++) {
        for (int j = 2; j <= F; j++) {
            dp[i][j] = INT_MAX;
            for (int k = 1; k <= j; k++) {
                int worst = 1 + (dp[i - 1][k - 1] > dp[i][j - k] ? dp[i - 1][k - 1] : dp[i][j - k]);
                if (worst < dp[i][j]) {
                    dp[i][j] = worst;
                }
            }
        }
    }
    return dp[E][F];
}
int main() {
    int E = 2, F = 100;
    printf("--- Q2: Super Egg Drop ---\n");
    printf("Eggs: %d, Floors: %d\n", E, F);
    printf("Minimum droppings in worst case: %d\n", super_egg_drop(E, F));
    return 0;
}