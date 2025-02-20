// 673380166-0
#include <stdio.h>
#include <string.h>

#define SIZE_TABLE 10
#define MAX_CHAIN 5
#define SIZE 2
int res[2] = {-1, -1};

int getKey(char *t){
    int size = strlen(t);
    int total = 0;
    for(int i=0;i<size;i++){
        total+=t[i];
    }
    return total;
}

// Chaining

char chainingKey[SIZE_TABLE][MAX_CHAIN][255];
int chainingValues[SIZE_TABLE][MAX_CHAIN];

void initializeChaining(){
    for(int i=0;i<SIZE_TABLE;i++){
        for(int j=0;j<MAX_CHAIN;j++){
            chainingKey[i][j][0] = '\0';
            chainingValues[i][j] = -1;
        }
    }
}

void displayChaining(){
    printf("----Chaining----\n");
    for(int i=0;i<SIZE_TABLE;i++){
        printf("[%d]: ", i);
        for(int j=0;j<MAX_CHAIN;j++){
            if(chainingValues[i][j] != -1){
                printf("{%s: %d} ->",chainingKey[i][j], chainingValues[i][j]);
            }
        }
// 673380166-0
        printf("NULL\n");
    }
}

void insertChaining(char *t, int value){
    int key = getKey(t);
    int index = key % SIZE_TABLE;
    for(int i=0;i<MAX_CHAIN;i++){
        if(chainingKey[index][i][0] == '\0'){
            strcpy(chainingKey[index][i], t);
            chainingValues[index][i] = value;
            printf("Separate Chaining: Inserted key %s at index %d, chain %d\n", chainingKey[index][i], index, i);
            return;
        }
    }

    printf("No space in chain for key %s\n", t);
}

void searchHelperChaining(char *t){
    res[0] = -1;
    res[1] = -1;
    int key = getKey(t);

    int index = key % SIZE_TABLE;
    for(int i=0;i<MAX_CHAIN;i++){
        if(strcmp(chainingKey[index][i], t) == 0){
            res[0] = index;
            res[1] = i;
            break;
        }
    }
}
// 673380166-0
void searchChaining(char *t){
    searchHelperChaining(t);
    if(res[0] == -1){
        printf("Key not found (Chaining)\n");
    }else{
        printf("{ %s: %d } (Chaining)\n", chainingKey[res[0]][res[1]], chainingValues[res[0]][res[1]]);
    }
    res[0] = -1;
    res[1] = -1;
}

void deleteChaining(char *t){
    searchHelperChaining(t);
    if(res[0] == -1){
        printf("Key not found (Chaining)\n");
    }else{
        for(int i=res[1];i<MAX_CHAIN;i++){
            strcpy(chainingKey[res[0]][i], chainingKey[res[0]][i+1]);
            chainingValues[res[0]][i] = chainingValues[res[0]][i+1];

        }
        chainingKey[res[0]][MAX_CHAIN][0] = '\0';
        chainingValues[res[0]][MAX_CHAIN] = -1;

        printf("Delete %s success (Chaining)\n", t);
        displayChaining();
    }
    res[0] = -1;
    res[1] = -1;
}
// 673380166-0
int main(){
    printf("/-------------------------Double Hashing------------------------/\n");
    initializeChaining();
    // 1. การเพิ่มข้อมูลและแสดงผล
    insertChaining("Peter", 40);
    insertChaining("Paul", 45);
    insertChaining("Mary", 50);
    displayChaining();

    // 2. การค้นหาและลบข้อมูล
    searchChaining("Bank");
    searchChaining("Paul");
    deleteChaining("Peter");
    printf("################################################################################\n");
}