#include <stdio.h>

void hit_target(int n) {
    if (n <= 1) return;
    if (n == 2) {
        printf("Shots: 2, 2\n");
        return;
    }

    printf("--- Q5: Moving Target Shooting Plan (n = %d) ---\n", n);
    printf("Phase 1 (Target starts at Even position): ");
    for (int i = 2; i <= n - 1; i++) {
        printf("%d ", i);
    }
    printf("\nPhase 2 (Target starts at Odd position):  ");
    for (int i = 2; i <= n - 1; i++) {
        printf("%d ", i);
    }
    printf("\nTotal shots guaranteed: %d\n", 2 * (n - 2));
}

int main() {
    hit_target(5);
    return 0;
}