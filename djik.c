#include <stdio.h>
#include <stdbool.h>

#define V 5         
#define INF 99999   

int minDistance(int dist[], bool visited[]) {
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}


void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}


void dijkstra(int graph[V][V], int src) {
    int dist[V];      
    bool visited[V];  

   
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0; 

    
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited); 
        visited[u] = true;

        
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}


int main() {
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int source = 0;
    printf("Dijkstra's Algorithm from Source Vertex %d:\n", source);
    dijkstra(graph, source);

    return 0;
}

