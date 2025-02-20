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
// 673380166-0
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
// 673380166-0
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
}