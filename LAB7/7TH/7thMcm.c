#include <stdio.h>
#include <limits.h>

#define MAX_N 20

int m[MAX_N][MAX_N];
int s[MAX_N][MAX_N];

void print_optimal_parens(int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_optimal_parens(i, s[i][j]);
        print_optimal_parens(s[i][j] + 1, j);
        printf(")");
    }
}

void matrix_chain_order(int p[], int n) {
    // n is the number of matrices
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int L = 2; L <= n; L++) { // L = chain length
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("--- Q7: Matrix Chain Multiplication ---\n");
    printf("Minimum scalar multiplications: %d\n", m[1][n]);
    printf("Optimal Parenthesization: ");
    print_optimal_parens(1, n);
    printf("\n");
}

int main() {
    // Matrices: A1(40x20), A2(20x30), A3(30x10), A4(10x30)
    int p[] = {40, 20, 30, 10, 30};
    int n = sizeof(p) / sizeof(p[0]) - 1;

    matrix_chain_order(p, n);
    return 0;
}