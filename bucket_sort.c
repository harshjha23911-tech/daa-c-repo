#include <stdio.h>
#define BUCKETS 10
void insertionSort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int n, i, j, index, k = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    int bucket[BUCKETS][n];
    int count[BUCKETS] = {0};
    printf("Enter elements (0 to 99): ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        index = a[i] / 10;
        bucket[index][count[index]++] = a[i];
    }
    for (i = 0; i < BUCKETS; i++)
        insertionSort(bucket[i], count[i]);
    for (i = 0; i < BUCKETS; i++)
    {
        for (j = 0; j < count[i]; j++)
            a[k++] = bucket[i][j];
    }
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}