// 673380166-0
#include <stdio.h>

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
// 673380166-0
void radixSort(int arr[], int n)
{

    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void printArray(int arr[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            printf("%d", arr[i]);
        }
        else
        {
            printf("%d, ", arr[i]);
        }
    }
    printf("]\n");
}
// 673380166-0
int main()
{
    int arr[] = {9, 7, 8, 5, 6, 3, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);

    radixSort(arr, n);

    printArray(arr, n);
    return 0;
}
