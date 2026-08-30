#include <stdio.h>
#define SIZE 100
int hashTable[SIZE];
void initialize()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}
int hash(int key)
{
    return key % SIZE;
}
int search(int key)
{
    int index = hash(key);
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
            return 1;

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }
    return 0;
}
void insert(int key)
{
    int index = hash(key);
    while (hashTable[index] != -1)
        index = (index + 1) % SIZE;
    hashTable[index] = key;
}
int main()
{
    int n, T, found = 0;
    initialize();
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter target value: ");
    scanf("%d", &T);
    for (int i = 0; i < n; i++)
    {
        int complement = T - a[i];
        if (search(complement))
        {
            printf("Elements: %d and %d\n", complement, a[i]);
            found = 1;
        }
        insert(a[i]);
    }
    if (found)
        printf("Yes, elements exist whose sum is %d\n", T);
    else
        printf("No, such two elements do not exist\n");
    return 0;
}