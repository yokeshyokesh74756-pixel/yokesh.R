#include <stdio.h>
 
long long comparisons, moves;
 
void bubbleSort(int a[], int n) {
    comparisons = moves = 0;
    for (int pass = 0; pass < n - 1; pass++) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - pass; j++) {
            comparisons++;
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                moves++;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}
 
void selectionSort(int a[], int n) {
    comparisons = moves = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (a[j] < a[min]) min = j;
        }
        if (min != i) {
            int t = a[i]; a[i] = a[min]; a[min] = t;
            moves++;
        }
    }
}
 
void insertionSort(int a[], int n) {
    comparisons = moves = 0;
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (a[j] <= key) break;
            a[j + 1] = a[j];
            moves++;
            j--;
        }
        a[j + 1] = key;
    }
}
 
void printArray(const int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}
 
int main(void) {
    int original[] = {34, 12, 27, 8, 19, 5};
    int a[6], n = 6;
 
    for (int i = 0; i < n; i++) a[i] = original[i];
    bubbleSort(a, n);
    printf("Bubble: "); printArray(a, n);
    printf("Comparisons=%lld, swaps=%lld\n", comparisons, moves);
 
    for (int i = 0; i < n; i++) a[i] = original[i];
    selectionSort(a, n);
    printf("Selection: "); printArray(a, n);
    printf("Comparisons=%lld, swaps=%lld\n", comparisons, moves);
 
    for (int i = 0; i < n; i++) a[i] = original[i];
    insertionSort(a, n);
    printf("Insertion: "); printArray(a, n);
    printf("Comparisons=%lld, shifts=%lld\n", comparisons, moves);
    return 0;
}
