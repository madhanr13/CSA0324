#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void DFS(int vertex, int n) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }
}

int main() {
    int n, edges, u, v, start;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    
    printf("DFS Traversal: ");
    DFS(start, n);
    printf("\n");
    
    return 0;
}
