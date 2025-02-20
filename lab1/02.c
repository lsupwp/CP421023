#include <stdio.h>

int main(){
    int myInt = 10;
    float myFloat = 3.14;
    char myChar = 'A';

    printf("Enter a new integer: ");
    scanf("%d", &myInt);

    printf("Enter a new character: ");
    scanf(" %c", &myChar);

    printf("New Integer: %d\n", myInt);
    printf("New Character: %c\n", myChar);

    return 0;
}