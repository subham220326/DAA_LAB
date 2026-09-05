#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define N 3

void matrixAdd(double A[N][N], double B[N][N], double C[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void matrixMultiply(double A[N][N], double B[N][N], double C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

bool isZeroMatrix(double A[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (fabs(A[i][j]) > 1e-9) return false;
    return true;
}

bool isSymmetric(double A[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (fabs(A[i][j] - A[j][i]) > 1e-9) return false;
    return true;
}

void transposeInPlace(double A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}

double computeDeterminant(double mat[N][N]) {
    double A[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) A[i][j] = mat[i][j];

    double det = 1.0;
    for (int i = 0; i < N; i++) {
        int pivot = i;
        for (int k = i + 1; k < N; k++)
            if (fabs(A[k][i]) > fabs(A[pivot][i])) pivot = k;

        if (fabs(A[pivot][i]) < 1e-9) return 0.0;

        if (pivot != i) {
            for (int k = 0; k < N; k++) {
                double temp = A[i][k];
                A[i][k] = A[pivot][k];
                A[pivot][k] = temp;
            }
            det = -det;
        }
        det *= A[i][i];
        for (int k = i + 1; k < N; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i + 1; j < N; j++)
                A[k][j] -= factor * A[i][j];
        }
    }
    return det;
}

// Power Iteration for Dominant Eigenvalue and Eigenvector
void dominantEigen(double A[N][N], double *lambda, double v[N], int max_iter) {
    for (int i = 0; i < N; i++) v[i] = 1.0;

    for (int it = 0; it < max_iter; it++) {
        double w[N] = {0};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                w[i] += A[i][j] * v[j];

        double norm = 0;
        for (int i = 0; i < N; i++) norm += w[i] * w[i];
        norm = sqrt(norm);

        for (int i = 0; i < N; i++) v[i] = w[i] / norm;

        // Rayleigh quotient
        double Av[N] = {0};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                Av[i] += A[i][j] * v[j];

        *lambda = 0;
        for (int i = 0; i < N; i++) *lambda += v[i] * Av[i];
    }
}

int main() {
    double A[N][N] = {{4, 1, 1}, {1, 3, -1}, {1, -1, 2}};
    printf("Is Symmetric: %s\n", isSymmetric(A) ? "Yes" : "No");
    printf("Determinant: %.2f\n", computeDeterminant(A));

    double lambda, v[N];
    dominantEigen(A, &lambda, v, 100);
    printf("Dominant Eigenvalue: %.4f\n", lambda);
    printf("Eigenvector: [%.4f, %.4f, %.4f]\n", v[0], v[1], v[2]);
    return 0;
}