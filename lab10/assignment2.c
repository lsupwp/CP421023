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
// 673380166-0
void printGraph() {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}


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
}