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
// 673380166-0
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
// 673380166-0
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