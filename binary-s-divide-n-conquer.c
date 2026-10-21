#include <stdio.h>

int binary_search(int key, int arr[], int low, int high)
{
    if(low > high)
        return -1;

    int mid = (low + high) / 2;

    if(arr[mid] == key)
        return mid;

    else if(key > arr[mid])
        return binary_search(key, arr, mid + 1, high);

    else
        return binary_search(key, arr, low, mid - 1);
}
