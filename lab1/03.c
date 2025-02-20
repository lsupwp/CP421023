#include <stdio.h>

int main(){
    int a = 10, b = 5;
    float x = 4.5, y = 2.5;

    int sum = a+b;
    int difference = a-b;
    float floatSum = x+y;
    float floatDifference = x-y;

    printf("Integer Sum: %d\n", sum);
    printf("Integer Difference: %d\n", difference);
    printf("Float Sum: %.2f\n", floatSum);
    printf("Float Difference: %.2f\n", floatDifference);

    return 0;
}