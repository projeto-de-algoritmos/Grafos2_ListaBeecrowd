#include <string.h>
#include <stdio.h>

typedef int Vertices;

struct Graph {
    int v;
    int a;
    int route[501][501];
};

struct Graph graph;

void dijkstra(int source, int destination) {
    int w, w0;
    int fr[501], parent[501];
    int cost[501];

    memset(parent, -1, sizeof(parent));
    memset(cost, 999999, sizeof(cost));

    fr[source] = source;
    cost[source] = 0;

    while (1) {
        int minCost = 999999;
        for (w = 0; w < graph.v; w++) {
            if (parent[w] == -1 && minCost > cost[w]) {
                minCost = cost[w0 = w];
            }
        }
        if (minCost == 999999)
            break;
        parent[w0] = fr[w0];

        for (w = 0; w < graph.v; w++) {
            if (cost[w] > cost[w0] + graph.route[w0][w]) {
                cost[w] = cost[w0] + graph.route[w0][w];
                fr[w] = w0;
            }
        }
    }

    if (cost[destination] < 999999)
        printf("%d\n", cost[destination]);
    else
        printf("Nao e possivel entregar a carta\n");
}

int main() {
    memset(&graph, 0, sizeof(graph));
    Vertices n, e, k, o, d;
    int x, y, z;
    int i, j;

    while (1) {
        scanf("%d %d", &n, &e);
        if (n == 0 && e == 0)
            break;
        for (i = 0; i <= n; i++)
            for (j = 0; j <= n; j++)
                graph.route[i][j] = 999999;
        for (i = 0; i < e; ++i) {
            scanf("%d %d %d", &x, &y, &z);
            if (graph.route[y][x] != 999999) {
                graph.route[x][y] = 0;
                graph.route[y][x] = 0;
            } else {
                graph.route[x][y] = z;
            }
        }
        graph.v = n + 1;
        graph.a = e;
        scanf("%d", &k);
        for (i = 0; i < k; ++i) {
            scanf("%d %d", &o, &d);
            dijkstra(o, d);
        }
        printf("\n");
    }
    return 0;
}
