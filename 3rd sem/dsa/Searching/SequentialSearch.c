#include <stdio.h>

int main() {
    int size, searchVal, i;
    int found = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to search for: ");
    scanf("%d", &searchVal);

    for (i = 0; i < size; i++) {
        if (arr[i] == searchVal) {
            found = 1;
            break;
        }
    }

    if (found == 1) {
        printf("Value found at index %d\n", i);
    } else {
        printf("Value not found\n");
    }

    return 0;
}
