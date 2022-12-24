#include <stdio.h>

#define MAX_SIZE 100  // Maximum size of the array

int main() {
  int arr[MAX_SIZE];  // Declare an array of integers
  int size;           // Size of the array
  int i, j, temp;     // Loop variables

  // Read the size of the array
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Read the elements of the array
  printf("Enter %d elements: ", size);
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  // Perform bubble sort
  for (i = 0; i < size; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Swap the elements
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  // Print the sorted array
  printf("Sorted array: ");
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
