#include "graph.h"

int minDist(int dist[], int visited[]) {
    int min = INF, idx = -1;
    for (int i = 0; i < V; i++)
        if (!visited[i] && dist[i] <= min)
            min = dist[i], idx = i;
    return idx;
}

void dijkstra(int graph[V][V], int src, int dist[]) {
    int visited[V] = {0};

    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = minDist(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
}
