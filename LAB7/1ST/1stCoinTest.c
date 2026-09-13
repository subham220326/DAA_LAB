#include <stdio.h>
void invert_coin_triangle(int n) {
    int total_coins = n * (n + 1) / 2;
    int min_moves = total_coins / 3;
    printf("--- Q1: Invert Coin-Triangle ---\n");
    printf("Side length (n): %d\n", n);
    printf("Total coins: %d\n", total_coins);
    printf("Minimum moves required: %d\n", min_moves);
    if (n == 4) {
        printf("Move sequence for n = 4:\n");
        printf("1. Move coin from row 1, col 1 -> row 4, col 0\n");
        printf("2. Move coin from row 4, col 1 -> row 2, col 3\n");
        printf("3. Move coin from row 4, col 4 -> row 2, col 0\n");
    }
}
int main() {
    invert_coin_triangle(4);
    return 0;
}