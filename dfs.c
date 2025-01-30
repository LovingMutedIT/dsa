#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10  // Maximum number of nodes

int graph[MAX_NODES][MAX_NODES];  // Adjacency matrix
bool visited[MAX_NODES];          // Visited array
int numVertices;                  // Number of vertices

// DFS Recursive Function
void DFS(int vertex) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// Function to initialize the graph
void initializeGraph(int vertices) {
    numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;  // Initialize all edges as 0 (no connection)
        }
        visited[i] = false;  // Mark all nodes as unvisited
    }
}

// Function to add an edge
void addEdge(int src, int dest) {
    graph[src][dest] = 1;  // Add edge
    graph[dest][src] = 1;  // Since it's an undirected graph, add both directions
}

// Driver Code
int main() {
    int vertices = 6;
    initializeGraph(vertices);

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(4, 5);

    printf("DFS Traversal starting from vertex 0:\n");
    DFS(0);

    return 0;
}

