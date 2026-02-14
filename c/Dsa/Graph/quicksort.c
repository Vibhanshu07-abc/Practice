#include <stdio.h>

// swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition using pivot = arr[lb] (Hoare-style but we place pivot at arr[end])
int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while (start < end) {
        // move start forward until an element > pivot is found
        while (start <= ub && arr[start] <= pivot)
            start++;
        // move end backward until an element <= pivot is found
        while (end >= lb && arr[end] > pivot)
            end--;
        if (start < end) {
            swap(&arr[start], &arr[end]);
        }
    }

    // put pivot in its correct position (arr[end])
    swap(&arr[lb], &arr[end]);
    return end; // return pivot final position
}

void quicksort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(arr, lb, ub);
        // left: lb .. loc-1, right: loc+1 .. ub
        quicksort(arr, lb, loc - 1);
        quicksort(arr, loc + 1, ub);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
