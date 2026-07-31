#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int bubbleSortUnoptimized(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return comparisons;
}


int bubbleSortOptimized(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0) {
            break;
        }
    }
    return comparisons;
}


void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

int main() {
    int n = 50;
    int original[50], test1[50], test2[50];
    int comp_opt, comp_unopt;
    
    printf("--- BUBBLE SORT ANALYSIS (Array Size: %d) ---\n\n", n);

   

    for (int i = 0; i < n; i++) original[i] = i; 
    copyArray(original, test1, n);
    copyArray(original, test2, n);
    
    comp_unopt = bubbleSortUnoptimized(test1, n);
    comp_opt = bubbleSortOptimized(test2, n);
    
    printf("1. BEST CASE (Already Sorted)\n");
    printf("Unoptimized Comparisons: %d\n", comp_unopt);
    printf("Optimized Comparisons:   %d\n\n", comp_opt);




    for (int i = 0; i < n; i++) original[i] = n - i;
    copyArray(original, test1, n);
    copyArray(original, test2, n);
    
    comp_unopt = bubbleSortUnoptimized(test1, n);
    comp_opt = bubbleSortOptimized(test2, n);
    
    printf("2. WORST CASE (Reverse Sorted)\n");
    printf("Unoptimized Comparisons: %d\n", comp_unopt);
    printf("Optimized Comparisons:   %d\n\n", comp_opt);

  
    
    srand(time(NULL));
    for (int i = 0; i < n; i++) original[i] = rand() % 100;
    copyArray(original, test1, n);
    copyArray(original, test2, n);
    
    comp_unopt = bubbleSortUnoptimized(test1, n);
    comp_opt = bubbleSortOptimized(test2, n);
    
    printf("3. AVERAGE CASE (Random Array)\n");
    printf("Unoptimized Comparisons: %d\n", comp_unopt);
    printf("Optimized Comparisons:   %d\n\n", comp_opt);

    return 0;
}
