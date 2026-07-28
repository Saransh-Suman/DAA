#include <stdio.h>
#include <stdlib.h>

int n, pos[10], count = 0;

int safe(int row, int col)
{
    for (int i = 1; i < row; i++)
        if (pos[i] == col || abs(pos[i] - col) == abs(i - row))
            return 0;
    return 1;
}

void printBoard()
{
    printf("Solution %d:\n\n", ++count);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (pos[i] == j)
                printf("Q");
            else
                printf("X");
        }
        printf("\n");
    }
}

void solve(int row)
{
    if (row > n)
    {
        printBoard();
        printf("\n");
        return;
    }

    for (int col = 1; col <= n; col++)
    {
        if (safe(row, col))
        {
            pos[row] = col;
            solve(row + 1);
        }
    }
}

int main()
{
    printf("Enter number of queens: ");
    scanf("%d", &n);

    solve(1);

    return 0;
}