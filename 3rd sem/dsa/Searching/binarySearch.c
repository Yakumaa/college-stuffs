#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] > key) {
            return binarySearch(arr, low, mid - 1, key);
        }

        return binarySearch(arr, mid + 1, high, key);
    }

    return -1;
}

int main() {
    int size, searchVal, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to search for: ");
    scanf("%d", &searchVal);

    int result = binarySearch(arr, 0, size - 1, searchVal);

    if (result == -1) {
        printf("Value not found in array\n");
    } else {
        printf("Value found at index %d\n", result);
    }

    return 0;
}
