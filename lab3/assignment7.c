#include <stdio.h>

int main(){
    int A[10] = {1,2,3,4,5};
    int n = 5;
    int pos;

    printf("Enter the position of the element to delete (1-based index): ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n){
        printf("Error: invalid position.\n");
        return 1;
    }

    for (int i=pos;i<n;i++){
        A[i-1] = A[i];
        for (int j = 0;j<10;j++){
            printf("%d ", A[j]);
        }
        printf("\n");
    }

    A[n-1] = 0;
    n = n-1;

    printf("Full array: ");
    for (int i=0;i<10;i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}