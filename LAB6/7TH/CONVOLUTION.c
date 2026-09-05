#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <stdbool.h>
#define PI 3.14159265358979323846

typedef double complex cd;

void fft(cd *a, int n, bool invert) {
    if (n <= 1) return;

    cd *a0 = malloc((n / 2) * sizeof(cd));
    cd *a1 = malloc((n / 2) * sizeof(cd));

    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    fft(a0, n / 2, invert);
    fft(a1, n / 2, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w = 1, wn = cos(ang) + I * sin(ang);

    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
    free(a0);
    free(a1);
}

void convolve(double *A, int m, double *B, int n, double *C) {
    int total_len = n + m - 1;
    int N = 1;
    while (N < total_len) N <<= 1;

    cd *fa = calloc(N, sizeof(cd));
    cd *fb = calloc(N, sizeof(cd));

    for (int i = 0; i < m; i++) fa[i] = A[i];
    for (int i = 0; i < n; i++) fb[i] = B[i];

    fft(fa, N, false);
    fft(fb, N, false);

    for (int i = 0; i < N; i++) fa[i] *= fb[i];

    fft(fa, N, true);

    for (int i = 0; i < total_len; i++)
        C[i] = creal(fa[i]);

    free(fa);
    free(fb);
}

int main() {
    double A[] = {1, 2, 3}; // m = 3
    double B[] = {4, 5, 6, 7}; // n = 4
    int m = 3, n = 4;
    int out_len = n + m - 1;
    double C[out_len];

    convolve(A, m, B, n, C);

    printf("Convolution Vector C: ");
    for (int i = 0; i < out_len; i++) printf("%.1f ", C[i]);
    printf("\n");
    return 0;
}