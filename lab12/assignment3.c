#include <stdio.h>

const int RUN = 32;

int min(int a, int b)    
{    
    if(a<b)    
    return a;     
    else     
    return b;     
}

void insertionSort(int a[], int beg, int end) /* function to sort an array with insertion sort */  
{  
    int i, j, temp;  
    for (i = beg + 1; i <= end; i++) {  
        temp = a[i];  
        j = i - 1;  
  
        while(j>=0 && temp <= a[j])    
        {    
            a[j+1] = a[j];     
            j = j-1;    
        }    
        a[j+1] = temp;    
    }  
}

void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;        
    int LeftArray[n1], RightArray[n2]; //temporary arrays      
    /* copy data to temp arrays */  
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];       
    i = 0;   
    j = 0;  
    k = beg;       
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else            {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }       
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}  

void timSort(int a[], int n)  
{  
      
    /* Sort individual subarrays of size RUN */  
    for (int i = 0; i < n; i+=RUN)  
        insertionSort(a, i, min((i+RUN-1), (n-1)));   
    // Start merging from size RUN (or 32).  
    for (int size = RUN; size < n; size = 2*size)  
    {  
        for (int beg = 0; beg < n; beg += 2*size)  
        {  
            /* find ending point of left sub array. The starting point of right sub array is mid + 1 */  
            int mid = beg + size - 1;  
            int end = min((beg + 2*size - 1),(n-1));  
  
            /* Merge subarray a[beg...mid] and a[mid+1...end] */  
            if(mid < end)  
                merge(a, beg, mid, end);  
        }  
    }  
}  

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

    timSort(arr, n);
    
    printArray(arr, n);
    return 0;
}