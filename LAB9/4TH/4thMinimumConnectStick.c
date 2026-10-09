#include <stdio.h>

typedef long long ll;

ll heap[100005];
int size = 0;

void push(ll x) {
    int i = ++size;
    while (i > 1 && heap[i / 2] > x) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = x;
}

ll pop() {
    ll ans = heap[1], x = heap[size--];
    int i = 1, j;

    while ((j = 2 * i) <= size) {
        if (j < size && heap[j + 1] < heap[j]) j++;
        if (heap[j] >= x) break;
        heap[i] = heap[j];
        i = j;
    }
    if (size) heap[i] = x;
    return ans;
}

int main() {
    int n;
    ll x, cost = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        push(x);
    }

    while (size > 1) {
        ll sum = pop() + pop();
        cost += sum;
        push(sum);
    }

    printf("%lld\n", cost);
    return 0;
}