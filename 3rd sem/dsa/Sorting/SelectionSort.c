#include <stdio.h>

#define MAX_SIZE 100  // Maximum size of the array

int main() {
  int arr[MAX_SIZE];  // Declare an array of integers
  int size;           // Size of the array
  int i, j, min, temp;  // Loop variables

  // Read the size of the array
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Read the elements of the array
  printf("Enter %d elements: ", size);
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  // Perform selection sort
  for (i = 0; i < size - 1; i++) {
    // Find the minimum element in the unsorted array
    min = i;
    for (j = i + 1; j < size; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }

    // Swap the minimum element with the first element of the unsorted array
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }

  // Print the sorted array
  printf("Sorted array: ");
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
