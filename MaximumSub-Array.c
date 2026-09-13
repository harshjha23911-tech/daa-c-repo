#include <stdio.h>
int max(int a, int b)
{
    return a > b ? a : b;
}
int maxCrossing(int a[], int low, int mid, int high)
{
    int leftSum = -999999, rightSum = -999999, sum = 0, i;
    for (i = mid; i >= low; i--)
    {
        sum += a[i];
        if (sum > leftSum)
            leftSum = sum;
    }
    sum = 0;
    for (i = mid + 1; i <= high; i++)
    {
        sum += a[i];
        if (sum > rightSum)
            rightSum = sum;
    }
    return leftSum + rightSum;
}
int maxSubarray(int a[], int low, int high)
{
    int mid, left, right, cross;
    if (low == high)
        return a[low];
    mid = (low + high) / 2;
    left = maxSubarray(a, low, mid);
    right = maxSubarray(a, mid + 1, high);
    cross = maxCrossing(a, low, mid, high);
    return max(max(left, right), cross);
}
int main()
{
    int n, a[100], i, result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    result = maxSubarray(a, 0, n - 1);
    printf("Maximum Subarray Sum = %d\n", result);
    return 0;
}