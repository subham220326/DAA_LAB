#include <stdio.h>
#include <stdlib.h>

int *parent, *sz;

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

int unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return 0;

    if (sz[a] < sz[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    parent[b] = a;
    sz[a] += sz[b];

    return 1;
}

int main() {
    int R, C, k;
    scanf("%d %d %d", &R, &C, &k);

    int n = R * C;

    parent = malloc(n * sizeof(int));
    sz = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        parent[i] = -1;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    int islands = 0;

    while (k--) {
        int r, c;
        scanf("%d %d", &r, &c);

        int id = (r - 1) * C + (c - 1);

        if (parent[id] != -1) {
            printf("%d\n", islands);
            continue;
        }

        parent[id] = id;
        sz[id] = 1;
        islands++;

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 1 || nr > R ||
                nc < 1 || nc > C)
                continue;

            int nid = (nr - 1) * C + (nc - 1);

            if (parent[nid] != -1) {
                if (unite(id, nid))
                    islands--;
            }
        }

        printf("%d\n", islands);
    }

    free(parent);
    free(sz);

    return 0;
}