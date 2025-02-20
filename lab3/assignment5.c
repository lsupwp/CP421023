#include <stdio.h>

int main(){
    int A[5];
    int n = 0;
    int N = 5;
    int x;

    while(1){
        printf("Enter an element to append: ");
        scanf("%d", &x);
        if (n == N){
            printf("Error: Array is full.\n");
        }else{
            A[n] = x;
            n+=1;

            printf("Array after appending: ");
            for (int i = 0;i<n;i++){
                printf("%d ", A[i]);
            }
        printf("\n");
        }
    }

    return 0;
}