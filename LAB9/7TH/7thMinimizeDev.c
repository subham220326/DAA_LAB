#include <stdio.h>
#include <limits.h>

typedef long long ll;

ll heap[100005];
int size = 0;

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
    ll x, mn = LLONG_MAX, ans = LLONG_MAX;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        if (x % 2) x *= 2;
        if (x < mn) mn = x;
        push(x);
    }

    while (size) {
        ll mx = pop();

        if (mx - mn < ans)
            ans = mx - mn;

        if (mx % 2) break;

        mx /= 2;
        if (mx < mn) mn = mx;
        push(mx);
    }

    printf("%lld\n", ans);
    return 0;
}