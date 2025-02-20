// 673380166-0
#include <stdio.h>
#include <string.h>

#define SIZE_TABLE 10

int getKey(char *t){
    int size = strlen(t);
    int total = 0;
    for(int i=0;i<size;i++){
        total+=t[i];
    }
    return total;
}

// QuadraticProbing

char quadraticProbingKeys[SIZE_TABLE][255];
int quadraticProbingValues[SIZE_TABLE];

void initializeQuadraticProbing(){
    for (int i = 0; i < SIZE_TABLE; i++){
        quadraticProbingKeys[i][0] = '\0';
        quadraticProbingValues[i] = 0;
    }
}

void insertQuadraticProbing(char *t, int value){
    int key = getKey(t);
    int index = key % SIZE_TABLE;
    int i = 0;

    while(quadraticProbingKeys[(index + i*i) % SIZE_TABLE][0] != '\0'){
        i++;
        if(i >= SIZE_TABLE){
            printf("Hash table is full (Quadratic Probing)\n");
            return;
        }
    }
// 673380166-0
    index = (index + i*i) % SIZE_TABLE;
    strcpy(quadraticProbingKeys[index], t);
    quadraticProbingValues[index] = value;
    printf("Quadratic Probing: Inserted key %s at index %d\n", t, index);
}

void displayQuadraticProbing(){
    printf("----Quadratic Probing----\n");
    for(int i=0;i<SIZE_TABLE;i++){
        printf("[%d] -> {%s: %d}\n", i, quadraticProbingKeys[i], quadraticProbingValues[i]);
    }
}

int searchHelperQuadraticProbing(char *t){
    int key = getKey(t);

    int index = key % SIZE_TABLE;
    int i = 0;

    while(quadraticProbingKeys[(index + i*i) % SIZE_TABLE][0] != '\0'){
        if(strcmp(quadraticProbingKeys[(index + i*i) % SIZE_TABLE], t) == 0){
            return (index + i*i) % SIZE_TABLE;
        }
        i++;
        if (i >= SIZE_TABLE){
            break;
        }
    }

    return -1;
}
// 673380166-0
void searchQuadraticProbing(char *t){
    int res = searchHelperQuadraticProbing(t);
    if(res == -1){
        printf("Key not found (Quadratic Probing)\n");
    }else{
        printf("{%s: %d} (Quadratic Probing)\n", quadraticProbingKeys[res], quadraticProbingValues[res]);
    }
}

void deleteQuadraticProbing(char *t){
    int index = searchHelperQuadraticProbing(t);
    if(index == -1){
        printf("Key not found (Quadratic Probing)\n");
    }else{
        quadraticProbingKeys[index][0] = '\0';
        quadraticProbingValues[index] = 0;
        printf("Delete %s success (Quadratic Probing)\n", t);
        displayQuadraticProbing();
    }
}

int main(){    
    printf("/-------------------------Quadratic Probing------------------------/\n");
    initializeQuadraticProbing();
    // 1. การเพิ่มข้อมูลและแสดงผล
    insertQuadraticProbing("Peter", 40);
    insertQuadraticProbing("Paul", 45);
    insertQuadraticProbing("Mary", 50);
    displayQuadraticProbing();

    // 2. การค้นหาและลบข้อมูล
    searchQuadraticProbing("Bank");
    searchQuadraticProbing("Paul");
    deleteQuadraticProbing("Peter");
    printf("################################################################################\n");
}