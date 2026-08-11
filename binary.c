#include <stdio.h>

int main() {
    int arr[100], n, key;
    int beg, end, mid, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements in sorted order:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);

    beg = 0;
    end = n - 1;

    while(beg <= end) {
        mid = (beg + end) / 2;

        if(arr[mid] == key) {
            printf("Element found at position %d.\n", mid + 1);
            return 0;
        }
        else if(arr[mid] < key) {
            beg = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    printf("Element not found.\n");

    return 0;
}