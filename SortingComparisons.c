#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n, int *swapCount) {
    *swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swapCount)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int *swapCount) {
    *swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
            (*swapCount)++;
        }
    }
}

void insertionSort(int arr[], int n, int *swapCount) {
    *swapCount = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            (*swapCount)++;
        }
        arr[j + 1] = key;
    }
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Random numbers between 0 and 999
    }
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void compareSortingAlgorithms(int n) {
    int arr[n], temp[n];
    int swapCount;
    clock_t start, end;

    generateRandomArray(arr, n);

    // Bubble Sort
    copyArray(arr, temp, n);
    start = clock();
    bubbleSort(temp, n, &swapCount);
    end = clock();
    printf("Bubble Sort (n=%d): Time = %lf seconds, Swaps = %d\n", n, (double)(end - start) / CLOCKS_PER_SEC, swapCount);

    // Selection Sort
    copyArray(arr, temp, n);
    start = clock();
    selectionSort(temp, n, &swapCount);
    end = clock();
    printf("Selection Sort (n=%d): Time = %lf seconds, Swaps = %d\n", n, (double)(end - start) / CLOCKS_PER_SEC, swapCount);

    // Insertion Sort
    copyArray(arr, temp, n);
    start = clock();
    insertionSort(temp, n, &swapCount);
    end = clock();
    printf("Insertion Sort (n=%d): Time = %lf seconds, Swaps = %d\n", n, (double)(end - start) / CLOCKS_PER_SEC, swapCount);
}

int main() {
    srand(time(0));

    printf("Comparing sorting algorithms for arrays of size 10:\n");
    compareSortingAlgorithms(10);

    printf("\nComparing sorting algorithms for arrays of size 100:\n");
    compareSortingAlgorithms(100);

    return 0;
}