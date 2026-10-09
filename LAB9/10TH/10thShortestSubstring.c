#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int overlap(const char *a, const char *b) {
    if (strstr(a, b))
        return strlen(b);

    int x = strlen(a), y = strlen(b);
    int k = x < y ? x : y;

    while (k > 0) {
        if (strncmp(a + x - k, b, k) == 0)
            return k;
        k--;
    }
    return 0;
}

char *merge(const char *a, const char *b, int k) {
    int x = strlen(a), y = strlen(b);
    char *res;

    if (strstr(a, b)) {
        res = malloc(x + 1);
        strcpy(res, a);
    } else {
        res = malloc(x + y - k + 1);
        strcpy(res, a);
        strcat(res, b + k);
    }

    return res;
}

int main() {
    int n;
    char *s[100], buf[10005];

    scanf("%d", &n);
    if (n < 1 || n > 100) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%10004s", buf);
        s[i] = malloc(strlen(buf) + 1);
        strcpy(s[i], buf);
    }

    while (n > 1) {
        int bi = 0, bj = 1, best = -1;
        int bestLen = 2147483647;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int k = overlap(s[i], s[j]);
                int len = strlen(s[i]) + strlen(s[j]) - k;

                if (k > best || (k == best && len < bestLen)) {
                    best = k;
                    bestLen = len;
                    bi = i;
                    bj = j;
                }
            }
        }

        char *merged = merge(s[bi], s[bj], best);
        char *temp[100];
        int m = 0;

        for (int i = 0; i < n; i++)
            if (i != bi && i != bj)
                temp[m++] = s[i];

        temp[m++] = merged;

        free(s[bi]);
        free(s[bj]);

        n = m;
        for (int i = 0; i < n; i++)
            s[i] = temp[i];
    }

    printf("%s\n", s[0]);
    free(s[0]);

    return 0;
}