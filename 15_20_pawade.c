//Program for topological sort.
#include <stdio.h>
#define MAX 20

int graph[MAX][MAX];
int indegree[MAX];
int queue[MAX], front = 0, rear = 0;

int main() {
    int n, edges, u, v;

    printf("enter number of vertices: ");
    scanf("%d", &n);

    printf("enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    printf("enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;      
        indegree[v]++;        
    }

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    printf("topological order: ");

    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    if (count != n)
        printf("\ngraph has a cycle\n topological sort not possible\n");

    return 0;
}
