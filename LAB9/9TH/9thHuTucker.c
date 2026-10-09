#include <stdio.h>
#include <limits.h>

typedef long long ll;

ll dp[505][505], sum[505];
int opt[505][505];

void printTree(int l, int r) {
    if (l == r) {
        printf("%d", l + 1);
        return;
    }

    int k = opt[l][r];

    printf("(");
    printTree(l, k);
    printf(" ");
    printTree(k + 1, r);
    printf(")");
}

int main() {
    int n;
    scanf("%d", &n);

    if (n < 1 || n > 500) return 0;

    for (int i = 0; i < n; i++) {
        ll x;
        scanf("%lld", &x);
        sum[i + 1] = sum[i] + x;
        opt[i][i] = i;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;

            int L = opt[i][j - 1];
            int R = opt[i + 1][j];

            for (int k = L; k <= R && k < j; k++) {
                ll cost = dp[i][k] + dp[k + 1][j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    opt[i][j] = k;
                }
            }

            dp[i][j] += sum[j + 1] - sum[i];
        }
    }

    printf("Minimum Cost: %lld\n", dp[0][n - 1]);
    printf("Optimal Tree: ");
    printTree(0, n - 1);
    printf("\n");

    return 0;
}