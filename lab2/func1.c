#include <stdio.h>

void add(int a, int b){
    int sum = a+b;
    printf("The sum is: %d\n", sum);
}

int main(){
    int x = 5,y = 10;
    add(x,y);
    return 0;
}