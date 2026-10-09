#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
    ll d, f;
} Station;

Station s[100005];
ll heap[100005];
int size = 0;

int cmp(const void *a, const void *b) {
    ll x = ((Station *)a)->d, y = ((Station *)b)->d;
    return (x > y) - (x < y);
}

void push(ll x) {
    int i = ++size;
    while (i > 1 && heap[i / 2] < x) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = x;
}

ll pop() {
    ll ans = heap[1], x = heap[size--];
    int i = 1, j;

    while ((j = 2 * i) <= size) {
        if (j < size && heap[j + 1] > heap[j]) j++;
        if (heap[j] <= x) break;
        heap[i] = heap[j];
        i = j;
    }
    if (size) heap[i] = x;
    return ans;
}

int main() {
    int n;
    ll D, F;
    scanf("%d%lld%lld", &n, &D, &F);

    for (int i = 0; i < n; i++)
        scanf("%lld%lld", &s[i].d, &s[i].f);

    qsort(s, n, sizeof(Station), cmp);

    int i = 0, stops = 0;

    while (F < D) {
        while (i < n && s[i].d <= F)
            push(s[i++].f);

        if (!size) {
            printf("-1\n");
            return 0;
        }

        F += pop();
        stops++;
    }

    printf("%d\n", stops);
    return 0;
}