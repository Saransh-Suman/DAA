#include <stdio.h>

void topoSort(int graph[20][20], int n)
{
    int topo[20], indegree[20] = {0}, stack[20], visited[20] = {0};
    int i, j, top = 0, node, index = 1;

    // Find indegree of each vertex
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(graph[i][j] == 1)
                indegree[j]++;

    printf("Indegree: ");
    for(i=1;i<=n;i++)
        printf("%d ", indegree[i]);

    // Push all vertices having indegree 0
    for(i=1;i<=n;i++)
        if(indegree[i]==0)
        {
            stack[++top]=i;
            visited[i]=1;
        }

    // Topological Sorting
    while(top)
    {
        node=stack[top--];
        topo[index++]=node;

        for(j=1;j<=n;j++)
            if(graph[node][j] && !visited[j])
            {
                indegree[j]--;
                if(indegree[j]==0)
                {
                    stack[++top]=j;
                    visited[j]=1;
                }
            }
    }

    printf("\nTopological Order: ");
    for(i=1;i<=n;i++)
        printf("%d ", topo[i]);
}

int main()
{
    int graph[20][20], n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&graph[i][j]);

    topoSort(graph,n);
}