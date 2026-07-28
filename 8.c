#include <stdio.h>

int main()
{
    int graph[10][10], visited[10] = {0};
    int n, i, j, edge = 1, min, minCost = 0;
    int from, to;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = 999;
        }

    visited[1] = 1;

    while (edge < n)
    {
        min = 999;

        for (i = 1; i <= n; i++)
            if (visited[i] == 1)
                for (j = 1; j <= n; j++)
                    if (visited[j] == 0 && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        from = i;
                        to = j;
                    }

        printf("Edge %d : (%d-%d) Cost = %d\n", edge++, from, to, min);

        minCost += min;
        visited[to] = 1;
        graph[from][to] = graph[to][from] = 999;
    }

    printf("Minimum Cost = %d", minCost);

    return 0;
}