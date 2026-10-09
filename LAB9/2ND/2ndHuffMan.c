#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long f[512];
int parent[512], len[256];
char name[256][32];

int cmp(const void *a, const void *b) {
    int x = *(int *)a, y = *(int *)b;
    if (len[x] != len[y]) return len[x] - len[y];
    return strcmp(name[x], name[y]);
}

int main() {
    int n, order[256];
    scanf("%d", &n);
    if (n < 1 || n > 256) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%31s%lld", name[i], &f[i]);
        order[i] = i;
    }

    for (int i = 0; i < 512; i++) parent[i] = -1;

    int m = n;
    while (m < 2 * n - 1) {
        int x = -1, y = -1;

        for (int i = 0; i < m; i++) {
            if (parent[i] != -1) continue;
            if (x == -1 || f[i] < f[x]) {
                y = x;
                x = i;
            } else if (y == -1 || f[i] < f[y]) {
                y = i;
            }
        }

        parent[x] = parent[y] = m;
        f[m] = f[x] + f[y];
        m++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; parent[j] != -1; j = parent[j])
            len[i]++;
        if (n == 1) len[i] = 1;
    }

    qsort(order, n, sizeof(int), cmp);

    char code[512] = "";
    int prev = 0;

    for (int i = 0; i < n; i++) {
        int L = len[order[i]];

        if (i > 0) {
            for (int j = prev - 1; j >= 0; j--) {
                if (code[j] == '0') {
                    code[j] = '1';
                    break;
                }
                code[j] = '0';
            }
        }

        for (int j = i == 0 ? 0 : prev; j < L; j++)
            code[j] = '0';

        code[L] = '\0';
        prev = L;

        printf("%s: %s\n", name[order[i]], code);
    }
    return 0;
}