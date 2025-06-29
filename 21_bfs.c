#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

void BFS(int startVertex, int n) {
    visited[startVertex] = 1;
    enqueue(startVertex);
    
    printf("BFS Traversal: ");
    
    while (!isEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);
        
        for (int i = 0; i < n; i++) {
            if (adj[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
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
    
    BFS(start, n);
    
    return 0;
}
