//Detecting whether graph is bi-connected or not
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int graph[MAX][MAX];
int visited[MAX], disc[MAX], low[MAX], parent[MAX];
int timecount = 0;
int articulationfound = 0;
void DFS(int u, int n) {
    visited[u] = 1;
    disc[u] = low[u] = ++timecount;

    int children = 0;

    for (int v = 0; v < n; v++) {
        if (graph[u][v]) {

            if (!visited[v]) {
                children++;
                parent[v] = u;
                DFS(v, n);
                low[u] = (low[u] < low[v]) ? low[u] : low[v];
                if (parent[u] == -1 && children > 1)
                    articulationfound = 1;

                if (parent[u] != -1 && low[v] >= disc[u])
                    articulationfound = 1;

            } else if (v != parent[u]) {
                low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
            }
        }
    }
}
int isconnected(int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    DFS(0, n);

    for (int i = 0; i < n; i++)
        if (!visited[i])
            return 0; 

    return 1;
}

int main() {
    int n, edges, u, v;

    printf("enter number of vertices: ");
    scanf("%d", &n);

    printf("enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("enter edges (u v): \n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        visited[i] = 0;
    }

    if (!isconnected(n))
        printf("graph is not biconnected (not connected)\n");
    else if (articulationfound)
        printf("graph is not biconnected (has articulation point)\n");
    else
        printf("graph is biconnected\n");

    return 0;
}
