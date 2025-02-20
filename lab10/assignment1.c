// 673380166-0
#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int numVertices;

void createGraph(int vertices) {
    numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int src, int dest, int weight) {
    adjMatrix[src][dest] = weight;
    adjMatrix[dest][src] = weight;
}

void printGraph() {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}
// 673380166-0
int findMinDistance(int distance[], int visited[]) {
    int min = INT_MAX, minIndex;

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i] && distance[i] < min) {
            min = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int startVertex) {
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};
    int total = 0;

    for (int i = 0; i < numVertices; i++) {
        distance[i] = INT_MAX;
    }
    distance[startVertex] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = findMinDistance(distance, visited);
        visited[u] = 1;
// 673380166-0
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && adjMatrix[u][v] && distance[u] != INT_MAX && distance[u] + adjMatrix[u][v] < distance[v]) {
                distance[v] = distance[u] + adjMatrix[u][v];
                if(distance[u] != 0){
                    total += adjMatrix[u][v];
                }
                // printf("%d : %d\n", distance[u], adjMatrix[u][v]);
            }
        }
        total+=distance[u];
        // printf("%d\n", distance[u]);
    }

    // printf("Vertex\tDistance from Source\n");
    // for (int i = 0; i < numVertices; i++) {
    //     printf("%d\t%d\n", i, distance[i]);
    // }
    printf("Minimum total edge: %d\n", total);
}
// 673380166-0
int main(){
    int vertices = 4;

    createGraph(vertices);
    addEdge(0, 1, 5);
    addEdge(0, 2, 10);
    addEdge(0, 3, 7);
    addEdge(1, 2, 4);
    addEdge(3, 1, 2);
    addEdge(3, 2, 8);

    printGraph();

    dijkstra(0);
}