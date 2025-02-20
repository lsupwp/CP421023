// 673380166-0
#include <stdio.h>
#include <limits.h>

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

void addEdge(int from, int to, int w) {
    obj[from][to] = w;
    obj[to][from] = w;
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
void setDefault(int *arr){
    for(int i=0;i<numVertices;i++){
        arr[i] = INT_MIN;
    }
}

int inArray(int *arr, int key){
    for(int i=0;i<numVertices;i++){
        if(key == arr[i]){
            return 1;
        }
    }
    return 0;
}

void append(int *arr, int n, int key){
    arr[++n] = key;
}
// 673380166-0
int sumEdge() {
    int sum = 0;
    int min;
    int arr[MATRIX] = {INT_MIN};
    int n=-1;
    int l = -1;
    setDefault(arr);
    for (int i = 0; i < numVertices; i++) {
        min = INT_MAX;
        for (int j = 0; j < numVertices; j++) {
            if (obj[i][j] > 0 && obj[i][j] < min) {
                if(!inArray(arr, j)){
                    min = obj[i][j];
                    l = j;
                }
            }
        }
        if (min == INT_MAX) min = 0;
        if(l != -1) append(arr, n, l);
        sum += min;
    }
    return sum;
}
// 673380166-0
int main() {
    int vertices = 5;

    createGraph(vertices);

    addEdge(0,1,5);
    addEdge(0,2,10);
    addEdge(0,3,7);
    addEdge(1,2,4);
    addEdge(3,1,2);
    addEdge(3,2,8);

    printGraph();

    printf("Lower length adge : %d\n", sumEdge());

    return 0;
}