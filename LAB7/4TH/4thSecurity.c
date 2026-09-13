#include <stdio.h>
int switch_moves = 0;
void turn_off(int n);
void turn_on(int n);
void turn_off(int n) {
    if (n <= 0) return;
    if (n == 1) {
        printf("Toggle switch 1 (OFF)\n");
        switch_moves++;
        return;
    }
    turn_off(n - 2);
    printf("Toggle switch %d (OFF)\n", n);
    switch_moves++;
    turn_on(n - 2);
    turn_off(n - 1);
}

void turn_on(int n) {
    if (n <= 0) return;
    if (n == 1) {
        printf("Toggle switch 1 (ON)\n");
        switch_moves++;
        return;
    }
    turn_on(n - 1);
    turn_off(n - 2);
    printf("Toggle switch %d (ON)\n", n);
    switch_moves++;
    turn_on(n - 2);
}

int main() {
    int n = 4;
    printf("--- Q4: Security Switches (n = %d) ---\n", n);
    turn_off(n);
    printf("Total moves: %d\n", switch_moves);
    return 0;
}