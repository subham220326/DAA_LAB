#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *parent, *sz, *active;
int *head, *to, *nextEdge;
long long *w, *sum, *tree;

int base, edgeCount = 0;

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

void addEdge(int u, int v) {
    to[edgeCount] = v;
    nextEdge[edgeCount] = head[u];
    head[u] = edgeCount++;
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

    update(a, sum[a]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    parent = malloc((n + 1) * sizeof(int));
    sz = calloc(n + 1, sizeof(int));
    active = calloc(n + 1, sizeof(int));

    w = malloc((n + 1) * sizeof(long long));
    sum = malloc((n + 1) * sizeof(long long));

    head = malloc((n + 1) * sizeof(int));
    to = malloc(2 * m * sizeof(int));
    nextEdge = malloc(2 * m * sizeof(int));

    int *order = malloc(n * sizeof(int));
    long long *ans = malloc(n * sizeof(long long));

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &w[i]);
        head[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(u, v);
        addEdge(v, u);
    }

    for (int i = 0; i < n; i++)
        scanf("%d", &order[i]);

    base = 1;
    while (base < n)
        base *= 2;

    tree = malloc(2 * base * sizeof(long long));

    for (int i = 1; i < 2 * base; i++)
        tree[i] = LLONG_MIN;

    for (int i = n - 1; i >= 0; i--) {

        // State after deleting the first i+1 vertices
        ans[i] = (tree[1] == LLONG_MIN)
                     ? 0
                     : tree[1];

        int u = order[i];

        // Activate vertex
        active[u] = 1;
        parent[u] = u;
        sz[u] = 1;
        sum[u] = w[u];

        update(u, sum[u]);

        // Connect with active neighbors
        for (int e = head[u]; e != -1;
             e = nextEdge[e]) {

            int v = to[e];

            if (active[v])
                unite(u, v);
        }
    }

    for (int i = 0; i < n; i++)
        printf("%lld\n", ans[i]);

    free(parent);
    free(sz);
    free(active);
    free(w);
    free(sum);
    free(head);
    free(to);
    free(nextEdge);
    free(order);
    free(ans);
    free(tree);

    return 0;
}