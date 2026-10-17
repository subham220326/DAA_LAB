#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *parent, *sz;
long long *sum, *tree;
int base, K;

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void update(int pos, long long val) {
    int i = base + pos - 1;
    tree[i] = val;

    for (i /= 2; i >= 1; i /= 2) {
        long long a = tree[2 * i];
        long long b = tree[2 * i + 1];

        tree[i] = (a > b) ? a : b;
    }
}

void unite(int u, int v) {
    int a = find(u);
    int b = find(v);

    if (a == b)
        return;

    if (sz[a] < sz[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    update(a, LLONG_MIN);
    update(b, LLONG_MIN);

    parent[b] = a;
    sz[a] += sz[b];
    sum[a] += sum[b];

    if (sz[a] <= K)
        update(a, sum[a]);
}

int main() {
    int n, m;
    scanf("%d %d %d", &n, &m, &K);

    parent = malloc((n + 1) * sizeof(int));
    sz = malloc((n + 1) * sizeof(int));
    sum = malloc((n + 1) * sizeof(long long));

    base = 1;
    while (base < n)
        base *= 2;

    tree = malloc(2 * base * sizeof(long long));

    for (int i = 1; i < 2 * base; i++)
        tree[i] = LLONG_MIN;

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &sum[i]);

        parent[i] = i;
        sz[i] = 1;

        if (K >= 1)
            tree[base + i - 1] = sum[i];
    }

    for (int i = base - 1; i >= 1; i--) {
        long long a = tree[2 * i];
        long long b = tree[2 * i + 1];

        tree[i] = (a > b) ? a : b;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        long long edgeWeight;

        scanf("%d %d %lld", &u, &v, &edgeWeight);

        unite(u, v);

        if (tree[1] == LLONG_MIN)
            printf("NONE\n");
        else
            printf("%lld\n", tree[1]);
    }

    free(parent);
    free(sz);
    free(sum);
    free(tree);

    return 0;
}