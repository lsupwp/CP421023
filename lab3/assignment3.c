#include <stdio.h>

int main(){
    int number[] = {1,2,3,4,5};
    for (int i = 0;i<5;i++){
        printf("Element %d: Value = %d, Address = %p\n", i, number[i], &number[i]);
    }

    return 0;
}