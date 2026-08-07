#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Regular Merge Sort
int* mergeTwoArrays(int* arr1, int n1, int* arr2, int n2) {
    int* result = (int*)malloc((n1 + n2) * sizeof(int));
    int i = 0, j = 0, idx = 0;
    
    // Worst-case merge requires comparing almost every element
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            result[idx++] = arr1[i++];
        } else {
            result[idx++] = arr2[j++];
        }
    }
    while (i < n1) result[idx++] = arr1[i++];
    while (j < n2) result[idx++] = arr2[j++];
    
    return result;
}

/* ========================================================================= */
/* METHOD 1: Sequential Merging - O(n * k^2)                                 */
/* ========================================================================= */
int* mergeMethod1(int** arrays, int k, int n) {
    if (k == 0) return NULL;
    
    int* current = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) current[i] = arrays[0][i];
    int currentSize = n;

    for (int i = 1; i < k; i++) {
        int* next = mergeTwoArrays(current, currentSize, arrays[i], n);
        free(current); 
        current = next;
        currentSize += n;
    }
    
    return current;
}

/* ========================================================================= */
/* METHOD 2: Pairwise Divide & Conquer - O(n * k log k)                      */
/* ========================================================================= */
int* mergeMethod2Rec(int** arrays, int left, int right, int n, int* returnSize) {
    if (left == right) {
        int* res = (int*)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++) res[i] = arrays[left][i];
        *returnSize = n;
        return res;
    }
    
    if (left < right) {
        int mid = left + (right - left) / 2;
        int sizeLeft, sizeRight;
        
        int* leftMerged = mergeMethod2Rec(arrays, left, mid, n, &sizeLeft);
        int* rightMerged = mergeMethod2Rec(arrays, mid + 1, right, n, &sizeRight);
        
        int* finalMerged = mergeTwoArrays(leftMerged, sizeLeft, rightMerged, sizeRight);
        
        free(leftMerged);
        free(rightMerged);
        
        *returnSize = sizeLeft + sizeRight;
        return finalMerged;
    }
    return NULL;
}

int* mergeMethod2(int** arrays, int k, int n) {
    if (k == 0) return NULL;
    int totalSize;
    return mergeMethod2Rec(arrays, 0, k - 1, n, &totalSize);
}


/* ========================================================================= */
/* BENCHMARK FUNCTION                                                        */
/* ========================================================================= */
void benchmark_complexity() {
    int n = 500; // Fixed size for each array
    int k_values[] = {100, 500, 1000, 2000, 4000}; // Scaling k
    int num_tests = sizeof(k_values) / sizeof(k_values[0]);

    printf("\n--- EFFICIENCY BENCHMARK ---\n");
    printf("Fixed elements per array (n) = %d\n", n);
    printf("Scaling number of arrays (k) to show O(n*k^2) vs O(n*k log k)\n\n");
    
    printf("%-10s | %-20s | %-20s\n", "k (Arrays)", "Method 1 Time (s)", "Method 2 Time (s)");
    printf("--------------------------------------------------------------\n");

    for (int t = 0; t < num_tests; t++) {
        int k = k_values[t];
        
        // Allocate worst-case interleaved arrays
        int** arrays = (int**)malloc(k * sizeof(int*));
        for (int i = 0; i < k; i++) {
            arrays[i] = (int*)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) {
                // Generates interleaved values: 
                // Arr 1: 1, k+1, 2k+1... | Arr 2: 2, k+2, 2k+2...
                arrays[i][j] = i + (j * k); 
            }
        }
        
        clock_t start, end;
        
        // Benchmark Method 1
        start = clock();
        int* res1 = mergeMethod1(arrays, k, n);
        end = clock();
        double time1 = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        // Benchmark Method 2
        start = clock();
        int* res2 = mergeMethod2(arrays, k, n);
        end = clock();
        double time2 = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        printf("%-10d | %-20f | %-20f\n", k, time1, time2);
        
        // Cleanup
        free(res1);
        free(res2);
        for (int i = 0; i < k; i++) free(arrays[i]);
        free(arrays);
    }
    printf("\n");
}


/* ========================================================================= */
/* MAIN METHOD                                                               */
/* ========================================================================= */
void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d%s", arr[i], (i == size - 1) ? "" : ", ");
    }
    printf("]\n");
}

int main() {
    // 1. Simple Correctness Test
    int k = 4;
    int n = 3;

    int** arrays = (int**)malloc(k * sizeof(int*));
    for (int i = 0; i < k; i++) arrays[i] = (int*)malloc(n * sizeof(int));

    int data[4][3] = { {1, 5, 9}, {2, 6, 10}, {3, 7, 11}, {4, 8, 12} };
    
    printf("--- CORRECTNESS TEST ---\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) arrays[i][j] = data[i][j];
        printf("Array %d: ", i + 1);
        printArray(arrays[i], n);
    }

    int* result1 = mergeMethod1(arrays, k, n);
    printf("\nMethod 1 (Sequential) Result:\n");
    printArray(result1, k * n);
    
    int* result2 = mergeMethod2(arrays, k, n);
    printf("Method 2 (Divide & Conquer) Result:\n");
    printArray(result2, k * n);

    free(result1); free(result2);
    for (int i = 0; i < k; i++) free(arrays[i]);
    free(arrays);

    // 2. Execute Complexity Benchmark
    benchmark_complexity();

    return 0;
}
