#include <stdio.h>


int findPartitionBinary(int arr[], int n, int *steps) {
    int low = 0, high = n - 1;
    *steps = 0;
    
    while (low <= high) {
        (*steps)++;
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == 1 && (mid == 0 || arr[mid - 1] == 0)) {
            return mid;
        } 
        else if (arr[mid] == 0) {
            low = mid + 1; 
        } 
        else {
            high = mid - 1; 
        }
    }
    return -1;
}

int main() {

    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int binary_steps = 0;
    
    int binary_index = findPartitionBinary(arr, n, &binary_steps);
    
    printf("--- PARTITION POINT ANALYSIS ---\n\n");
    
    printf("Array: [ ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
    printf("Index:   ");
    for(int i = 0; i < n; i++) {
        if(i < 10) printf("%d ", i);
        else printf("%d ", i);
    }
    printf("\n\n");
    

    
    printf(" Binary Search Results:\n");
    printf("Partition found at index: %d\n", binary_index);
    printf("Total steps required: %d\n\n", binary_steps);
    
    return 0;
}
