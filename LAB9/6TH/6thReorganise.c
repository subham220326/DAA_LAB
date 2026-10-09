#include <stdio.h>
#include <string.h>

int main() {
    char s[100005], ans[100005];
    int k, freq[256] = {0}, last[256];

    scanf("%100004s%d", s, &k);

    int n = strlen(s);

    for (int i = 0; i < 256; i++)
        last[i] = -1000000000;

    for (int i = 0; i < n; i++)
        freq[(unsigned char)s[i]]++;

    for (int i = 0; i < n; i++) {
        int best = -1;

        for (int j = 0; j < 256; j++)
            if (freq[j] > 0 && i - last[j] >= k)
                if (best == -1 || freq[j] > freq[best])
                    best = j;

        if (best == -1) {
            printf("\n");
            return 0;
        }

        ans[i] = best;
        freq[best]--;
        last[best] = i;
    }

    ans[n] = '\0';
    printf("%s\n", ans);
    return 0;
}