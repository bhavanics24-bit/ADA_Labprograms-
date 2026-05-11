

#include <stdio.h>
#include <time.h>
#define MAX 20


int mincost;

void prims(int n, int cost[MAX][MAX], int t[MAX][2])
{
    int near[MAX];
    int i, j, k, l, min;



    min = 999;

    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                k = i;
                l = j;
            }
        }
    }

    t[1][1] = k;
    t[1][2] = l;
    mincost = cost[k][l];

    for (i = 1; i <= n; i++)
    {
        if (cost[i][k] < cost[i][l])
            near[i] = k;
        else
            near[i] = l;
    }

    near[k] = 0;
    near[l] = 0;

    for (i = 2; i <= n - 1; i++)
    {
        min = 999;

        for (j = 1; j <= n; j++)
        {
            if (near[j] != 0 && cost[j][near[j]] < min)
            {
                min = cost[j][near[j]];
                k = j;
            }
        }

        t[i][1] = k;
        t[i][2] = near[k];

        mincost = mincost + cost[k][near[k]];

        near[k] = 0;

        for (j = 1; j <= n; j++)
        {
            if (near[j] != 0 && cost[j][near[j]] > cost[j][k])
                near[j] = k;
        }
    }
}

int main()
{
    clock_t start,end;
    double time_taken;
    int n, cost[MAX][MAX], t[MAX][2];
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0 && i != j)
                cost[i][j] = 999;
        }
    }

    start=clock();
    prims(n, cost, t);
    end=clock();

    printf("\nEdges of Minimum Spanning Tree are:\n");

    for (i = 1; i <= n - 1; i++)
    {
        printf("%d -> %d\n", t[i][1], t[i][2]);
    }

    printf("\nMinimum cost = %d\n", mincost);
    time_taken=((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time:%.f",&time_taken);

    return 0;
}

