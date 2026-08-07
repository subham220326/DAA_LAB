#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

/* ========================================================================= */
/* 1. REGULAR MERGE SORT (2-WAY)                                             */
/* ========================================================================= */
void merge2(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = malloc((n1 + 1) * sizeof(int));
    int *R = malloc((n2 + 1) * sizeof(int));
    
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    L[n1] = INT_MAX; 
    R[n2] = INT_MAX;
    
    int i = 0, j = 0;
    for (int k = l; k <= r; k++) {
        if (L[i] <= R[j]) arr[k] = L[i++];
        else              arr[k] = R[j++];
    }
    free(L); 
    free(R);
}

void mergeSort2(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort2(arr, l, m);
        mergeSort2(arr, m + 1, r);
        merge2(arr, l, m, r);
    }
}

/* ========================================================================= */
/* 2. MODIFIED MERGE SORT (3-WAY)                                            */
/* ========================================================================= */
void merge3(int arr[], int l, int mid1, int mid2, int r) {
    int n1 = mid1 - l + 1;
    int n2 = mid2 - mid1;
    int n3 = r - mid2;
    
    int *L = malloc((n1 + 1) * sizeof(int));
    int *M = malloc((n2 + 1) * sizeof(int));
    int *R = malloc((n3 + 1) * sizeof(int));
    
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) M[i] = arr[mid1 + 1 + i];
    for (int i = 0; i < n3; i++) R[i] = arr[mid2 + 1 + i];
    
    L[n1] = INT_MAX; 
    M[n2] = INT_MAX; 
    R[n3] = INT_MAX;
    
    int i = 0, j = 0, p = 0;
    for (int k = l; k <= r; k++) {
        if (L[i] <= M[j] && L[i] <= R[p])      arr[k] = L[i++];
        else if (M[j] <= L[i] && M[j] <= R[p]) arr[k] = M[j++];
        else                                   arr[k] = R[p++];
    }
    free(L); 
    free(M); 
    free(R);
}

void mergeSort3(int arr[], int l, int r) {
    if (l >= r) return; // Base case
    
    int mid1 = l + (r - l) / 3;
    int mid2 = l + 2 * (r - l) / 3;
    
    mergeSort3(arr, l, mid1);
    if (mid1 + 1 <= mid2) mergeSort3(arr, mid1 + 1, mid2);
    if (mid2 + 1 <= r)    mergeSort3(arr, mid2 + 1, r);
    
    merge3(arr, l, mid1, mid2, r);
}

