#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n,a[20][20],indeg[20],t[20];
    int i,j,k=1;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix: \n");
    for(int i = 1; i<=n; i++){
        for(j = 1; j<=n; j++)
            scanf("%d",&a[i][j]);
    }

    // Find indegree
    for(i = 1; i<=n; i++){
        for(j = 1; j<=n; j++){
            if(a[j][i] == 1){
                indeg[i]++;
            }
        }
    }
    return 0;
}
