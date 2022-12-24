#include <stdio.h>

#define MAX_SIZE 100  // Maximum size of the array

// Function prototypes
void quick_sort(int arr[], int p, int r);
int partition(int arr[], int p, int r);

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

  // Sort the array using quick sort
  quick_sort(arr, 0, size - 1);

  // Print the sorted array
  printf("Sorted array: ");
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

// Quick sort function
void quick_sort(int arr[], int p, int r) {
  if (p < r) {
    int q = partition(arr, p, r);
    quick_sort(arr, p, q - 1);
    quick_sort(arr, q + 1, r);
  }
}

// Partition function
int partition(int arr[], int p, int r) {
  int x = arr[r];
  int i = p - 1;
  int j;
  for (j = p; j < r; j++) {
    if (arr[j] <= x) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[i + 1];
  arr[i + 1] = arr[r];
  arr[r] = temp;
  return i + 1;
}
