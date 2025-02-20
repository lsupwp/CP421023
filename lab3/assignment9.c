// 673380166-0
#include <stdio.h>
#include <stdlib.h>

int checkLengthErr(int length, int pos){
    if(pos < 0 || pos > length-1){
        printf("Error: position out of range!\n");
        return 1;
    }
    else{
        return 0;
    }
}

void display(int* array, int length){
    printf("[ ");
    for(int i = 0;i<length;i++){
        if (i == length -1){
            printf("%d", array[i]);
        }else{
            printf("%d, ", array[i]);
        }
    }
    printf(" ]\n");
}

int insert(int* array, int length, int pos, int value){
    if(checkLengthErr(length, pos)){return 1;}
    if(array[length-1] != 0){
        printf("array is full.\n");
        return 1;
    }
    if(array[pos+1] == 0){
        array[pos] = value;
        return 0;
    }
    for (int i = length-2;i>=pos;i--){
        array[i+1] = array[i];
    }
    array[pos] = value;
}

int update(int* array, int length, int pos, int value){
    if(checkLengthErr(length, pos)){return 1;}
    array[pos] = value;
}

int delete(int* array, int length, int pos){
    if(checkLengthErr(length, pos)){return 1;}
    for (int i=pos;i<length;i++){
        array[i] = array[i+1];
    }
    array[length-1] = 0;
}

// 673380166-0
int main(){
    int array[10] = {0};
    int length = sizeof(array) / sizeof(int);
    while(1){
        printf("Menu:\n");
        printf("1. Display all element in the array\n");
        printf("2. Insert element into the array\n");
        printf("3. Update element in the array\n");
        printf("4. Delete element from the array\n");
        printf("0. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 0){
            break;
        }
        switch(choice){
            case 1:
                // display
                display(array, length);
                break;
            case 2:
                // insert
                int pos_insert;
                int val;
                printf("Enter you position you want to insert (start with 0): ");
                scanf("%d", &pos_insert);
                printf("Enter your value you want to insert: ");
                scanf("%d", &val);
                insert(array, length, pos_insert, val);
                break;
            case 3:
                // update
                int pos_update;
                int val_update;
                printf("Enter you position you want to update (start with 0): ");
                scanf("%d", &pos_update);
                printf("Enter your value you want to update: ");
                scanf("%d", &val_update);
                update(array, length, pos_update, val_update);
                break;
            case 4:
                // delete
                int pos_delete;
                printf("Enter you position you want to delete (start with 0): ");
                scanf("%d", &pos_delete);
                delete(array, length, pos_delete);
                break;
            default:
                printf("Invalid in put!");
        }

    }
    return 0;
}