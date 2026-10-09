#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    return (x > y) - (x < y);
}

int main() {
    int n;
    long long start[100005], end[100005];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%lld%lld", &start[i], &end[i]);

    qsort(start, n, sizeof(long long), cmp);
    qsort(end, n, sizeof(long long), cmp);

    int i = 0, j = 0, rooms = 0, ans = 0;

    while (i < n) {
        if (start[i] < end[j]) {
            rooms++;
            if (rooms > ans) ans = rooms;
            i++;
        } else {
            rooms--;
            j++;
        }
    }

    printf("%d\n", ans);
    return 0;
}