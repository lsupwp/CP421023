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

// LinearProbing

char linearProbingKeys[SIZE_TABLE][255];
int linearProbingValues[SIZE_TABLE];

void initializeLinearProbing()
{
    for (int i = 0; i < SIZE_TABLE; i++){
        linearProbingKeys[i][0] = '\0';
        linearProbingValues[i] = 0;
    }
}

void insertLinearProbing(char *t,int value){
    int key = getKey(t);
    int index = key % SIZE_TABLE;
    int startIndex = index;

    while(linearProbingKeys[index][0] != '\0'){
        index = (index + 1) % SIZE_TABLE;
        if (index == startIndex) {
            printf("Hash table is full (Linear Probing)\n");
            return;
        }
    }

    strcpy(linearProbingKeys[index], t);
    linearProbingValues[index] = value;
    printf("Linear Probing: Inserted key %s at index %d\n", t, index);
}

void displayLinearProbing(){
    printf("----Linear Probing----\n");
    for(int i=0;i<SIZE_TABLE;i++){
        printf("[%d] -> {%s: %d}\n", i, linearProbingKeys[i], linearProbingValues[i]);
    }
}

int searchHelperLinearProbing(char *t){
    int key = getKey(t);

    int index = key % SIZE_TABLE;
    int startIndex = index;
    while(linearProbingKeys[index][0] != '\0'){
        if(strcmp(linearProbingKeys[index], t) == 0){
            return index;
        }
        index = (index + 1) % SIZE_TABLE;
        if(index == startIndex){
            break;
        }
    }
    return -1;
}

void searchLinearProbing(char *t){
    int res = searchHelperLinearProbing(t);
    if(res == -1){
        printf("Key not found (Linear Probing)\n");
    }else{
        printf("{%s: %d} (Linear Probing)\n", linearProbingKeys[res], linearProbingValues[res]);
    }
}

void deleteLinearProbing(char *t){
    int index = searchHelperLinearProbing(t);
    if(index == -1){
        printf("Key not found (Linear Probing)\n");
    }else{
        linearProbingKeys[index][0] = '\0';
        linearProbingValues[index] = 0;
        printf("Delete %s success (Linear Probing)\n", t);
        displayLinearProbing();
    }
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
            return index;
        }
        i++;
        if (i >= SIZE_TABLE){
            break;
        }
    }

    return -1;
}

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

// DoubleHashing

char doubleHashingKeys[SIZE_TABLE][255];
int doubleHashingValues[SIZE_TABLE];

void initializeDoubleHashing(){
    for (int i = 0; i < SIZE_TABLE; i++){
        doubleHashingKeys[i][0] = '\0';
        doubleHashingValues[i] = 0;
    }
}

int secondHash(int key){
    return 7 - (key % 7);
}

void insertDoubleHashing(char *t, int value){
    int key = getKey(t);

    int index = key % SIZE_TABLE;
    int step = secondHash(key);
    while(doubleHashingKeys[index][0] != '\0'){
        index = (index + step) % SIZE_TABLE;
    }

    strcpy(doubleHashingKeys[index], t);
    doubleHashingValues[index] = value;
    printf("Double Hashing: Inserted key %s at index %d\n", t, index);
}

void displayDoubleHashing(){
    printf("----Double Hashing----\n");
    for(int i=0;i<SIZE_TABLE;i++){
        printf("[%d] -> {%s: %d}\n", i, doubleHashingKeys[i], doubleHashingValues[i]);
    }
}

int searchHelperDoubleHashing(char *t){
    int key = getKey(t);

    int index = key % SIZE_TABLE;
    int step = secondHash(key);

    while(doubleHashingKeys[index][0] != '\0'){
        if(strcmp(doubleHashingKeys[index], t) == 0){
            return index;
        }
        index = (index + step) % SIZE_TABLE;
    }
    return -1;
}

void searchDoubleHashing(char *t){
    int index = searchHelperDoubleHashing(t);
    if(index == -1){
        printf("Key not found (Double Hashing)\n");
    }else{
        printf("{%s: %d} (Double Hashing)\n", doubleHashingKeys[index], doubleHashingValues[index]);
    }
}

void deleteDoubleHashing(char *t){
    int index = searchHelperDoubleHashing(t);
    if(index == -1){
        printf("Key not found (Double Hashing)\n");
    }else{
        doubleHashingKeys[index][0] = '\0';
        doubleHashingValues[index] = 0;
        printf("Delete %s success! (Double Hashing)\n", t);
        displayDoubleHashing();
    }
}

int main(){
    printf("/-------------------------Linear Probing------------------------/\n");
    initializeLinearProbing();
    // 1. การเพิ่มข้อมูลและแสดงผล
    insertLinearProbing("Peter", 40);
    insertLinearProbing("Paul", 45);
    insertLinearProbing("Mary", 50);
    displayLinearProbing();

    // 2. การค้นหาและลบข้อมูล
    searchLinearProbing("Bank");
    searchLinearProbing("Paul");
    deleteLinearProbing("Peter");
    printf("################################################################################\n");
    
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

    printf("/-------------------------Double Hashing------------------------/\n");
    initializeDoubleHashing();
    // 1. การเพิ่มข้อมูลและแสดงผล
    insertDoubleHashing("Peter", 40);
    insertDoubleHashing("Paul", 45);
    insertDoubleHashing("Mary", 50);
    displayDoubleHashing();

    // 2. การค้นหาและลบข้อมูล
    searchDoubleHashing("Bank");
    searchDoubleHashing("Paul");
    deleteDoubleHashing("Peter");
    printf("################################################################################\n");
}