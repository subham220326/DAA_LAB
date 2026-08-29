#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int kthSmallest(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int pi = partition(arr, low, high);
        if (pi - low == k - 1)
            return arr[pi];
        if (pi - low > k - 1)
            return kthSmallest(arr, low, pi - 1, k);
        return kthSmallest(arr, pi + 1, high, k - (pi - low + 1));
    }
    return -1;
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    int k = 3;
    printf("\n%d-th smallest element: %d\n", k, kthSmallest(arr, 0, n - 1, k));
    return 0;
}