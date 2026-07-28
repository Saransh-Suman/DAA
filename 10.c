#include <stdio.h>
#define INF 999

void dijkstra(int graph[10][10], int n, int src, int dist[])
{
    int visited[10] = {0}, i, j, min, next;

    for(i=1;i<=n;i++)
        dist[i]=graph[src][i];

    visited[src]=1;
    dist[src]=0;

    for(i=1;i<n;i++)
    {
        min=INF;

        for(j=1;j<=n;j++)
            if(!visited[j] && dist[j]<min)
            {
                min=dist[j];
                next=j;
            }

        visited[next]=1;

        for(j=1;j<=n;j++)
            if(!visited[j] && dist[next]+graph[next][j]<dist[j])
                dist[j]=dist[next]+graph[next][j];
    }
}

int main()
{
    int graph[10][10], dist[10], n, src, i, j;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d",&src);

    dijkstra(graph,n,src,dist);

    for(i=1;i<=n;i++)
        printf("Distance from %d to %d = %d\n",src,i,dist[i]);

    return 0;
}