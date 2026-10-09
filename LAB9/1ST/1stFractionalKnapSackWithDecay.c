#include <stdio.h>

int n, used[10], order[10], bestOrder[10], bestN;
double v[10], w[10], lambda[10], W, best = 0, amount[10];

void check(int k) {
    int idx[10];
    double d[10], a[10] = {0}, rem = W, val = 0;

    for (int i = 0; i < k; i++) {
        idx[i] = i;
        d[i] = v[order[i]] / w[order[i]] - lambda[order[i]] * i;
    }

    for (int i = 0; i < k; i++)
        for (int j = i + 1; j < k; j++)
            if (d[idx[j]] > d[idx[i]]) {
                int t = idx[i];
                idx[i] = idx[j];
                idx[j] = t;
            }

    for (int j = 0; j < k && rem > 0; j++) {
        int p = idx[j], id = order[p];
        if (d[p] <= 0) break;
        double x = rem < w[id] ? rem : w[id];
        a[id] = x;
        val += x * d[p];
        rem -= x;
    }

    if (val > best) {
        best = val;
        bestN = k;
        for (int i = 0; i < k; i++)
            bestOrder[i] = order[i];
        for (int i = 0; i < n; i++)
            amount[i] = a[i];
    }
}

void solve(int k) {
    check(k);
    for (int i = 0; i < n; i++)
        if (!used[i]) {
            used[i] = 1;
            order[k] = i;
            solve(k + 1);
            used[i] = 0;
        }
}

int main() {
    scanf("%d%lf", &n, &W);

    if (n < 1 || n > 9) return 0;

    for (int i = 0; i < n; i++)
        scanf("%lf%lf%lf", &v[i], &w[i], &lambda[i]);

    solve(0);

    printf("Maximum Value: %.2f\n", best);
    for (int i = 0; i < bestN; i++) {
        int id = bestOrder[i];
        if (amount[id] > 0)
            printf("Item %d: %.2f\n", id + 1, amount[id]);
    }
    return 0;
}