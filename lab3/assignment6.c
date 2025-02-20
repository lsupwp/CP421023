#include <stdio.h>

int main(){
    int A[5] = {1,2,3};
    int n = 3;
    int N = 5;
    int x, pos;
    printf("Enter the element to insert: ");
    scanf("%d", &x);
    printf("Enter the position to insert at (1-based index): ");
    scanf("%d", &pos);

    if(n == N){
        printf("Error: Array is full.\n");
        return 1;
    }
    for (int i = n;i>=pos-1;i--){
        A[i+1] = A[i];
        for (int j = 0;j<N;j++){
            printf("%d ", A[j]);
        }
        printf("\n");
    }

    A[pos-1] = x;
    n = n+1;
    printf("Array after insertion: ");
    for (int i = 0;i<n;i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}