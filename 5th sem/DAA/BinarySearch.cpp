/*
 * Program: Binary Search Program
*/

#include <iostream>
using namespace std;

int binarySearch(int[], int, int);

int main()
{

    int n, key, index;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array in ascending order: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the key to search: ";
    cin >> key;

    index = binarySearch(arr, n, key);

    index == -1 ? cout << "Key not found" : cout << "Key found at position " << index + 1;

    return 0;
}

/*
 * This function searches for a key in an array using binary search algorithm
 *
 * @param arr[] - array to be searched
 * @param size - size of the array
 * @param key - key to be searched
 *
 * @returns index of the key if found, else -1
 */
int binarySearch(int arr[], int size, int key)
{
    int low = 0, high = size - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
    }
    return -1;
}


