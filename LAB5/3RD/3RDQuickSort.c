#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void generateRandomFile(const char *filename, int n) {
    FILE *fp = fopen(filename, "w");
    if (!fp) return;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", rand() % 10000);
    }
    fclose(fp);
}

int main() {
    int n = 100;
    generateRandomFile("input.txt", n);

    FILE *fp = fopen("input.txt", "r");
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    quickSort(arr, 0, n - 1);

    FILE *out = fopen("sorted_quick.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(out, "%d ", arr[i]);
    }
    fclose(out);
    free(arr);

    printf("Quick Sort completed. Output written to sorted_quick.txt\n");
    return 0;
}