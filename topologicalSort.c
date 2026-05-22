#include <stdio.h>

int main()
{
    int a[20][20], indeg[20], t[20];
    int n, i, j, k = 1;

    printf("Enter the number of nodes\n");
    scanf("%d", &n);

    printf("Enter Adjacency matrix\n");

    // Input adjacency matrix
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Find indegree
    for(i = 1; i <= n; i++)
    {
        indeg[i] = 0;

        for(j = 1; j <= n; j++)
        {
            if(a[j][i] == 1)
                indeg[i]++;
        }
    }

    // Print indegree array
    printf("Indegree Array:");

    for(i = 1; i <= n; i++)
        printf("%d ", indeg[i]);

    // Topological Sorting
    printf("\nTopological Ordering is:");

    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            if(indeg[i] == 0)
            {
                printf("%d ", i);

                indeg[i] = -1;

                for(j = 1; j <= n; j++)
                {
                    if(a[i][j] == 1)
                        indeg[j]--;
                }
            }
        }
    }

    return 0;
}