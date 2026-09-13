#include <stdio.h>
struct Item
{
    int weight;
    int profit;
    float ratio;
};
int main()
{
    int n, i, j, capacity;
    float total = 0;
    struct Item item[100], temp;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weight and profit of each item:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &item[i].weight, &item[i].profit);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (item[i].ratio < item[j].ratio)
            {
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (capacity >= item[i].weight)
        {
            total += item[i].profit;
            capacity -= item[i].weight;
        }
        else
        {
            total += item[i].ratio * capacity;
            break;
        }
    }
    printf("Maximum Profit = %.2f\n", total);
    return 0;
}