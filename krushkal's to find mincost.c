#include <stdio.h>
#include <time.h>

#define MAX 20
#define INF 9999

int parent[MAX];

// Find function
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union function
void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Kruskal function (same model as prims)
int kruskal(int n, int cost[MAX][MAX], int T[MAX][2]) {
    int mincost = 0;
    int edges = 0;

    // Initialize parent
    for (int i = 0; i < n; i++)
        parent[i] = i;

    while (edges < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        // Find global minimum edge
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // Check for cycle using union-find
        if (find(u) != find(v)) {
            T[edges][0] = u;
            T[edges][1] = v;

            mincost += min;
            unionSet(u, v);
            edges++;
        }

        // Remove edge after considering
        cost[u][v] = cost[v][u] = INF;
    }

    return mincost;
}

int main() {
    int n, cost[MAX][MAX], T[MAX][2];
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    start = clock();

    int mincost = kruskal(n, cost, T);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nEdges in MST (u - v):\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d - %d\n", T[i][0], T[i][1]);
    }

    printf("\nMinimum cost = %d\n", mincost);
    printf("Execution time = %f seconds\n", cpu_time_used);

    return 0;
}
