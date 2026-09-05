#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int findMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

void findFirstSecondLargest(int arr[], int n, int *first, int *second) {
    *first = arr[0] > arr[1] ? arr[0] : arr[1];
    *second = arr[0] > arr[1] ? arr[1] : arr[0];
    for (int i = 2; i < n; i++) {
        if (arr[i] > *first) {
            *second = *first;
            *first = arr[i];
        } else if (arr[i] > *second && arr[i] != *first) {
            *second = arr[i];
        }
    }
}

double findMean(int arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum / n;
}

double findStdDev(int arr[], int n, double mean) {
    double sq_diff = 0;
    for (int i = 0; i < n; i++)
        sq_diff += (arr[i] - mean) * (arr[i] - mean);
    return sqrt(sq_diff / n);
}

int cmpInt(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int findMedian(int arr[], int n) {
    int *temp = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    qsort(temp, n, sizeof(int), cmpInt);
    int med = temp[n / 2];
    free(temp);
    return med;
}

int findMode(int arr[], int n) {
    int *temp = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    qsort(temp, n, sizeof(int), cmpInt);

    int mode = temp[0], max_count = 1, curr_count = 1;
    for (int i = 1; i < n; i++) {
        if (temp[i] == temp[i - 1]) curr_count++;
        else curr_count = 1;

        if (curr_count > max_count) {
            max_count = curr_count;
            mode = temp[i];
        }
    }
    free(temp);
    return mode;
}

int removeDuplicates(int arr[], int n) {
    if (n <= 1) return n;
    qsort(arr, n, sizeof(int), cmpInt);
    int j = 0;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1])
            arr[j++] = arr[i];
    arr[j++] = arr[n - 1];
    return j;
}

void reverseArray(int arr[], int n) {
    int l = 0, r = n - 1;
    while (l < r) swap(&arr[l++], &arr[r--]);
}

// Partition: Elements >= pivot appear BEFORE elements < pivot
void partitionArray(int arr[], int n, int pivot) {
    int left = 0, right = n - 1;
    while (left <= right) {
        while (left <= right && arr[left] >= pivot) left++;
        while (left <= right && arr[right] < pivot) right--;
        if (left < right) swap(&arr[left++], &arr[right--]);
    }
}

int main() {
    int arr[] = {12, 3, 5, 7, 19, 3, 5, 29, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    int first, second;
    findFirstSecondLargest(arr, n, &first, &second);
    double mean = findMean(arr, n);

    printf("Max: %d\n", findMax(arr, n));
    printf("1st Largest: %d, 2nd Largest: %d\n", first, second);
    printf("Mean: %.2f\n", mean);
    printf("Median: %d\n", findMedian(arr, n));
    printf("Std Dev: %.2f\n", findStdDev(arr, n, mean));
    printf("Mode: %d\n", findMode(arr, n));

    reverseArray(arr, n);
    printf("Reversed array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    partitionArray(arr, n, 10);
    printf("Partitioned around pivot=10 (>=10 first): ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    int new_len = removeDuplicates(arr, n);
    printf("After duplicate removal: ");
    for (int i = 0; i < new_len; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}