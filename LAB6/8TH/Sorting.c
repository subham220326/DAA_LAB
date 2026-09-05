#include <stdio.h>

long long total_reversal_cost = 0;

void reverse(int p[], int i, int j) {
    if (i >= j) return;
    total_reversal_cost += (j - i + 1);
    while (i < j) {
        int temp = p[i];
        p[i] = p[j];
        p[j] = temp;
        i++;
        j--;
    }
}

void blockSwap(int p[], int left, int mid, int right) {
    if (left > mid || mid >= right) return;
    reverse(p, left, mid);
    reverse(p, mid + 1, right);
    reverse(p, left, right);
}

int lowerBound(int p[], int left, int right, int val) {
    int l = left, r = right + 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (p[mid] >= val) r = mid;
        else l = mid + 1;
    }
    return l;
}

void inPlaceMerge(int p[], int l1, int r1, int l2, int r2) {
    if (l1 > r1 || l2 > r2) return;

    int mid1 = l1 + (r1 - l1) / 2;
    int mid2 = lowerBound(p, l2, r2, p[mid1]);


    blockSwap(p, mid1, r1, mid2 - 1);

    int new_mid = mid1 + (mid2 - l2);
    inPlaceMerge(p, l1, mid1 - 1, mid1, new_mid - 1);
    inPlaceMerge(p, new_mid + 1, r1 + (mid2 - l2), mid2, r2);
}

void mergeSortViaReversals(int p[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortViaReversals(p, left, mid);
    mergeSortViaReversals(p, mid + 1, right);
    inPlaceMerge(p, left, mid, mid + 1, right);
}

int main() {
    int p[] = {1, 4, 3, 2, 5};
    int n = sizeof(p) / sizeof(p[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) printf("%d ", p[i]);
    printf("\n");

    mergeSortViaReversals(p, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", p[i]);
    printf("\nTotal reversal cost incurred: %lld\n", total_reversal_cost);
    return 0;
}