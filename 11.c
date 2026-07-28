#include <stdio.h>

int a[20], pick[20], n, target;

void subset(int index, int sum)
{
    if (sum == target)
    {
        for (int i = 0; i < n; i++)
            if (pick[i])
                printf("%d ", a[i]);
        printf("\n");
        return;
    }

    if (index == n || sum > target)
        return;

    pick[index] = 1;
    subset(index + 1, sum + a[index]);

    pick[index] = 0;
    subset(index + 1, sum);
}

int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    subset(0, 0);

    return 0;
}