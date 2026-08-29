#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n = 100;
    FILE *fp = fopen("input.txt", "w");
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", rand() % 10000);
    }
    fclose(fp);

    fp = fopen("input.txt", "r");
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    heapSort(arr, n);

    FILE *out = fopen("sorted_heap.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(out, "%d ", arr[i]);
    }
    fclose(out);
    free(arr);

    printf("Heap Sort completed. Output written to sorted_heap.txt\n");
    return 0;
}