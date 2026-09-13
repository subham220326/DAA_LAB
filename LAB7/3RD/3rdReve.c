#include <stdio.h>
int move_count = 0;
void hanoi_3peg(int n, char src, char dest, char aux) {
    if (n == 0) return;
    hanoi_3peg(n - 1, src, aux, dest);
    printf("Move disk %d: %c -> %c\n", n, src, dest);
    move_count++;
    hanoi_3peg(n - 1, aux, dest, src);
}
void reves_puzzle(int n, int offset, char src, char dest, char aux1, char aux2) {
    if (n == 0) return;
    if (n == 1) {
        printf("Move disk %d: %c -> %c\n", offset + 1, src, dest);
        move_count++;
        return;
    }
    int k = (n == 8) ? 4 : (n > 2 ? n - 2 : n - 1);

    reves_puzzle(k, offset, src, aux1, aux2, dest);
    hanoi_3peg(n - k, aux1, dest, aux2);
    reves_puzzle(k, offset, aux1, dest, src, aux2);
}
int main() {
    int n = 8;
    printf("--- Q3: Reve's Puzzle (n = %d) ---\n", n);
    reves_puzzle(n, 0, 'A', 'D', 'B', 'C');
    printf("Total moves: %d\n", move_count);
    return 0;
}