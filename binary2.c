#include <stdio.h>

int binarySearch(int arr[], int beg, int end, int key)
{
    if (beg > end)
        return -1;

    int mid = beg + (end - beg) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return binarySearch(arr, beg, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, end, key);
}

int main()
{
    int n, key, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("Element found at position %d\n", result + 1);
    else
        printf("Element not found\n");

    return 0;
}