/* ========================================================================= */
/* 3. BENCHMARK & SVG GRAPH GENERATOR                                        */
/* ========================================================================= */
void generate_svg(const char* filename) {
    // ---------------------------------------------------------
    // Phase A: Run Efficiency Benchmark
    // ---------------------------------------------------------
    int start_N = 10000;
    int end_N = 200000;
    int step = 20000;
    int count = (end_N - start_N) / step + 1;
    
    int *sizes = malloc(count * sizeof(int));
    double *times2 = malloc(count * sizeof(double));
    double *times3 = malloc(count * sizeof(double));
    
    printf("--- EFFICIENCY BENCHMARK (Large Datasets) ---\n");
    printf("%-10s | %-15s | %-15s\n", "Size (N)", "2-Way Time (s)", "3-Way Time (s)");
    printf("-----------------------------------------------\n");
    
    int index = 0;
    for (int N = start_N; N <= end_N; N += step) {
        int *b_arr2 = malloc(N * sizeof(int));
        int *b_arr3 = malloc(N * sizeof(int));
        
        // Populate random arrays identically
        for (int i = 0; i < N; i++) {
            int val = rand() % 100000;
            b_arr2[i] = val;
            b_arr3[i] = val;
        }
        clock_t start, end;
        
        // Time 2-Way
        start = clock();
        mergeSort2(b_arr2, 0, N - 1);
        end = clock();
        times2[index] = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        // Time 3-Way
        start = clock();
        mergeSort3(b_arr3, 0, N - 1);
        end = clock();
        times3[index] = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        printf("%-10d | %-15f | %-15f\n", N, times2[index], times3[index]);
        
        sizes[index] = N;
        index++;
        
        free(b_arr2); 
        free(b_arr3);
    }
    
    // ---------------------------------------------------------
    // Phase B: Generate SVG File
    // ---------------------------------------------------------
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Error creating SVG file!\n");
        free(sizes); free(times2); free(times3);
        return;
    }

    // Find max time to scale the graph vertically
    double max_time = 0.001; 
    for (int i = 0; i < count; i++) {
        if (times2[i] > max_time) max_time = times2[i];
        if (times3[i] > max_time) max_time = times3[i];
    }

    fprintf(f, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"900\" height=\"600\">\n");
    fprintf(f, "  <rect width=\"100%%\" height=\"100%%\" fill=\"#1e1e1e\"/>\n");
    
    // Draw Grid
    for (int i = 50; i <= 800; i += 75) {
        fprintf(f, "  <line x1=\"50\" y1=\"%d\" x2=\"850\" y2=\"%d\" stroke=\"#333\" stroke-width=\"1\"/>\n", i, i);
        fprintf(f, "  <line x1=\"%d\" y1=\"50\" x2=\"%d\" y2=\"550\" stroke=\"#333\" stroke-width=\"1\"/>\n", i, i);
    }

    // Draw Axes & Labels
    fprintf(f, "  <line x1=\"50\" y1=\"550\" x2=\"850\" y2=\"550\" stroke=\"white\" stroke-width=\"2\"/>\n");
    fprintf(f, "  <line x1=\"50\" y1=\"50\" x2=\"50\" y2=\"550\" stroke=\"white\" stroke-width=\"2\"/>\n");
    fprintf(f, "  <text x=\"400\" y=\"590\" fill=\"white\" font-family=\"sans-serif\" font-size=\"16\">Array Size (N)</text>\n");
    fprintf(f, "  <text x=\"20\" y=\"350\" fill=\"white\" font-family=\"sans-serif\" font-size=\"16\" transform=\"rotate(-90 20,350)\">Time (Seconds)</text>\n");
    fprintf(f, "  <text x=\"50\" y=\"30\" fill=\"white\" font-family=\"sans-serif\" font-size=\"20\" font-weight=\"bold\">Efficiency: 2-Way vs 3-Way Merge Sort</text>\n");

    // Plot 2-Way Merge Sort (Blue line)
    fprintf(f, "  <polyline fill=\"none\" stroke=\"#60a5fa\" stroke-width=\"4\" stroke-linejoin=\"round\" points=\"");
    for (int i = 0; i < count; i++) {
        int x = 50 + (int)(((double)sizes[i] / sizes[count-1]) * 800);
        int y = 550 - (int)((times2[i] / max_time) * 500);
        fprintf(f, "%d,%d ", x, y);
    }
    fprintf(f, "\"/>\n");

    // Plot 3-Way Merge Sort (Red line)
    fprintf(f, "  <polyline fill=\"none\" stroke=\"#f87171\" stroke-width=\"4\" stroke-linejoin=\"round\" points=\"");
    for (int i = 0; i < count; i++) {
        int x = 50 + (int)(((double)sizes[i] / sizes[count-1]) * 800);
        int y = 550 - (int)((times3[i] / max_time) * 500);
        fprintf(f, "%d,%d ", x, y);
    }
    fprintf(f, "\"/>\n");

    // Add Legend
    fprintf(f, "  <rect x=\"80\" y=\"60\" width=\"250\" height=\"80\" fill=\"#2d2d2d\" stroke=\"#555\" rx=\"5\"/>\n");
    fprintf(f, "  <text x=\"100\" y=\"90\" fill=\"#60a5fa\" font-family=\"sans-serif\" font-size=\"16\" font-weight=\"bold\">2-Way Merge Sort</text>\n");
    fprintf(f, "  <text x=\"100\" y=\"120\" fill=\"#f87171\" font-family=\"sans-serif\" font-size=\"16\" font-weight=\"bold\">3-Way Merge Sort</text>\n");

    fprintf(f, "</svg>\n");
    fclose(f);
    
    // Clean up arrays after file is written
    free(sizes); 
    free(times2); 
    free(times3);

    printf("\n--> SVG graph generated as '%s'. Open in your browser.\n", filename);
}

/* ========================================================================= */
/* 4. MAIN METHOD & TEST RUNNER                                              */
/* ========================================================================= */
void print_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d%s", arr[i], i == size - 1 ? "" : ", ");
    }
    printf("]\n");
}

int main() {
    // ---------------------------------------------------------
    // PART 1: Output Display 
    // ---------------------------------------------------------
    int small_size = 15;
    int arr_orig[] = {45, 12, 89, 33, 7, 99, 1, 56, 23, 67, 88, 4, 19, 72, 10};
    int arr2[15], arr3[15];
    
    for (int i = 0; i < small_size; i++) {
        arr2[i] = arr_orig[i];
        arr3[i] = arr_orig[i];
    }

    printf("--- CORRECTNESS TEST (Small Array) ---\n");
    printf("Original Array : ");
    print_array(arr_orig, small_size);

    clock_t start, end;

    // Test 2-way
    start = clock();
    mergeSort2(arr2, 0, small_size - 1);
    end = clock();
    printf("2-Way Sorted   : ");
    print_array(arr2, small_size);
    printf("  -> Time taken: %f seconds\n\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Test 3-way
    start = clock();
    mergeSort3(arr3, 0, small_size - 1);
    end = clock();
    printf("3-Way Sorted   : ");
    print_array(arr3, small_size);
    printf("  -> Time taken: %f seconds\n\n", ((double)(end - start)) / CLOCKS_PER_SEC);


    // ---------------------------------------------------------
    // PART 2: Efficiency Benchmark & SVG Generation
    // ---------------------------------------------------------
    generate_svg("mergesort_comparison.svg");
    
    return 0;
}
