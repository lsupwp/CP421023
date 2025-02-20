// 673380166-0
#include <stdio.h>

#define MATRIX 10

int obj[MATRIX][MATRIX];
int numVertices;

void createGraph(int vertices) {
    numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            obj[i][j] = 0;
        }
    }
}

void addEdge(int src, int dest) {
    obj[src][dest] = 1;
    obj[dest][src] = 1;
}
// 673380166-0
void printGraph() {
    printf("Adjacency Matrix:\n");
    for (int i = -1; i < numVertices; i++) {
        if(i == -1){
            printf("  | ");
        }else{
            printf("%d | ", i);
        }
        for (int j = 0; j < numVertices; j++) {
            if(i == -1){
                printf("%d ", j);
                continue;
            }
            printf("%d ", obj[i][j]);
        }
        printf("\n");
    }
}
// 673380166-0
void delete(int key){
    if(numVertices == 0){
        printf("Error: Vertices is not defind!");
        return;
    }
    if(key > numVertices){
        printf("Error: Key error!");
        return;
    }
    int d=0;
    for(int i=0;i<numVertices;i++){
        for(int j=0;j<numVertices;j++){
            if(i == key || j == key){
                obj[i][j] = 0;
                d++;
            }
        }
    }
    if(d == 0){
        printf("%d is not found!", key);
    }else{
        printf("Delete %d success!", key);
    }
}
// 673380166-0
int main() {
    int vertices = 5;

    createGraph(vertices);

    addEdge(0,1);
    addEdge(0,2);
    addEdge(0,3);
    addEdge(1,2);
    addEdge(3,1);
    addEdge(3,2);

    printGraph();

    delete(3);
    printGraph();

    return 0;
}