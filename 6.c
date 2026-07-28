#include <stdio.h>
#define MAX 20
int w[MAX];      // Weights
int p[MAX];      // Profits
int V[MAX][MAX]; // DP table
int Keep[MAX][MAX];
int n; // Number of objects
int M; // Knapsack capacity
void ReadObjects();
int Knapsack();
int main()
{
    int optsoln;
    ReadObjects();
    // Initialize first row and column to 0
    for (int i = 0; i <= M; i++)
        V[0][i] = 0;
    for (int i = 0; i <= n; i++)
        V[i][0] = 0;
    optsoln = Knapsack();
    printf("Optimal solution = %d\n", optsoln);
    return 0;
}
void ReadObjects()
{
    printf("Knapsack Problem - Dynamic Programming Solution:\n");
    printf("Enter the max capacity of knapsack: ");
    scanf("%d", &M);
    printf("Enter number of objects: ");
    scanf("%d", &n);
    printf("Enter Weights:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("Enter Profits:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
}
int Knapsack()
{
    int r;
    // Build table V[][] and Keep[][]
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if ((w[i] <= j) && (p[i] + V[i - 1][j - w[i]] > V[i - 1][j]))
            {
                V[i][j] = p[i] + V[i - 1][j - w[i]];
                Keep[i][j] = 1;
            }
            else
            {
                V[i][j] = V[i - 1][j];
                Keep[i][j] = 0;
            }
        }
    }
    // Find the items included in knapsack
    r = M;
    printf("Items included:\n");
    for (int i = n; i > 0; i--)
    {
        if (Keep[i][r] == 1)
        {
            printf("Item %d\n", i);
            r = r - w[i];
        }
    }
    return V[n][M];
}