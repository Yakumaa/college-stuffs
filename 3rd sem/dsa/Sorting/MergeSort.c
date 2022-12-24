#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Maximum size of the array

// Function prototypes
void merge_sort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

int main() {
  int arr[MAX_SIZE];  // Declare an array of integers
  int size;           // Size of the array
  int i;              // Loop variable

  // Read the size of the array
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Read the elements of the array
  printf("Enter %d elements: ", size);
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  // Sort the array using merge sort
  merge_sort(arr, 0, size - 1);

  // Print the sorted array
  printf("Sorted array: ");
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

// Merge sort function
void merge_sort(int arr[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

// Merge function
void merge(int arr[], int low, int mid, int high) {
  int i, j, k;
  int n1 = mid - low + 1;
  int n2 = high - mid;

  // Create temporary arrays
  int left[n1], right[n2];

  // Copy data to temporary arrays
  for (i = 0; i < n1; i++) {
    left[i] = arr[low + i];
  }
  for (j = 0; j < n2; j++) {
    right[j] = arr[mid + 1 + j];
  }

  // Merge the temporary arrays back into arr[low..high]
  i = 0;  // Initial index of first subarray
  j = 0;  // Initial index of second subarray
  k = low;  // Initial index of merged subarray
  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
        arr[k] = left[i];
        i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of left[], if there are any
  while (i < n1) {
    arr[k] = left[i];
    i++;
    k++;
  }

  // Copy the remaining elements of right[], if there are any
  while (j < n2) {
    arr[k] = right[j];
    j++;
    k++;
  }
}
