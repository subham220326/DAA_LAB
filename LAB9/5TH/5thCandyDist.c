#include <stdio.h>

int main() {
    int n, a[100005], c[100005];
    long long ans = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        c[i] = 1;
    }

    for (int i = 1; i < n; i++)
        if (a[i] > a[i - 1])
            c[i] = c[i - 1] + 1;

    for (int i = n - 2; i >= 0; i--)
        if (a[i] > a[i + 1] && c[i] <= c[i + 1])
            c[i] = c[i + 1] + 1;

    for (int i = 0; i < n; i++)
        ans += c[i];

    printf("%lld\n", ans);
    return 0;
}