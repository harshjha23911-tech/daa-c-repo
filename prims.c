#include <stdio.h>
#define MAX 20
int main()
{
    int n, e;
    int u[MAX], v[MAX], w[MAX];
    int visited[MAX] = {0};
    int i, j;
    int min, x, y;
    int edges = 0, total = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (source destination weight):\n");
    for (i = 0; i < e; i++)
    {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }
    visited[0] = 1;
    printf("\nEdges in MST:\n");
    while (edges < n - 1)
    {
        min = 9999;
        for (i = 0; i < e; i++)
        {
            if (visited[u[i]] && !visited[v[i]])
            {
                if (w[i] < min)
                {
                    min = w[i];
                    x = u[i];
                    y = v[i];
                }
            }
            if (visited[v[i]] && !visited[u[i]])
            {
                if (w[i] < min)
                {
                    min = w[i];
                    x = v[i];
                    y = u[i];
                }
            }
        }
        printf("%d - %d : %d\n", x, y, min);
        visited[y] = 1;
        total += min;
        edges++;
    }
    printf("Minimum Cost = %d\n", total);
    return 0;
}