#include <stdio.h>
#include <stdlib.h>

int *parent, *sz, *parity;

int find(int x) {
    if (parent[x] == x)
        return x;

    int p = parent[x];
    parent[x] = find(p);
    parity[x] ^= parity[p];

    return parent[x];
}

int addEdge(int u, int v) {
    int ru = find(u);
    int rv = find(v);

    int pu = parity[u];
    int pv = parity[v];

    if (ru == rv)
        return (pu ^ pv) == 1;

    if (sz[ru] < sz[rv]) {
        int temp = ru;
        ru = rv;
        rv = temp;
    }

    parent[rv] = ru;
    parity[rv] = pu ^ pv ^ 1;
    sz[ru] += sz[rv];

    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    parent = malloc((n + 1) * sizeof(int));
    sz = malloc((n + 1) * sizeof(int));
    parity = calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (addEdge(u, v))
            printf("ADDED\n");
        else
            printf("REJECTED\n");
    }

    free(parent);
    free(sz);
    free(parity);

    return 0;
}