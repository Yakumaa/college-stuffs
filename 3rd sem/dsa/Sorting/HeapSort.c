#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Maximum size of the array

// Function prototypes
void heap_sort(int arr[], int size);
void build_max_heap(int arr[], int size);
void max_heapify(int arr[], int size, int i);

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

  // Sort the array using heap sort
  heap_sort(arr, size);

  // Print the sorted array
  printf("Sorted array: ");
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

// Heap sort function
void heap_sort(int arr[], int size) {
  build_max_heap(arr, size);
  int i;
  for (i = size - 1; i >= 1; i--) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    size--;
    max_heapify(arr, size, 0);
  }
}

// Build max heap function
void build_max_heap(int arr[], int size) {
  int i;
  for (i = size / 2; i >= 0; i--) {
    max_heapify(arr, size, i);
  }
}

// Max heapify function
void max_heapify(int arr[], int size, int i) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int largest = i;
  if (l < size && arr[l] > arr[largest]) {
    largest = l;
  }
  if (r < size && arr[r] > arr[largest]) {
    largest = r;
  }
  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    max_heapify(arr, size, largest);
  }
}

