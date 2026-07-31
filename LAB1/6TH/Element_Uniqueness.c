#include <stdio.h>
#include <stdlib.h>

int checkUniqueOptimized(int arr[], int n, int *comparisons) {
    *comparisons = 0;

    int seen[100] = {0}; 
    
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (seen[arr[i]] == 1) {
            return 0; 
        }
        seen[arr[i]] = 1; 
    }
    return 1; 
}

int main() {

    int arr[] = {12, 45, 7, 89, 23, 56, 34, 91, 18, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int brute_steps = 0, opt_steps = 0;
    
    printf("--- ELEMENT UNIQUENESS ANALYSIS ---\n\n");
    
    printf("Array: [ ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n\n");
    
 
    
    printf("Optimized Hash Search:\n");
    int isUnique2 = checkUniqueOptimized(arr, n, &opt_steps);
    printf("Status: %s\n", isUnique2 ? "All elements are unique" : "Contains duplicates");
    printf("Total array checks required: %d\n\n", opt_steps);
    
    return 0;
}
