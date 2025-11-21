//Printing BFS and DFS on graph
#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];  
int visited[MAX];
int queue[MAX], front = 0, rear = 0;
int stack[MAX], top = -1;
void BFS(int start, int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    front = rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS:\n ");

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}
void DFS(int start, int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    top = -1;
    stack[++top] = start;
    visited[start] = 1;

    printf("DFS: \n");

    while (top != -1) {
        int node = stack[top--];
        printf("%d ", node);
        for (int i = n - 1; i >= 0; i--) {
            if (graph[node][i] == 1 && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main() {
    int n, edges, u, v, start;

    printf("enter number of vertices: ");
    scanf("%d", &n);

    printf("enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;   
    }

    printf("enter starting node: ");
    scanf("%d", &start);

    BFS(start, n);
    DFS(start, n);

    return 0;
}
