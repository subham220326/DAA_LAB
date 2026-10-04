#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned long long collatzNext(unsigned long long n) {

    if (n % 2 == 0)
        return n / 2;

    if (n > (ULLONG_MAX - 1) / 3)
        return 0;   // Overflow

    return 3 * n + 1;
}

void analyze(unsigned long long n) {

    unsigned long long capacity = 10;
    unsigned long long size = 0;

    unsigned long long *sequence =
        malloc(capacity * sizeof(unsigned long long));

    if (sequence == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    unsigned long long current = n;

    while (1) {

        if (size == capacity) {

            capacity *= 2;

            unsigned long long *temp =
                realloc(sequence,
                        capacity * sizeof(unsigned long long));

            if (temp == NULL) {
                printf("Memory reallocation failed.\n");
                free(sequence);
                return;
            }

            sequence = temp;
        }

        sequence[size++] = current;

        if (current == 1)
            break;

        unsigned long long next = collatzNext(current);

        if (next == 0) {
            printf("Overflow detected for starting value %llu.\n",
                   n);
            free(sequence);
            return;
        }

        current = next;
    }

    printf("\nStarting value: %llu\n", n);
    printf("Number of terms: %llu\n", size);

    printf("Trajectory:\n");

    for (unsigned long long i = 0; i < size; i++)
        printf("%llu ", sequence[i]);

    printf("\n");

    free(sequence);
}

int main() {

    unsigned long long a, b;

    printf("Enter interval [a, b]: ");
    scanf("%llu %llu", &a, &b);

    if (a == 0 || a > b) {
        printf("Invalid interval.\n");
        return 1;
    }

    for (unsigned long long n = a; n <= b; n++) {

        analyze(n);

        if (n == ULLONG_MAX)
            break;
    }

    return 0;
}