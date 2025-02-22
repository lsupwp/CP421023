// 673380166-0
#include <stdio.h>
#include <stdlib.h>

void countSort(int arr[], int N) {
  
    int M = 0;
    for (int i = 0; i < N; i++)
        if (arr[i] > M)
            M = arr[i];
    
    int* countArray = (int*)calloc(M + 1, sizeof(int));
    
    for (int i = 0; i < N; i++)
        countArray[arr[i]]++;
    
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];
    
    int* outputArray = (int*)malloc(N * sizeof(int));
    for (int i = N - 1; i >= 0; i--) {
        outputArray[countArray[arr[i]] - 1] = arr[i];
        countArray[arr[i]]--;
    }
    
    for (int i = 0; i < N; i++)
        arr[i] = outputArray[i];

    free(countArray);
    free(outputArray);
}
// 673380166-0
void printArray(int arr[], int size) {
    printf("[");
    for(int i=0;i<size;i++){
        if(i==size-1){
            printf("%d",arr[i]);
        }else{
            printf("%d, ",arr[i]);
        }
    }
    printf("]\n");
}

int main() {
    int arr[] = {9,7,8,5,6,3,4,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printArray(arr, n);

    countSort(arr, n);
    
    printArray(arr, n);
    return 0;
}
