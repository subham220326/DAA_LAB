#include <stdio.h>
#include <stdlib.h>

int *parent, *sz;

typedef struct {
    int root;
    int index;
} Item;

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    if (sz[a] < sz[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    parent[b] = a;
    sz[a] += sz[b];
}

int cmpItem(const void *a, const void *b) {
    const Item *x = a;
    const Item *y = b;

    if (x->root != y->root)
        return (x->root > y->root) -
               (x->root < y->root);

    return (x->index > y->index) -
           (x->index < y->index);
}

int cmpInt(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *A = malloc((n + 1) * sizeof(int));
    int *ans = malloc((n + 1) * sizeof(int));
    int *values = malloc(n * sizeof(int));

    parent = malloc((n + 1) * sizeof(int));
    sz = malloc((n + 1) * sizeof(int));

    Item *items = malloc(n * sizeof(Item));

    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);

        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        unite(u, v);
    }

    for (int i = 1; i <= n; i++) {
        items[i - 1].root = find(i);
        items[i - 1].index = i;
    }

    qsort(items, n, sizeof(Item), cmpItem);

    int i = 0;

    while (i < n) {
        int j = i;

        // Collect values from one component
        while (j < n &&
               items[j].root == items[i].root) {

            values[j - i] = A[items[j].index];
            j++;
        }

        // Sort component values
        qsort(values, j - i, sizeof(int), cmpInt);

        // Assign smallest values to smallest indices
        for (int k = i; k < j; k++)
            ans[items[k].index] = values[k - i];

        i = j;
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);

    printf("\n");

    free(A);
    free(ans);
    free(values);
    free(parent);
    free(sz);
    free(items);

    return 0;
}