#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10
#define INF INT_MAX

/* ---------- Function to find the vertex with minimum distance ---------- */
int minDistance(int dist[], int visited[], int n) {
    int min = INF, minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

/* ---------- Dijkstra's Algorithm ---------- */
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int source) {
    int dist[MAX_VERTICES];   // Distance from source to each vertex
    int visited[MAX_VERTICES]; // Visited vertices

    // Initialize distances and visited array
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0; // Distance from source to itself is 0

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n); // Pick the minimum distance vertex
        if (u == -1) break; // All remaining vertices are unreachable

        visited[u] = 1; // Mark as visited

        // Update distances of neighbors of u
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the results
    printf("Vertex\tDistance from Source (%d)\n", source);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d\t\tINF\n", i);
        else
            printf("%d\t\t%d\n", i, dist[i]);
    }
}

/* ---------- Main Function ---------- */
int main() {
    int n = 5; // Number of vertices
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int source = 0; // Source vertex

    printf("Weighted Graph (Adjacency Matrix):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    printf("\nDijkstra's Algorithm Result:\n");
    dijkstra(graph, n, source);

    return 0;
}